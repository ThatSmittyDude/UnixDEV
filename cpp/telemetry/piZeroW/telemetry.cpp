#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <cstdint>
#include <sys/syscall.h>
#include <ctime>
#include <sys/time.h>

#define AHT10_I2C_ADDR 0x38  // AHT10 I2C address
#define BMP180_I2C_ADDR 0x77 // BMP180 I2C address
#define I2C_BUS "/dev/i2c-1"  // I2C bus

// AHT10 Data Structure
float temperatureAHT10, humidityAHT10;

// BMP180 Calibration Data
struct CalibrationData {
    int16_t AC1, AC2, AC3, B1, B2, MB, MC, MD;
    uint16_t AC4, AC5, AC6;
};

// AHT10 functions
void readAHT10(int fd, float &temperature, float &humidity) {
    uint8_t cmd[3] = {0xAC, 0x33, 0x00};  
    write(fd, cmd, 3);  
    usleep(80000);  
    uint8_t data[6] = {0};  
    read(fd, data, 6);
    if (data[0] & 0x80) {  
        std::cerr << "Sensor not ready\n";
        return;
    }
    uint32_t raw_humidity = ((data[1] << 16) | (data[2] << 8) | data[3]) >> 4;
    uint32_t raw_temperature = ((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5];
    humidity = (raw_humidity * 100.0) / 1048576.0;
    temperature = ((raw_temperature * 200.0) / 1048576.0) - 50;
}

// BMP180 functions
int openI2CBus() {
    int fd = open(I2C_BUS, O_RDWR);
    if (fd < 0) {
        std::cerr << "Error: Could not open I2C bus!\n";
        return -1;
    }
    return fd;
}

bool setI2CDevice(int fd, int addr) {
    if (ioctl(fd, I2C_SLAVE, addr) < 0) {
        std::cerr << "Error: Could not communicate with device at address 0x" 
                  << std::hex << addr << std::dec << "\n";
        return false;
    }
    return true;
}

bool readRegister(int fd, uint8_t reg, uint8_t *buffer, size_t length) {
    if (write(fd, &reg, 1) != 1) {
        std::cerr << "Error: Failed to write register address\n";
        return false;
    }
    if (read(fd, buffer, length) != (ssize_t)length) {
        std::cerr << "Error: Failed to read data\n";
        return false;
    }
    return true;
}

bool writeRegister(int fd, uint8_t reg, uint8_t value) {
    uint8_t buffer[2] = {reg, value};
    return write(fd, buffer, 2) == 2;
}

void readCalibrationData(int fd, CalibrationData &calib) {
    uint8_t calibData[22];
    readRegister(fd, 0xAA, calibData, 22);
    calib.AC1 = (calibData[0] << 8) | calibData[1];
    calib.AC2 = (calibData[2] << 8) | calibData[3];
    calib.AC3 = (calibData[4] << 8) | calibData[5];
    calib.AC4 = (calibData[6] << 8) | calibData[7];
    calib.AC5 = (calibData[8] << 8) | calibData[9];
    calib.AC6 = (calibData[10] << 8) | calibData[11];
    calib.B1  = (calibData[12] << 8) | calibData[13];
    calib.B2  = (calibData[14] << 8) | calibData[15];
    calib.MB  = (calibData[16] << 8) | calibData[17];
    calib.MC  = (calibData[18] << 8) | calibData[19];
    calib.MD  = (calibData[20] << 8) | calibData[21];
}

int16_t readRawTemperature(int fd) {
    if (!writeRegister(fd, 0xF4, 0x2E)) return -1;
    usleep(5000);
    uint8_t data[2];
    if (!readRegister(fd, 0xF6, data, 2)) return -1;
    return (data[0] << 8) | data[1];
}

float calculateTemperature(int16_t rawTemp, CalibrationData &calib, int32_t &B5) {
    int32_t X1 = (rawTemp - calib.AC6) * calib.AC5 / 32768;
    int32_t X2 = (calib.MC * 2048) / (X1 + calib.MD);
    B5 = X1 + X2;
    return (B5 + 8) / 16.0 / 10.0;
}

int32_t readRawPressure(int fd) {
    uint8_t command = 0x34 + (3 << 6); // Using oversampling setting 3
    if (!writeRegister(fd, 0xF4, command)) return -1;
    usleep(25000);
    uint8_t data[3];
    if (!readRegister(fd, 0xF6, data, 3)) return -1;
    return ((data[0] << 16) | (data[1] << 8) | data[2]) >> (8 - 3);
}

float calculatePressure(int32_t rawPressure, int32_t B5, CalibrationData &calib) {
    int32_t B6 = B5 - 4000;
    int32_t X1 = (calib.B2 * (B6 * B6 / 4096)) / 2048;
    int32_t X2 = (calib.AC2 * B6) / 2048;
    int32_t X3 = X1 + X2;
    int32_t B3 = (((calib.AC1 * 4 + X3) << 3) + 2) / 4;
    X1 = (calib.AC3 * B6) / 8192;
    X2 = (calib.B1 * (B6 * B6 / 4096)) / 65536;
    X3 = ((X1 + X2) + 2) / 4;
    uint32_t B4 = (calib.AC4 * (uint32_t)(X3 + 32768)) / 32768;
    uint32_t B7 = ((uint32_t)rawPressure - B3) * (50000 >> 3);
    int32_t P = (B7 < 0x80000000) ? (B7 * 2) / B4 : (B7 / B4) * 2;
    X1 = (P / 256) * (P / 256);
    X1 = (X1 * 3038) / 65536;
    X2 = (-7357 * P) / 65536;
    P = P + (X1 + X2 + 3791) / 16;
    return P / 100.0;
}

// File writing functions
void write_temperature(float temperature) {
    const char* filename = "temperature.tsv";
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1){
        std::cerr << "Error opening file\n";
        return;
    }
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    struct tm *local_time = localtime(&tv.tv_sec);
    char buffer[64];
    int len = snprintf(buffer, sizeof(buffer), "%.2f	C	%04d-%02d-%02d	%02d:%02d:%02d.%01ld\n",
                       temperature, local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
                       local_time->tm_hour, local_time->tm_min, local_time->tm_sec, tv.tv_usec / 100000);
    write(fd, buffer, len);
    close(fd);
}

void write_humidity(float humidity) {
    const char* filename = "humidity.tsv";
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1){
        std::cerr << "Error opening file\n";
        return;
    }
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    struct tm *local_time = localtime(&tv.tv_sec);
    char buffer[64];
    int len = snprintf(buffer, sizeof(buffer), "%.2f	RH	%04d-%02d-%02d	%02d:%02d:%02d.%01ld\n",
                       humidity, local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
                       local_time->tm_hour, local_time->tm_min, local_time->tm_sec, tv.tv_usec / 100000);
    write(fd, buffer, len);
    close(fd);
}

void write_pressure(float pressure) {
    const char* filename = "pressure.tsv";
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        std::cerr << "Error opening file\n";
        return;
    }

    struct timeval tv;
    gettimeofday(&tv, nullptr);
    struct tm *local_time = localtime(&tv.tv_sec);

    char buffer[64];
    int len = snprintf(buffer, sizeof(buffer), "%.2f    hPa    %04d-%02d-%02d  %02d:%02d:%02d.%01ld\n",
                       pressure, local_time->tm_year + 1900, local_time->tm_mon + 1, local_time->tm_mday,
                       local_time->tm_hour, local_time->tm_min, local_time->tm_sec, tv.tv_usec / 100000);

    write(fd, buffer, len);
    close(fd);
}


int main() {
    const char *i2c_dev = "/dev/i2c-1";  
    int fd = open(i2c_dev, O_RDWR);  
    if (fd < 0) {
        std::cerr << "Error opening I2C device\n";
        return 1;
    }

    // Set AHT10
    if(ioctl(fd, I2C_SLAVE, AHT10_I2C_ADDR) < 0){
        std::cerr << "Failed to acquire bus access for AHT10\n";
        close(fd);
        return 1;
    }

    // Set BMP180
    int bmp_fd = openI2CBus();
    if (bmp_fd < 0) return -1;
    if (!setI2CDevice(bmp_fd, BMP180_I2C_ADDR)) {
        close(bmp_fd);
        return -1;
    }

    CalibrationData calib;
    readCalibrationData(bmp_fd, calib);

    try {
        while(true) {
            // Read and process AHT10 data
            readAHT10(fd, temperatureAHT10, humidityAHT10);
            write_temperature(temperatureAHT10);
            write_humidity(humidityAHT10);
		std::cout << "\n---- ---- ---- ----\n";
		std::cout << "AHT10\n";
		std::cout << "____\n";
		std::cout << "AHT10 Temperature: " << temperatureAHT10 << " °C\n";
		std::cout << "AHT10 Humidity: " << humidityAHT10 << " %\n";

            // Read and process BMP180 data
            int32_t B5;
            int16_t rawTemp = readRawTemperature(bmp_fd);
            int32_t rawPressure = readRawPressure(bmp_fd);

            if (rawTemp != -1 && rawPressure != -1) {
                float temperatureBMP = calculateTemperature(rawTemp, calib, B5);
                float pressureBMP = calculatePressure(rawPressure, B5, calib);
               std::cout << "\n==== ==== ==== ====\n";
		std::cout << "BMP180\n";
		std::cout << "____\n";
		 std::cout << "BMP180 Temperature: " << temperatureBMP << " °C\n";
                std::cout << "BMP180 Pressure: " << pressureBMP << " hPa\n";
            	write_pressure(pressureBMP);
		}


            std::cout << "---- ---- ---- ----\n\n";
            sleep(1);
        }
    } catch (...) {
        std::cerr << "Exiting...\n";
    }

    close(fd);
    close(bmp_fd);
    return 0;
}

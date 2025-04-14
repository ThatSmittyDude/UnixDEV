#include <iostream>
#include <unistd.h>
#include <cstdint>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define BMP180_I2C_ADDR 0x77
#define I2C_BUS "/dev/i2c-1"
#define OSS 3  // Oversampling setting (0 to 3)

struct CalibrationData {
    int16_t AC1, AC2, AC3, B1, B2, MB, MC, MD;
    uint16_t AC4, AC5, AC6;
};

int openI2CBus() {
    int fd = open(I2C_BUS, O_RDWR);
    if (fd < 0) {
        std::cerr << "Error: Could not open I2C bus!" << std::endl;
        return -1;
    }
    return fd;
}

bool setI2CDevice(int fd, int addr) {
    if (ioctl(fd, I2C_SLAVE, addr) < 0) {
        std::cerr << "Error: Could not communicate with device at address 0x" 
                  << std::hex << addr << std::dec << std::endl;
        return false;
    }
    return true;
}

bool readRegister(int fd, uint8_t reg, uint8_t *buffer, size_t length) {
    if (write(fd, &reg, 1) != 1) {
        std::cerr << "Error: Failed to write register address" << std::endl;
        return false;
    }
    if (read(fd, buffer, length) != (ssize_t)length) {
        std::cerr << "Error: Failed to read data" << std::endl;
        return false;
    }
    return true;
}

bool writeRegister(int fd, uint8_t reg, uint8_t value) {
    uint8_t buffer[2] = {reg, value};
    if (write(fd, buffer, 2) != 2) {
        std::cerr << "Error: Failed to write command" << std::endl;
        return false;
    }
    return true;
}

void readCalibrationData(int fd, CalibrationData &calib) {
    uint8_t calibData[22];
    if (!readRegister(fd, 0xAA, calibData, 22)) {
        std::cerr << "Error: Failed to read calibration data" << std::endl;
        return;
    }

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

float calculatePressure(int32_t rawPressure, int32_t B5, CalibrationData &calib) {
    int32_t B6 = B5 - 4000;
    int32_t X1 = (calib.B2 * (B6 * B6 / 4096)) / 2048;
    int32_t X2 = (calib.AC2 * B6) / 2048;
    int32_t X3 = X1 + X2;
    int32_t B3 = (((calib.AC1 * 4 + X3) << OSS) + 2) / 4;
    X1 = (calib.AC3 * B6) / 8192;
    X2 = (calib.B1 * (B6 * B6 / 4096)) / 65536;
    X3 = ((X1 + X2) + 2) / 4;
    uint32_t B4 = (calib.AC4 * (uint32_t)(X3 + 32768)) / 32768;
    uint32_t B7 = ((uint32_t)rawPressure - B3) * (50000 >> OSS);

    int32_t P = (B7 < 0x80000000) ? (B7 * 2) / B4 : (B7 / B4) * 2;
    X1 = (P / 256) * (P / 256);
    X1 = (X1 * 3038) / 65536;
    X2 = (-7357 * P) / 65536;
    P = P + (X1 + X2 + 3791) / 16;

    return P / 100.0;  // Convert to hPa
}

int main() {
    int fd = openI2CBus();
    if (fd < 0) return -1;

    if (!setI2CDevice(fd, BMP180_I2C_ADDR)) {
        close(fd);
        return -1;
    }

    CalibrationData calib;
    readCalibrationData(fd, calib);

    int16_t rawTemp = readRawTemperature(fd);
    int32_t rawPressure = readRawPressure(fd);

    if (rawTemp == -1 || rawPressure == -1) {
        std::cerr << "Error: Failed to read sensor data" << std::endl;
    } else {
        float temperature = calculateTemperature(rawTemp, calib.AC5, calib.AC6, calib.MC, calib.MD);
        float pressure = calculatePressure(rawPressure, temperature, calib);
        std::cout << "Temperature: " << temperature << " °C" << std::endl;
        std::cout << "Pressure: " << pressure << " hPa" << std::endl;
    }

    close(fd);
    return 0;
}

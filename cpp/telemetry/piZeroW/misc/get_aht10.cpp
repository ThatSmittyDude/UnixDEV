#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <cstring>
#include <cstdint>

#define AHT10_I2C_ADDR 0x38											// Sets I2C slave address to 0x38

//Byte Index:   0        1        2        3        4        5
//Data:      [Status] [ Humidity Data (20 bits) ] [ Temperature Data (20 bits) ]
//Bits:       8      |  8       8       4  |  4       8       8



void readAHT10(int fd, float &temperature, float &humidity){
	uint8_t cmd[3] = {0xAC, 0x33, 0x00};									// Command array holds commands to be sent to the AHT
	write(fd, cmd, 3);											// [3] == 3 Bytes
	usleep(80000);	// Wait at least 75ms for measurement							// 0xAC > Trigger measurement
	//													// 0x33 > Fixed sequence value
	uint8_t data[6] = {0};											// 0x00 > Reserved byte, must be zero
	read(fd, data, 6);
	//													// Data array stores 6 bytes of raw data
	if(data[0] & 0x80){											// data[0] == Status byte, bit 7 determines if sensor is busy
		std::cerr << "	****Sensor not ready****" << std::endl;						// data[1], data[2], data[3] == raw humidity == 20Bits
		return;												// data[4], data[5], data[6] == raw temperature == 20Bits
	}

	uint32_t raw_humidity = ((data[1] << 16) | (data[2] << 8) | data[3]) >> 4;
	uint32_t raw_temperature = ((data[3] & 0x0F) << 16) | (data[4] << 8) | data[5];

	humidity = (raw_humidity * 100.0) / 1048576.0;								// 1048576.0 is a scling factor for c++ reading raw sensor data
	temperature = ((raw_temperature * 200.0) / 1048576.0) - 50;						// 1048576.0 happens to be 2^20 aka 20bit integer from sensor
}

int main(){
	const char *i2c_dev = "/dev/i2c-1";									// The file
	int fd = open(i2c_dev, O_RDWR);										// File descriptor
	if (fd < 0){
		std::cerr << "	****Error opening I2C device****" << std::endl;
		return 1;
	}

	if(ioctl(fd, I2C_SLAVE, AHT10_I2C_ADDR) < 0){
		std::cerr << "	****Failed to acquire bus access****" << std::endl;
		close(fd);
		return 1;
	}

	try{
		while(true){
			float temperature, humidity;
			readAHT10(fd, temperature, humidity);

			std::cout << "Temperature: " << temperature << " Celsius\n";
			std::cout << "Humidity: " << humidity << " Percent\n";
			std::cout << "---- ---- ---- ----\n";
			sleep(0.5);
		}
	} catch (...){
		std::cerr << "Exiting...\n";
	}

	close(fd);
	return 0;
}

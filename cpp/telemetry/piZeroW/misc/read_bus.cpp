#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

#define I2C_BUS "/dev/i2c-1"
#define BMP180_I2C_ADDR 0x77
#define AHT10_I2C_ADDR  0x38 

int openI2CBus() {
    int fd = open(I2C_BUS, O_RDWR);
    if (fd < 0) {
        std::cerr << "Error: Could not open I2C bus!" << std::endl;
        return -1;
    }
    return fd;  // Return file descriptor
}

bool setI2CDevice(int fd, int addr) {
    if (ioctl(fd, I2C_SLAVE, addr) < 0) {
        std::cerr << "Error: Could not communicate with device at address 0x"
                  << std::hex << addr << std::dec << std::endl;
        return false;
    }
    return true;
}

int main() {
    int fd = openI2CBus();
    if (fd < 0) return -1;

    // Example: Select BMP180
    if (setI2CDevice(fd, BMP180_I2C_ADDR)) {
        std::cout << "BMP180 online\n";
    }

    // Example: Switch to AHT10
    if (setI2CDevice(fd, AHT10_I2C_ADDR)) {
        std::cout << "AHT10 online\n";
    }

    close(fd);
    return 0;
}

#include "Communications.h"
#include <fcntl.h>    // For open()
#include <unistd.h>   // For read(), write(), close()
#include <iostream>

PiComm::PiComm() : fileDescriptor(-1), isConnected(false) {}

PiComm::~PiComm() {
    closeConnection();
}

bool PiComm::initialize(const std::string& devicePath, int baudRateOrAddress) {
    // Open device file in Read/Write mode
    fileDescriptor = open(devicePath.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    
    if (fileDescriptor == -1) {
        std::cerr << "Error: Failed to open communication channel to Pi.\n";
        return false;
    }

    // NOTE: For UART or I2C, you would typically use ioctl() or termios 
    // configuration here to set baud rates or slave addresses.

    isConnected = true;
    return true;
}

void PiComm::closeConnection() {
    if (isConnected && fileDescriptor != -1) {
        close(fileDescriptor);
        fileDescriptor = -1;
        isConnected = false;
    }
}

bool PiComm::writeByte(uint8_t data) {
    if (!isConnected) return false;
    
    // Write 1 byte to the Pi's device file descriptor
    ssize_t bytesWritten = write(fileDescriptor, &data, 1);
    return (bytesWritten == 1);
}

int PiComm::readByte() {
    if (!isConnected) return -1;

    uint8_t buffer;
    ssize_t bytesRead = read(fileDescriptor, &buffer, 1);
    
    if (bytesRead > 0) {
        return buffer;
    }
    return -1; // No data read or error
}

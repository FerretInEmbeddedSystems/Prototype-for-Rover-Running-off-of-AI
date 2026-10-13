#ifndef PI_COMM_H
#define PI_COMM_H

#include <cstdint> // For portable types like uint8_t
#include <string>
#include <vector>

class PiComm {
public:
    // Constructor and Destructor
    PiComm();
    ~PiComm();

    // Setup and Configuration
    // e.g., passing "/dev/ttyS0" for Serial or an I2C device address
    bool initialize(const std::string& devicePath, int baudRateOrAddress);
    void closeConnection();

    // Core Communication Functions
    bool writeByte(uint8_t data);
    bool writeBytes(const std::vector<uint8_t>& data);
    
    int readByte(); // Returns -1 on error, or 0-255 on success
    std::vector<uint8_t> readBytes(size_t length);

private:
    int fileDescriptor; // Stores the system file handle (-1 if closed)
    bool isConnected;   // Tracking state
};

#endif // PI_COMM_H

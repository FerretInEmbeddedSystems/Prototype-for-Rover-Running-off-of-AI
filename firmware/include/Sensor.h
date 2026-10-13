#ifndef SENSOR_H
#define SENSOR_H

#include <gpiod.hpp>
#include <string>

class Sensor {
public:
    Sensor(int triggerPin, int echoPin);
    ~Sensor();

    bool initialize();
    
    // Returns distance in centimeters
    float getDistanceCM();
    
    // Quick check to see if an object is dangerously close
    bool isEmergencyClose(float thresholdCM);

private:
    int trigger;
    int echo;
    
    gpiod::chip gpioChip;
    gpiod::line triggerLine;
    gpiod::line echoLine;
    bool isReady;
};

#endif // SENSOR_H


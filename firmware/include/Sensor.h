#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor {
  private:
    uint8_t _trigPin; // Output pin on uno
    uint8_t _echoPin; // input pin on uno

  public:
    DistanceSensor(uint8_t trigPin, uint8_t echoPin);
    
    void begin();
    float getDistance();
};

#endif

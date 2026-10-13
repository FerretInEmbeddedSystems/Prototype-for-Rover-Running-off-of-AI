#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

class ShiftRegister {
  private:
    uint8_t _dataPin;   
    uint8_t _clockPin;  
    uint8_t _latchPin;  
    uint8_t _stateByte;

  public:
    ShiftRegister(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin);
    void begin();
    void writeBit(uint8_t bitPosition, bool value);
};

class Motor {
  private:
    ShiftRegister& _register; 
    uint8_t _pwmPin;
    uint8_t _bitIn1;
    uint8_t _bitIn2;

  public:
    Motor(ShiftRegister& reg, uint8_t pwmPin, uint8_t bitIn1, uint8_t bitIn2);    
    void begin();
    void drive(int speed, bool forward); // Handles TB6612 Forward/Reverse truth tables
    void brake();                        // TB6612 specific: Short brake (IN1=HIGH, IN2=HIGH)
    void coast();                        // TB6612 specific: Stop/Coast (IN1=LOW, IN2=LOW)
};

#endif

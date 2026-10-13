#include <Arduino.h>
#include "Motors.h"

const uint8_t SR_DATA_PIN  = 11; 
const uint8_t SR_CLOCK_PIN = 13; 
const uint8_t SR_LATCH_PIN = 12; 

ShiftRegister mySR(SR_DATA_PIN, SR_CLOCK_PIN, SR_LATCH_PIN);

Motor leftMotor(mySR,  3, 0, 1);  
Motor rightMotor(mySR, 5, 2, 3); 

const int MOVE_SPEED = 180; 

// MOVEMENT CONTROLLER FUNCTIONS

void stop() {
    leftMotor.brake(); // Uses your TB6612 short brake configuration
    rightMotor.brake();
}

void moveForward() {
    leftMotor.drive(MOVE_SPEED, true);  // Left forward
    rightMotor.drive(MOVE_SPEED, true); // Right forward
}

void moveBackward() {
    // BACKUP OPTION: Pass 'false' to flip the TB6612 truth tables to reverse
    leftMotor.drive(MOVE_SPEED, false);  // Left reverse
    rightMotor.drive(MOVE_SPEED, false); // Right reverse
}

void turnLeft() {
    leftMotor.drive(MOVE_SPEED, false); // Pivot left: left wheel backwards
    rightMotor.drive(MOVE_SPEED, true);  // right wheel forwards
}

void turnRight() {
    leftMotor.drive(MOVE_SPEED, true);  // Pivot right: left wheel forwards
    rightMotor.drive(MOVE_SPEED, false); // right wheel backwards
}

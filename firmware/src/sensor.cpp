#include "Sensor.h"
#include <chrono>
#include <thread>
#include <iostream>

Sensor::Sensor(int triggerPin, int echoPin) 
    : trigger(triggerPin), echo(echoPin), isReady(false) {}

Sensor::~Sensor() {
    if (isReady) {
        triggerLine.release();
        echoLine.release();
    }
}

bool Sensor::initialize() {
    try {
        // Open the default GPIO chip on the Pi
        gpioChip = gpiod::chip("0"); 
        
        // Configure the Trigger pin as an OUTPUT
        triggerLine = gpioChip.get_line(trigger);
        triggerLine.request({ "robot_trigger", gpiod::line_request::DIRECTION_OUTPUT, 0 }, 0);
        
        // Configure the Echo pin as an INPUT
        echoLine = gpioChip.get_line(echo);
        echoLine.request({ "robot_echo", gpiod::line_request::DIRECTION_INPUT, 0 });
        
        isReady = true;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "GPIO Initialization failed: " << e.what() << "\n";
        return false;
    }
}

float Sensor::getDistanceCM() {
    if (!isReady) return -1.0f;

    // 1. Ensure trigger is low before pulse
    triggerLine.set_value(0);
    std::this_thread::sleep_for(std::chrono::microseconds(2));

    // 2. Send 10-microsecond high pulse to trigger the sensor
    triggerLine.set_value(1);
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    triggerLine.set_value(0);

    // 3. Wait for echo pin to go HIGH (Start of pulse)
    auto startTime = std::chrono::steady_clock::now();
    auto timeoutStart = std::chrono::steady_clock::now();
    
    while (echoLine.get_value() == 0) {
        startTime = std::chrono::steady_clock::now();
        // Prevent infinite loops if sensor disconnects (timeout after 30ms)
        if (std::chrono::duration_cast<std::chrono::milliseconds>(startTime - timeoutStart).count() > 30) {
            return -1.0f; 
        }
    }

    // 4. Wait for echo pin to go LOW (End of pulse)
    auto endTime = std::chrono::steady_clock::now();
    while (echoLine.get_value() == 1) {
        endTime = std::chrono::steady_clock::now();
    }

    // 5. Calculate time elapsed in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();

    // Speed of sound is 343 m/s or 0.0343 cm/microsecond. 
    // Divide by 2 because the wave travels out and back.
    float distance = (duration * 0.0343f) / 2.0f;
    
    return distance;
}

bool Sensor::isEmergencyClose(float thresholdCM) {
    float currentDistance = getDistanceCM();
    
    // Ignore error readings (-1), but trigger brake if below threshold
    if (currentDistance > 0.0f && currentDistance < thresholdCM) {
        return true;
    }
    return false;
}

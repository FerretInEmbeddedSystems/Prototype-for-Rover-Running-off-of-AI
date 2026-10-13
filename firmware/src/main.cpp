#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "Communications.h"
#include "Motors.h"
#include "Sensor.h"
#include "AI.h"

int main() {
    // 1. Initialize Hardware Communication
    PiComm pi;
    if (!pi.initialize("/dev/serial0", 115200)) return 1;

    // 2. Initialize Subsystems
    MotorController motors(pi);

    // Setup distance sensor on Pi Pins GPIO 23 (Trigger) and GPIO 24 (Echo)
    Sensor proximitySensor(23, 24);
    proximitySensor.initialize();
    
    // 3. Initialize AI Brain
    AI brain;
    if (!brain.loadModel("models/navigation_model.tflite")) {
        std::cerr << "Failed to load AI model!\n";
        return 1;
    }

    std::cout << "All systems green. AI autonomy loop active.\n";


    // 4. Main Control Loop (Running at ~20Hz)
    while (true) {
        
        if (proximitySensor.isEmergencyClose(15.0f)) {
            std::cout << "EMERGENCY BRAKE:Overriding AI.\n";
            motors.executeCommand(Action::STOP);

        switch (choice) {
            case Action::MOVE_FORWARD:
                motors.moveForward(75); // Cruise at 75% speed
                break;
          case Action::MOVE_BACKWARD:
                motors.moveBackward(-50); // 50% as reverse speed
                break
            case Action::TURN_RIGHT:
                motors.turnRight(50);
                break;
            case Action::TURN_LEFT:
                motors.turnLeft(50);
                break;
            case Action::STOP:
            default:
                motors.stop();
                break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}


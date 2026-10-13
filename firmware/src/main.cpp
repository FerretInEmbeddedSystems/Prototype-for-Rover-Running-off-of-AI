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
    SensorReader sensors(pi);
    
    // 3. Initialize AI Brain
    RobotAI brain;
    if (!brain.loadModel("models/navigation_model.tflite")) {
        std::cerr << "Failed to load AI model!\n";
        return 1;
    }

    std::cout << "All systems green. AI autonomy loop active.\n";

    // 4. Main Control Loop (Running at ~20Hz)
    while (true) {
        // --- SENSE ---
        float distance = sensors.getUltrasonicDistance();
        std::vector<float> telemetry = sensors.getGyroscopeData(); // e.g., [X, Y, Z]

        // --- THINK ---
        // Feed the real-world sensor numbers into your AI model
        RobotAction choice = brain.decideNextAction(distance, telemetry);

        // --- ACT ---
        // Execute the AI's structural choice using your hardware wrapper
        switch (choice) {
            case RobotAction::MOVE_FORWARD:
                motors.moveForward(75); // Cruise at 75% speed
                break;
          case RobotAction::MOVE_BACKWARD:
                motors.moveBackward(50); // 50% as reverse speed
            case RobotAction::TURN_RIGHT:
                motors.turnRight(50);
                break;
            case RobotAction::TURN_LEFT:
                motors.turnLeft(50);
                break;
            case RobotAction::STOP:
            default:
                motors.stop();
                break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}


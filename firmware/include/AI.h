#ifndef AI_H
#define AI_H

#include <string>

// The shared commands used by the AI, the main loop, and the motors
enum class Action {
    STOP = 0,
    MOVE_FORWARD = 1,
    MOVE_BACKWARD = 2,
    TURN_LEFT = 3,
    TURN_RIGHT = 4
};

class AI {
public:
    AI();
    ~AI();

    // Loads your model and boots up the Pi camera
    bool initialize(const std::string& modelPath);
    
    // Grabs a frame, runs the model, and outputs one of the commands above
    Action analyzeCurrentFrame(); 
};

#endif // AI_H

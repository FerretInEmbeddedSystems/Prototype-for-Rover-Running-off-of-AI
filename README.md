# Prototype-for-Rover-Running-off-of-AI
I have decided to build a prototype. I'm not sure how well it runs because it is mainly theoretical at this juncture, but I will be including the documentation and required hardware components as well if anybody wants to try it. 
I'd test it but I'm kind of saving up for another thing right now.

## Project Structure Tree
```
RoverOnAI/
├── firmware/
│ ├── src/
| |  ├── main.cpp
| |  ├── motors.cpp
| |  ├── motors.h
| |  ├── sensors.cpp
| |  ├── sensors.h
| |  ├── communication.cpp
| |  └── communication.h
│ └── platformio.ini
├── ai/
│ ├── camera.py
│ ├── model.py
│ ├── navigation.py
│ └── main.py
├── protocol/
│ └── commands.md
├── tests/
├── docs/
├── README.md
├── LICENSE
└── requirements.txt
```

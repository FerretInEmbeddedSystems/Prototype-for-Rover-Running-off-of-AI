# Prototype-for-Rover-Running-off-of-AI
I have decided to build a prototype. I'm not sure how well it runs because it is mainly theoretical at this juncture, but I will be including the documentation and required hardware components as well if anybody wants to try it. 
I'd test it but I'm kind of saving up for another thing right now.

## Project Structure Tree
```
RoverOnAI/
├── docs/
│ ├── hardware/
| |  ├── architecture.md
| |  ├── wiring.md
| |  └── serial-protocol.md
│ └── requirements.md
├── firmware/
│ ├── platformio.ini
│ ├── include/
| |  ├── motors.h
| |  ├── sensors.h
| |  └── communication.h
│ ├── src/
| |  ├── main.cpp
| |  ├── motors.cpp
| |  ├── sensors.cpp
| |  └── communication.cpp
│ └── tests/
│   ├── test_protocol.py
│   └── test_navigation.py
├── ai/
│ ├── main.py
│ ├── model.py
│ ├── camera.py
│ ├── navigation.py
│ └── requirements.txt
├── protocol/
│ └── commands.md
├── README.md
└── LICENSE
```

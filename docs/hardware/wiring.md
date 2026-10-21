# Wiring
  How to basically wire up the entire electrical system.

## 1. Purpose

This document defines the physical electrical connections between the rover's hardware components. It specifies pin assignments, power distribution, grounding, and electrical constraints required for hardware assembly.

Serial communication configuration and message protocols will be documented separately in `serial-io.md`.

## 2. Hardware Inventory

| ID | Component | Model | Reference |
|---|---|---|---|
| HW-01 | Microcontroller | Arduino Uno 4 | [Datasheet](https://docs.arduino.cc/resources/datasheets/ABX00087-datasheet.pdf) |
| HW-02 | Companion Computer | Raspberry Pi 5 | [Datasheet](https://www.richardelectronics.com/blog/projects/raspberry%20pi/raspberry-pi-5-pinout-specs-datasheet-projects) |
| HW-03 | Distance Sensor | HC-SR04 | [Datasheet](https://cdn-learn.adafruit.com/downloads/pdf/ultrasonic-sonar-distance-sensors.pdf) |
| HW-04 | Camera for Companion Computer | Raspberry Pi Camera Module 3 | [Datasheet](https://www.farnell.com/datasheets/4562668.pdf) |
| HW-05 | Motor Driver | TB6612FNG | [Datasheet](https://learn.sparkfun.com/tutorials/tb6612fng-hookup-guide/all) |
| HW-06 | Motor Assembly | G12-N20 Geared Mini DC Motor | [Datasheet](https://www.handsontec.com/dataspecs/motor_fan/GA12-N20.pdf) |
| HW-06 | Battery / Power System | Battery Holder, AAx8 | [Datasheet](https://www.farnell.com/datasheets/2629293.pdf) |

## 3. Wiring Diagram

The diagram below will represent the physical electrical connections between components.

<!-- Insert a verified wiring schematic or connection diagram here. -->


## 4. Pin-to-Pin Connections

| Source Component | Source Pin | Destination Component | Destination Pin | Signal |
|---|---|---|---|---|
| Microcontroller | 5V | Motor Driver | VCC | logic power |
| Microcontroller | GND | Motor Driver | GND | tie all grounds together with the motor power supply negative terminal |
| Microcontroller | D10 | Motor Driver | STBY | pull HIGH to enable the driver |
| Microcontroller | D3 | Motor Driver | PWMA | PWM speed control for Motor A |
| Microcontroller | D9 | Motor Driver | AIN1 | Direction input 1 for Motor A |
| Microcontroller | D8 | Motor Driver | AIN2 | Direction input 2 for Motor A |
| Microcontroller | D5 | Motor Driver | PWMB | PWM speed control for Motor B |
| Microcontroller | D11 | Motor Driver | BIN1 | Direction input 1 for Motor B |
| Microcontroller | D12 | Motor Driver | BIN2 | Direction input 2 for Motor B |
| Microcontroller | GND | Raspberry Pi 5 | Pi Pin 6/GND | Grounding |
| Microcontroller | Pin 0/RX | Raspberry Pi 5 | Pi Pin 8/GPIO 14 | RX-RX |
| Microcontroller | Pin 1/TX | Raspberry Pi 5 | Pi Pin 10/GPIO 15 | TX-TX |
| Microcontroller | A4 | Distance Sensor | SDA | Data Line |
| Microcontroller | A5 | Distance Sensor | SCL | Clock Line |

### Passive wiring map of ribbon connection between camera and pi(you will link one ribbon to get the system working

[ CAMERA MODULE 3 ]                                        [ RASPBERRY PI 5 ]
 15-Pin Connector                                           22-Pin Mini Port
┌────────────────┐                                         ┌────────────────┐
│ (1) GND        ├─────────────────────────────────────────┤ (1) GND        │
│ (2) CAM_D0_N   ├─────────────────────────────────────────┤ (2) CAM_D0_N   │
│ (3) CAM_D0_P   ├─────────────────────────────────────────┤ (3) CAM_D0_P   │
│ (4) GND        ├─────────────────────────────────────────┤ (4) GND        │
│ (5) CAM_D1_N   ├─────────────────────────────────────────┤ (5) CAM_D1_N   │
│ (6) CAM_D1_P   ├─────────────────────────────────────────┤ (6) CAM_D1_P   │
│ (7) GND        ├─────────────────────────────────────────┤ (7) GND        │
│ (8) CAM_CK_N   ├─────────────────────────────────────────┤ (8) CAM_CK_N   │
│ (9) CAM_CK_P   ├─────────────────────────────────────────┤ (9) CAM_CK_P   │
│ (10) GND       ├─────────────────────────────────────────┤ (10) GND       │
│                │                                         │ (11) NC (GND)  │
│                │            [ IDLE TRACKS ]              │ (12) NC (D2)   │
│                │      Pins 11-13 sit empty because       │ (13) NC (D3)   │
│                │      Camera 3 only uses 2 data lanes.    ├────────────────┤
│ (11) POWER-EN  ├─────────────────────────────────────────┤ (14) POWER-EN  │
│ (12) LED-CTRL  ├─────────────────────────────────────────┤ (15) LED-EN    │
│                │                                         │ (16) NC (GND)  │
│ (13) I2C_SCL   ├─────────────────────────────────────────┤ (17) I2C_SCL   │
│ (14) I2C_SDA   ├─────────────────────────────────────────┤ (18) I2C_SDA   │
│ (15) 3.3V VCC  ├─────────────────────────────────────────┤ (19) 3.3V VCC  │
└────────────────┘                                         │ (20) NC (GND)  │
                                                           │ (21) NC (GND)  │
                                                           │ (22) NC (GND)  │
                                                           └────────────────┘


## 5. Power Distribution

Document how electrical power is distributed throughout the system.

When done, we'll know whether to source power from the battery or from the arduino itself. check that we have a net ground connection that the arduino connects for us when a switch needs to be activated to run the n20 motors.

### Uno to Driver
• VM → External Motor Power Supply (2.5V to 13.5V positive terminal)
• AO1 & AO2 → Motor A terminals (+ and -)
• BO1 & BO2 → Motor B terminals (+ and -)



| Component | Supply Voltage | Current Requirement | Power Source |
|---|---|---|---|
| Microcontroller | TBD | TBD | TBD |
| Companion Computer | TBD | TBD | TBD |
| Camera for Computer | TBD | TBD | TBD |
| Distance Sensor | TBD | TBD | TBD |
| Motor Driver | TBD | TBD | TBD |
| Motor Assembly | TBD | TBD | TBD |

Record the battery specifications, regulator outputs, motor supply requirements, and grounding arrangement.

## 6. Electrical Constraints

- Verify supply voltage compatibility for every component.
- Confirm microcontroller GPIO voltage limits.
- Verify motor driver continuous and peak current ratings against motor requirements.
- Ensure appropriate grounding between interconnected devices.
- Confirm connector polarity, wire ratings, and overcurrent protection.
- Do not power motors directly from microcontroller GPIO pins.

## 7. Wiring Verification

- [ ] Confirm component pinouts against datasheets.
- [ ] Verify all connections against the wiring diagram.
- [ ] Check power polarity and inspect for short circuits.
- [ ] Verify supply voltages before connecting sensitive electronics.
- [ ] Confirm serial and other signal connections match `serial-io.md` and the relevant interface documentation.
- [ ] Test each hardware subsystem independently.
- [ ] Record any deviations from the documented wiring.

## 8. Related Documentation

- Hardware architecture: `architecture.md`
- Serial communication: `serial-io.md`
- Firmware implementation: Refer to the relevant source modules.

Stuff I need to make to show what is even going on here.

## 9. Revision History

| Version | Changes |
|---|---|
| 0.1 | Initial wiring documentation |


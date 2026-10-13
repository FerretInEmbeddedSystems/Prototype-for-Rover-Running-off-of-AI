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

### Uno to Driver
• VM → External Motor Power Supply (2.5V to 13.5V positive terminal)
• VCC → Arduino 5V pin (logic power)
• GND → Arduino GND (tie all grounds together with the motor power supply negative terminal)
• STBY → Arduino Digital Pin 10 (pull HIGH to enable the driver)
• PWMA → Arduino Digital Pin 3 (PWM speed control for Motor A)
• AIN1 → Arduino Digital Pin 9 (Direction input 1 for Motor A)
• AIN2 → Arduino Digital Pin 8 (Direction input 2 for Motor A)
• PWMB → Arduino Digital Pin 5 (PWM speed control for Motor B)
• BIN1 → Arduino Digital Pin 11 (Direction input 1 for Motor B)
• BIN2 → Arduino Digital Pin 12 (Direction input 2 for Motor B)
• AO1 & AO2 → Motor A terminals (+ and -)
• BO1 & BO2 → Motor B terminals (+ and -)

### Camera to Pi
Camera Module 3 (15-Pin Connector on Board)

• Pin 1–2: GND, CAM_D0_N / CAM_D0_P (Data Lane 0)
• Pin 3–5: GND, CAM_D1_N / CAM_D1_P (Data Lane 1)
• Pin 6–8: GND, CAM_CK_N / CAM_CK_P (Clock Lane), GND
• Pin 9–11: CAM_IO0 (Power Enable), CAM_IO1 (LED), CAM_SCL (I2C Clock)
• Pin 12–15: CAM_SDA (I2C Data), CAM_3V3 (Power), GND

Raspberry Pi 5 (22-Pin CSI/DSI Connectors)

• Pin 1–2: GND, CAM_D0 (N/P lanes)
• Pin 3–6: CAM_D1, GND, CAM_CK (N/P lanes)
• Pin 7–10: GND, CAM_D2 (N/P lanes)
• Pin 11–14: GND, CAM_D3 (N/P lanes), GND, POWER-EN
• Pin 15–18: LED-EN/XCLK, GND, SCL, SDA
• Pin 19–22: VCC (3.3V), GND

### Pi to Uno
• Ground: Pi Pin 6 (GND) ── Arduino GND
• Pi TX to Arduino RX: Pi Pin 8 (GPIO 14) ── [Shifter] ── Arduino Pin 0 (RX)
• Pi RX to Arduino TX: Pi Pin 10 (GPIO 15) ── [Shifter] ── Arduino Pin 1 (TX)

### Uno to Distance Sensor
If the Arduino R4 is controlling the sensors/motors:
• Data Line (SDA): Connect both the sensor's SDA and motor driver's SDA to Arduino Pin A4 (or the dedicated SDA pin near the USB port).
• Clock Line (SCL): Connect both the sensor's SCL and motor driver's SCL to Arduino Pin A5 (or the dedicated SCL pin near the USB port).
If the Raspberry Pi 5 is controlling the sensors/motors:
• Data Line (SDA): Connect both SDAs to Pi Pin 3 (GPIO 2) through a bi-directional level shifter.
• Clock Line (SCL): Connect both SCLs to Pi Pin 5 (GPIO 3) through a bi-directional level shifter.

| Source Component | Source Pin | Destination Component | Destination Pin | Signal |
|---|---|---|---|---|
| Microcontroller | TBD | Sensor 1 | TBD | Sensor interface |
| Microcontroller | TBD | Sensor 2 | TBD | Sensor interface |
| Microcontroller | TBD | Motor Driver | TBD | Motor control |
| Motor Driver | TBD | Motor Assembly | TBD | Motor output |
| Power System | TBD | Microcontroller | TBD | Supply power |
| Power System | TBD | Motor Driver | TBD | Motor supply |
| Power System | TBD | System Ground | TBD | Ground reference |

Add rows for every required electrical connection. Verify all assignments against the selected component datasheets before assembly.

## 5. Power Distribution

Document how electrical power is distributed throughout the system.

When done, we'll know whether to source power from the battery or from the arduino itself. check that we have a net ground connection that the arduino connects for us when a switch needs to be activated to run the n20 motors.

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


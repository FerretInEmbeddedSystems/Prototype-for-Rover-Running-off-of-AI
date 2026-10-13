# Wiring
  How to basically wire up the entire electrical system.

## 1. Purpose

This document defines the physical electrical connections between the rover's hardware components. It specifies pin assignments, power distribution, grounding, and electrical constraints required for hardware assembly.

Serial communication configuration and message protocols are documented separately in `serial-io.md`.

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

| Component | Supply Voltage | Current Requirement | Power Source |
|---|---|---|---|
| Microcontroller | TBD | TBD | TBD |
| Sensor 1 | TBD | TBD | TBD |
| Sensor 2 | TBD | TBD | TBD |
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

## 9. Revision History

| Version | Changes |
|---|---|
| 0.1 | Initial wiring documentation |


# Serial I/O Documentation
Going to plop this format in for here and figure this all out later, but basically, we are using UART for pi to uno com, I2C for sensor to uno com, and either SPI or I2C for driver to uno com.
pi to cam com will be I2C but will have a free board to pinout from, so more leeway to play with the wiring setup there.

## 1. Purpose

Define the serial communication interfaces used by the rover, including their configuration, message formats, and expected behavior.

## 2. Interface Inventory

| Interface ID | Device / Endpoint | Protocol | Purpose |
|---|---|---|---|
| COM-01 | Microcontroller ↔ Host | TBD | Debugging or telemetry |
| COM-02 | Microcontroller ↔ Peripheral | TBD | Device communication |

## 3. Serial Configuration

| Parameter | Value |
|---|---|
| Interface | UART / USB Serial / TBD |
| Baud Rate | TBD |
| Data Bits | TBD |
| Parity | TBD |
| Stop Bits | TBD |
| Flow Control | TBD |

## 4. Message Definitions

Document each command, response, or telemetry message.

| Message ID | Direction | Format | Purpose |
|---|---|---|---|
| MSG-01 | TBD | TBD | TBD |

## 5. Communication Behavior

- Initialization and connection setup
- Message transmission and reception
- Parsing and validation
- Timeout handling
- Invalid-message handling
- Communication recovery

## 6. Hardware References

Refer to `wiring.md` for physical pin connections, voltage compatibility, and electrical requirements.

## 7. Firmware References

List the firmware modules responsible for serial communication and message processing.

## 8. Verification

Document tests for valid messages, invalid messages, timeouts, and communication failures.

## 9. Revision History

| Version | Changes |
|---|---|
| 0.1 | Initial serial I/O documentation |

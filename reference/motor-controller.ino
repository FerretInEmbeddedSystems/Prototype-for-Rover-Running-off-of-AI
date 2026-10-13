// Arduino Code (Runs on the Arduino Uno/Nano/Mega)
void setup() {
  Serial.begin(115200); // Must match the baud rate in PiComm.h
  pinMode(leftMotorPin, OUTPUT);
  pinMode(rightMotorPin, OUTPUT);
}

void loop() {
  // Wait until the Pi sends a motor command packet
  if (Serial.available() >= 3) { 
    uint8_t commandType = Serial.read();
    uint8_t leftSpeed   = Serial.read();
    uint8_t rightSpeed  = Serial.read();

    if (commandType == 0x01) { // 0x01 = Move command
      analogWrite(leftMotorPin, leftSpeed);
      analogWrite(rightMotorPin, rightSpeed);
    } else if (commandType == 0x00) { // 0x00 = Stop command
      analogWrite(leftMotorPin, 0);
      analogWrite(rightMotorPin, 0);
    }
  }
}

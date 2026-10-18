
import serial
import time


class RoverCommunication:
    def __init__(self, port="/dev/ttyACM0", baud=115200):
        self.serial = serial.Serial(
            port=port,
            baudrate=baud,
            timeout=1,
            write_timeout=1
        )

        # Some Arduino boards reset when serial opens.
        time.sleep(2)

    def send_command(self, command):
        allowed = {"STOP", "LEFT", "RIGHT", "FORWARD"}

        if command not in allowed:
            command = "STOP"

        self.serial.write((command + "\n").encode("ascii"))

    def close(self):
        self.send_command("STOP")
        self.serial.close()


from picamera2 import Picamera2
import time

from perception import RoverPerception
from decision import choose_action
from communication import RoverCommunication


MODEL_PATH = "models/rover_model.tflite"


def main():
    camera = Picamera2()
    camera.configure(
        camera.create_video_configuration(
            main={"format": "RGB888", "size": (320, 240)}
        )
    )

    perception = RoverPerception(MODEL_PATH)
    communication = None

    try:
        camera.start()
        communication = RoverCommunication()

        while True:
            frame = camera.capture_array()

            class_index, confidence = perception.predict(frame)

            action = choose_action(class_index, confidence)

            print(
                f"Class: {class_index}, "
                f"Confidence: {confidence:.2f}, "
                f"Action: {action}"
            )

            communication.send_command(action)

            time.sleep(0.05)

    except KeyboardInterrupt:
        print("Rover stopping.")

    finally:
        if communication is not None:
            try:
                communication.send_command("STOP")
                communication.close()
            except Exception:
                pass

        camera.stop()


if __name__ == "__main__":
    main()


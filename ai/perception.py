
import numpy as np
from tflite_runtime.interpreter import Interpreter


class RoverPerception:
    def __init__(self, model_path):
        self.interpreter = Interpreter(
            model_path=model_path,
            num_threads=2
        )
        self.interpreter.allocate_tensors()

        self.input_info = self.interpreter.get_input_details()[0]
        self.output_info = self.interpreter.get_output_details()[0]

        _, self.height, self.width, channels = (
            self.input_info["shape"]
        )

        if channels != 3:
            raise ValueError("Expected a 3-channel RGB model.")

    def predict(self, rgb_frame):
        # Resize and prepare the camera frame.
        import cv2

        image = cv2.resize(
            rgb_frame, (self.width, self.height)
        )
        image = np.expand_dims(image, axis=0)

        # Match this preprocessing to model training.
        dtype = self.input_info["dtype"]

        if dtype == np.float32:
            image = image.astype(np.float32) / 255.0
        else:
            image = image.astype(dtype)

        self.interpreter.set_tensor(
            self.input_info["index"], image
        )
        self.interpreter.invoke()

        scores = self.interpreter.get_tensor(
            self.output_info["index"]
        )[0]

        best_index = int(np.argmax(scores))

        return best_index, float(scores[best_index])

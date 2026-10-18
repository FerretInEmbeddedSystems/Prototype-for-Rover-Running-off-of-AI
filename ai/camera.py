
# camera.py

from picamera2 import Picamera2


class RoverCamera:
    def __init__(self, width=320, height=240):
        self.width = width
        self.height = height
        self.camera = None

    def start(self):
        self.camera = Picamera2()

        config = self.camera.create_video_configuration(
            main={
                "size": (self.width, self.height),
                "format": "RGB888"
            }
        )

        self.camera.configure(config)
        self.camera.start()

    def capture_frame(self):
        if self.camera is None:
            raise RuntimeError("Camera has not been started")

        return self.camera.capture_array()

    def stop(self):
        if self.camera is not None:
            self.camera.stop()
            self.camera = None

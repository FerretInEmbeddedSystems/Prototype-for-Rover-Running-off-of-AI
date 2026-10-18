
# The order MUST match the class order used in training.
CLASS_LABELS = [
    "STOP",
    "LEFT",
    "FORWARD",
    "RIGHT",
]

CONFIDENCE_THRESHOLD = 0.80


def choose_action(class_index, confidence):
    # Uncertain predictions must not cause movement.
    if confidence < CONFIDENCE_THRESHOLD:
        return "STOP"

    label = CLASS_LABELS[class_index]

    if label == "STOP":
        return "STOP"
    elif label == "LEFT":
        return "LEFT"
    elif label == "FORWARD":
        return "FORWARD"
    elif label == "RIGHT":
        return "RIGHT"

    # Unknown or invalid class.
    return "STOP"

import os
import time
import fpp

PIPE_PATH = "../pipe"

# extend the fpp.Listener class to create a custom listener
class PipeListener(fpp.Listener):
    def __init__(self, pipe_path):
        self.pipe_path = pipe_path

    # Override the on_message_received method to handle incoming messages
    def on_message_received(self, msg):
        with open(self.pipe_path, 'w') as pipe:
            pipe.write(msg + '\n')
            pipe.flush()


# Main function for the peripheral reader
def main():
    # Check if the pipe exists, if not create it
    if not os.path.exists(PIPE_PATH):
        os.mkfifo(PIPE_PATH)

    # Initialize the Peripheral object and Notifier
    peripheral = fpp.Peripheral("/dev/peripheral")
    listener = PipeListener(PIPE_PATH)
    notifier = fpp.Notifier(peripheral, [listener])

    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        print("[Reader] Stopped.")
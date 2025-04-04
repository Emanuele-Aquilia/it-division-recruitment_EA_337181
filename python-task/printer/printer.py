import os
import time

PIPE_PATH = "../pipe"  # Same pipe path as the reader

def main():
    # Wait until the pipe exists, since the reader creates it
    if not os.path.exists(PIPE_PATH):
        while not os.path.exists(PIPE_PATH):
            time.sleep(1)

    # Open the pipe for reading
    with open(PIPE_PATH, 'r') as pipe:
        while True:
            # Read a line from the pipe
            # If the pipe is empty, this will block until a line is written
            line = pipe.readline()
            if line:
                print(f"{line.strip()}")

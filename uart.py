#!python
import time
import cgi
from serial import Serial
import subprocess

ser = Serial('COM45', 9600, timeout=1)
print("connected to: " + ser.portstr)

while True:
    # Read a line and convert it from b'xxx\r\n' to xxx
    line = ser.readline().decode('utf-8')[:-2]

    if line:  # If it isn't a blank line
        print(line)
        if line == '520':
            subprocess.call(["xte", "key Up"])
        elif line == '620':
            subprocess.call(["xte", "key Down"])
        elif line == '110':
            break

ser.close()

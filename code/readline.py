import serial
import time

# Open serial connection
ser = serial.Serial('/dev/tty.usbmodemHIDPC1', 9600)  # Adjust COM port accordingly

# Read lines from "rockyou.txt" and send them to Arduino
with open("rockyou.txt", "r") as file:
    for line in file:
        line = line.strip()
        ser.write((line + '\n').encode())
        time.sleep(0.1)  # Delay between sending lines

# Close serial connection
ser.close()

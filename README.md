# badusb: Brute-force Attacker
This is a keystroke injector made using Pro Micro chip to crack passwords.
A badusb uses brute force and dictionary attack to penetrate internet accounts, files, folders and other sensitive data. It uses pydictor to Social Engineer user passwords.

Link to install pydictor: https://github.com/LandGrey/pydictor
Lint to install rockyou.txt: https://github.com/brannondorsey/naive-hashcat/releases/download/data/rockyou.txt

Make sure your wordlist and python script are in the same directory and run the script to start the brute force process.
As an example, I have used rockyou.txt to run my device. You can modify your python script according to the name of your text file.

Download the required libraries/boards in your Arduino IDE to run the badusb. 
Sparkfun AVR Boards
U8glib (display)

Disclaimer:

This project is designed and intended for educational purposes only. It is not intended to be used for any malicious, harmful, or illegal activities. Any actions taken with the knowledge gained from this project are the sole responsibility of the individual user. The creators of this project do not condone or support any misuse or unethical use of the information or techniques provided. Users should adhere to all applicable laws and regulations in their use of this project.

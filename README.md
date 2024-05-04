# Password-Secure-door-lock-using-IoT

This Arduino sketch provides a simple password-based door opener system using a keypad, EEPROM, and a liquid crystal display (LCD). The system utilizes the Keypad library for interfacing with the keypad, LiquidCrystal library for the LCD, and EEPROM library for storing the password.

## Requirements

- Arduino board (e.g., Arduino Uno)
- Keypad
- Liquid Crystal Display (16x2)
- Buzzer
- Motor Driver
- DC Motor
- Jumper wires
- Power supply

## Wiring

- Keypad:
  - Connect rows to pins 9, 8, 7, and 6.
  - Connect columns to pins 5, 4, 3, and 2.
- LCD:
  - Connect RS to A0, RW to A1, EN to A2, D4 to A3, D5 to A4, and D6 to A5.
- Motor Driver:
  - Connect motor 1A to pin 10 and motor 1B to pin 11.
- Buzzer:
  - Connect to pin 12.
- LED:
  - Connect to pin 13.

## Usage

1. Upload the sketch to your Arduino board.
2. Input the correct password using the keypad.
3. If the password is correct, the system will open the door. If not, it will indicate a wrong password.

## Functionality

- The sketch initializes the system by setting up the keypad, LCD, and pins.
- Users can input a password using the keypad. The LCD displays '*' for each entered digit.
- After five digits are entered, the system checks if the password matches the predefined one.
- If the password matches, the door opens using a DC motor connected via a motor driver.
- If the password is incorrect, the system indicates this with a buzzer and LCD message.
- The door closes automatically after a predefined delay.

## Note

- Ensure the correct wiring and power supply to avoid malfunctions.
- Customize the `password` variable to set your desired password.
- Adjust motor opening and closing delays (`openCloseDoor` function) based on your motor's specifications.

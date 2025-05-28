# arduino-ssd1306-bouncing-text

This repository contains a simple Arduino sketch that displays a piece of text bouncing around on a 128×32 SSD1306 OLED display. The animation moves the string back and forth across the screen in a "ping‑pong" style so you can see how to use the SSD1306 library for small graphical effects.

## Hardware required

- An Arduino-compatible microcontroller (e.g. Arduino Uno, Nano, etc.)
- A 128×32 I2C SSD1306 OLED display
- Jumper wires

## Dependencies

The sketch relies on the following libraries, which can be installed via the Arduino Library Manager:

- **Adafruit GFX Library** – provides basic graphics primitives
- **Adafruit SSD1306** – driver for SSD1306-based displays

Make sure both libraries are installed before compiling the sketch.

## Usage

1. Clone this repository or download the `bouncing_text.ino` sketch.
2. Open the sketch in the Arduino IDE.
3. Connect the OLED display to your board using the standard I2C pins (SDA and SCL) as well as power (VCC to 3.3/5 V and GND).
4. Select your board and port in the IDE and upload the sketch.
5. After uploading, the display should show the text message bouncing across the screen.

Feel free to modify the message or change the display size if you are using a different SSD1306 module.

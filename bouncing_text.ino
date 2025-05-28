#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Display dimensions
#define SCREEN_WIDTH 128    // OLED width, in pixels
#define SCREEN_HEIGHT 32    // OLED height, in pixels

#define OLED_RESET    -1    // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Wire.begin();                                        // Initialize I2C
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {    // Initialize display
    for (;;);                                          // Halt on failure
  }

  display.clearDisplay();                              // Clear buffer
  display.setTextSize(1);                              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);                 // White text
  display.display();                                   // Commit clear
}

void loop() {
  static int16_t x_pos = 0;                            // Initial X position
  static int16_t y_pos = 0;                            // Initial Y position
  static int8_t  dx = 1;                               // X velocity (pixels/frame)
  static int8_t  dy = 1;                               // Y velocity (pixels/frame)
  const char*   text = "Daniel";                       // Scrolling text

  // Compute text bounds (width, height)
  int16_t x1, y1;
  uint16_t text_w, text_h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &text_w, &text_h);

  // Clear previous frame
  display.clearDisplay();

  // Draw text at current position
  display.setCursor(x_pos, y_pos);
  display.print(text);
  display.display();

  // Update position
  x_pos += dx;
  y_pos += dy;

  // Bounce horizontally
  if (x_pos <= 0 || x_pos >= SCREEN_WIDTH - text_w) {
    dx = -dx;  // Reverse X direction
    x_pos = constrain(x_pos, 0, SCREEN_WIDTH - text_w);
  }

  // Bounce vertically
  if (y_pos <= 0 || y_pos >= SCREEN_HEIGHT - text_h) {
    dy = -dy;  // Reverse Y direction
    y_pos = constrain(y_pos, 0, SCREEN_HEIGHT - text_h);
  }

  delay(30);  // Control animation speed (lower = faster)
}

#include "Keyboard.h"
#include "U8glib.h"
#include "EEPROM.h"

#define SWITCH_PIN 7 // Pin connected to the switch
#define DISPLAY_PIN 8 // Pin connected to the display

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

unsigned long startTime = 0;

void setup() {
  Keyboard.begin();
  pinMode(SWITCH_PIN, INPUT);
  pinMode(DISPLAY_PIN, OUTPUT);

  // Wait for serial connection
  Serial.begin(9600);
  while (!Serial);

  // Read start time from EEPROM
  EEPROM.get(0, startTime);
}

void loop() {
  int switchState = digitalRead(SWITCH_PIN);

  if (switchState == HIGH) {
    if (Serial.available()) {
      String password = Serial.readStringUntil('\n');
      password.trim();
      
      // Store start time in EEPROM if not set
      if (startTime == 0) {
        startTime = millis();
        EEPROM.put(0, startTime);
      }

      bruteforce(password);
    }
  } else {
    // Reset start time if switch is off
    startTime = 0;
    EEPROM.put(0, startTime);
  }

  delay(100);
}

void bruteforce(String prev) {
  while (digitalRead(SWITCH_PIN) == LOW) {
    // Wait until the switch is pressed
  }

  Keyboard.println(prev);

  u8g.firstPage();
  do {
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(0, 22, prev.c_str());
  } while (u8g.nextPage());

  delay(100);
}

/*


 */

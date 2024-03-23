//using the "" first checks your local directory, and if it doesn't find a match then moves on to check the system paths. Using <> starts the search with system headers.
#include "Arduino.h"
#include <LiquidCrystal_I2C_Hangul.h>
#include <Wire.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); //I2C address in hex, followed by number of columns and rows

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  delay(1000);
  lcd.print("Hello Steve!");
  Serial.println ("Setup complete");
}

void loop() {
	delay(1000);
	lcd.setCursor(0,1); //Column starting at 0, Row 0 for top and 1 for bottom
	lcd.print("Bottom row");
	delay(1000);
	lcd.clear();
	Serial.println("Loop running");
}

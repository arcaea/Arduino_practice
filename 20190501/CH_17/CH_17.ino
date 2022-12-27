#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
char control = '0';
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop() {
  if (Serial.available() > 0) {
    control = Serial.read();
    lcd.clear();
    if (control == '0') {
      lcd.print("STOP");
    }
    if (control == '1') {
      lcd.print("GO-AHEAD");
    }
    if (control == '2') {
      lcd.print("BACKWARD");
    }
    if (control == '3') {
      lcd.print("TURN-RIGHT");
    }
    if (control == '4') {
      lcd.print("TURN-LEFT");
    }
  }
}

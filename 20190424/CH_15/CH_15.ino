#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(39, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int i;
void setup() {
  lcd.begin(16, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
  lcd.print("Arduino LCD Demo");
}
void loop() {
  for (i = 0; i <= 15; i = i + 1) {
    lcd.setCursor(i, 1);
    lcd.write(0xff);
    delay(300);
  }
  for (i = 15; i >= 0; i = i - 1) {
    lcd.setCursor(i, 1);
    lcd.write(" ");
    delay(300);
  }
}


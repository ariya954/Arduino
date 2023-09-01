#include <LiquidCrystal.h>

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  lcd.begin(16, 2);

}

void loop() {
  lcd.setCursor(3, 0);
  lcd.print("Ariya.com");
  lcd.setCursor(5, 1);
  lcd.print("Test");
  delay(2000);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Our Test");
  lcd.setCursor(1, 1);
  lcd.print("Was Succesful");
  delay(2000);
  lcd.clear();  

}

#include <LiquidCrystal.h>
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5 ,d6, d7);
int pot = A1;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  int voltage_of_potentialmeter;
  voltage_of_potentialmeter = analogRead(pot);
  lcd.setCursor(0, 0);
  lcd.print("voltage of pot:");
  lcd.setCursor(0, 1);
  lcd.print(voltage_of_potentialmeter * 5 / 1023);
  lcd.setCursor(2, 1);
  lcd.print(" volts");
  delay(1000);
  lcd.clear();
}

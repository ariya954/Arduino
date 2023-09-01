#include <LiquidCrystal.h>
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int lm35 = A1;
int temperature_ADC;
float temperature;

void setup() {
  lcd.begin(16, 2);
  
}

void loop() {
  temperature_ADC = analogRead(lm35);
  temperature = temperature_ADC * 4.88 / 10;
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  delay(1000);
  lcd.clear();

}

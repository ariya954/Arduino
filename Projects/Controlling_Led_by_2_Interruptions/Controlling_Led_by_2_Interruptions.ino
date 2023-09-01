#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int LED = 13;
int state = LOW;

void setup() 
{
  lcd.begin(16, 2);
  pinMode(LED, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  attachInterrupt(digitalPinToInterrupt(2), buttonpressed1, LOW);
  attachInterrupt(digitalPinToInterrupt(3), buttonpressed2, LOW);
}

void loop() 
{
  lcd.setCursor(0, 0);
  lcd.print("Ariya.com");
  digitalWrite(LED, state);
  delay(500);
  lcd.clear();
}

void buttonpressed1() 
{
  state = LOW;
  lcd.setCursor(0, 1);
  lcd.print("interrupt1=OFF");
}

void buttonpressed2() 
{
  state = HIGH;
  lcd.setCursor(0, 1);
  lcd.print("interrupt2=ON");
}

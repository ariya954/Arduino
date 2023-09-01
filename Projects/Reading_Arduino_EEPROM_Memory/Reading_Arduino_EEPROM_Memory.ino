#include <EEPROM.h>

int state;

void setup()
{
  Serial.begin(9600);
  int cap = EEPROM.length();
  for(int i = 0; i < cap; i++)
  {
    state = EEPROM.read(i);
    Serial.print(i);
    Serial.print("\t");
    Serial.println(state);
  }
}

void loop() 
{}

#include <EEPROM.h>

void setup() 
{
  int cap = EEPROM.length();
  for(int i = 0; i < cap; i++)
  {
    EEPROM.write(i, 0);
  }
}

void loop() 
{}

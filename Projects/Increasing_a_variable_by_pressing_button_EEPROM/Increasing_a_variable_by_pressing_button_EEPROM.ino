#include <EEPROM.h>

int read1;
int button = 2;
int i;

void setup() 
{
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  read1 = EEPROM.read(0);
  Serial.println(read1);
}

void loop() 
{
  int button_state = digitalRead(button);
  read1 = EEPROM.read(0);
  int i = read1;
  if(button_state == LOW)
  {
    i++;
    Serial.println(i);
    EEPROM.write(0, i);
    delay(400);
  }
}

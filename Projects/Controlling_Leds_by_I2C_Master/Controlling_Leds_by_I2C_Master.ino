#include <Wire.h>

int LED = 3;
int button = 2;
int button_state;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Wire.begin();
}

void loop() 
{
  Wire.requestFrom(8, 1);
  byte master_recieved = Wire.read();
  if (master_recieved == 1)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
  byte master_send;
  button_state = digitalRead(button);
  if (button_state == LOW)
  {
    master_send = 1;
  }
  else
  {
    master_send = 0;
  }
  Wire.beginTransmission(8);
  Wire.write(master_send);
  Wire.endTransmission();
}

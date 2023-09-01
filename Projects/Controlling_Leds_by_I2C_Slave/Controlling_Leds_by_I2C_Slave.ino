#include <Wire.h>

byte slave_received, slave_send;
int LED = 3;
int button = 2;
int button_state;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}

void loop() 
{
  if (slave_received == 1)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

void receiveEvent()
{
  slave_received = Wire.read(); 
}

void requestEvent()
{
  button_state = digitalRead(button);
  if (button_state == LOW)
  {
    slave_send = 1;
  }
  else
  {
    slave_send = 0;
  }
  Wire.write(slave_send);
}

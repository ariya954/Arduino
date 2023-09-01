#include <SPI.h>

int LED = 7;
int button = 2;
int button_value;

void setup() 
{
  pinMode(button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH);
}

void loop()
{
  int Master_send, Master_recieve;
  button_value = digitalRead(button);
  if (button_value == LOW)
  {
    Master_send = 1;
  }
  else
  {
    Master_send = 0;
  }
  digitalWrite(SS, LOW);
  Master_recieve = SPI.transfer(Master_send);
  if (Master_recieve == 1)
  {
    digitalWrite(LED, HIGH);
  }
  if (Master_recieve == 0)
  {
    digitalWrite(LED, LOW);
  }
  delay(1000);
}

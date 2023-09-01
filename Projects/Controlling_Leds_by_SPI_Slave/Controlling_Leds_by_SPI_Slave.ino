#include <SPI.h>

int LED = 7;
int button = 2;
int button_value;
volatile boolean received;
int Slave_send, Slave_recieve;

void setup() 
{
  pinMode(button, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(MISO, OUTPUT);
  received = false;
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}

ISR (SPI_STC_vect)
{
  Slave_recieve = SPDR;
  received = true;
}

void loop()
{
  if (received)
  {
    if (Slave_recieve == 1)
    {
      digitalWrite(LED, HIGH);
    }
    if (Slave_recieve == 0)
    {
      digitalWrite(LED, LOW);
    }
    button_value = digitalRead(button);
    if (button_value == LOW)
    {
      Slave_send = 1;
    }
    else
    {
      Slave_send = 0;
    }
    SPDR = Slave_send;
    delay(1000);
  }
}

int pin[5] = {2, 3, 4, 5, 6};

void setup() 
{
  for(int i = 0; i < 5; i++)
  {
    pinMode(pin[i], OUTPUT);
  }
}

void loop() 
{
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(pin[i], HIGH);
    delay(50);
    digitalWrite(pin[i], LOW);
    delay(50);    
  }
}

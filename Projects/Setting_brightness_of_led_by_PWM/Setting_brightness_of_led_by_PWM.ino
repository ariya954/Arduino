int led = 3;

void setup() 
{
  pinMode(led, OUTPUT);
}

void loop() 
{
  for(int brightness = 0; brightness <= 255; brightness++)
  {
     analogWrite(led, brightness);
     delay(8);
  }
  for(int brightness = 255; brightness >= 0; brightness--)
  {
     analogWrite(led, brightness);
     delay(8);
  }
}

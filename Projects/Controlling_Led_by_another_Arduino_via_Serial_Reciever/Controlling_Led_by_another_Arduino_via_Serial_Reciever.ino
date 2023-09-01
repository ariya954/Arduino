int LED = 2;

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
  {
    int state = Serial.read();
    if(state == '1')
    {
      digitalWrite(LED, HIGH);
    }    
    if(state == '0')
    {
      digitalWrite(LED, LOW);
    }    
  }
}

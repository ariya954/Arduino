int button = 3;

void setup() 
{
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  int button_state = digitalRead(button);
  if(button_state == LOW)
  {
    Serial.println('1');
  }
  if(button_state == HIGH)
  {
    Serial.println('0');
  }  
}

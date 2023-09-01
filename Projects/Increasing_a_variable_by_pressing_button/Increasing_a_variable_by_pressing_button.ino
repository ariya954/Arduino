int button = 2;
int i;

void setup() 
{
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  Serial.println(i);
}

void loop() 
{
  int button_state = digitalRead(button);
  if(button_state == LOW)
  {
    i++;
    Serial.println(i);
    delay(400);
  }
}

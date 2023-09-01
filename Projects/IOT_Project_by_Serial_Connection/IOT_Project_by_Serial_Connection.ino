int relay1 = 2;
int relay2 = 3;
int relay3 = 4;

void setup() 
{
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
}

void loop() 
{
  if(Serial.available())
  {
    int state = Serial.read();
    if(state == '1')
    {
      digitalWrite(relay1, HIGH);
      Serial.println("TV ON");
    }
    if(state == '2')
    {
      digitalWrite(relay1, LOW);
      Serial.println("TV OFF");
    }
    if(state == '3')
    {
      digitalWrite(relay2, HIGH);
      Serial.println("Lamp1 ON");
    } 
    if(state == '4')
    {
      digitalWrite(relay2, LOW);
      Serial.println("Lamp1 OFF");
    }
    if(state == '5')
    {
      digitalWrite(relay3, HIGH);
      Serial.println("Lamp2 ON");
    } 
    if(state == '6')
    {
      digitalWrite(relay3, LOW);
      Serial.println("Lamp2 OFF");
    }          
  }
}

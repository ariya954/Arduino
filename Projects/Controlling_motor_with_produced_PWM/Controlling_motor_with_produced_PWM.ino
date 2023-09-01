int pin_which_produces_PWM = 12;
int pot = A0;
int on_time = 0;
int off_time = 0;

void setup() 
{
  pinMode(pin_which_produces_PWM, OUTPUT);
  pinMode(pot, INPUT);
}

void loop()
{
  off_time = analogRead(pot);
  on_time = 1024 - off_time;
  digitalWrite(pin_which_produces_PWM, HIGH);
  delayMicroseconds(on_time);
  digitalWrite(pin_which_produces_PWM, LOW);
  delayMicroseconds(off_time);  
}

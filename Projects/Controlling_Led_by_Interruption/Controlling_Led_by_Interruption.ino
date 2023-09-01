int LED = 10;
bool LED_state = LOW;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), Interrupt_Programme, CHANGE);
}

void loop() 
{
  digitalWrite(LED, LED_state);
}

void Interrupt_Programme()
{
  LED_state = !LED_state;
}

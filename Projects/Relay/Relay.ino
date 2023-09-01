int relay = 2;
int button = 3;
int button_state = 0;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(button, INPUT_PULLUP);  
}

void loop() {
  button_state = digitalRead(button);
  if(button_state == LOW)
    digitalWrite(relay, HIGH);
  else
    digitalWrite(relay, LOW);
}

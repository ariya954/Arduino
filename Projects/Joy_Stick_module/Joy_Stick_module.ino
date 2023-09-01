int x = A0;
int y = A1;
int SW = 6;

int up = 2;
int right = 3;
int down = 4;
int left = 5;

int xpos;
int ypos;
int SW_state;
 
void setup() {
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(SW, INPUT_PULLUP);

  pinMode(up, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(left, OUTPUT);
}

void loop() {
  xpos = analogRead(x);
  ypos = analogRead(y);
  SW_state = digitalRead(SW);

  if (ypos > 1000)
  {
    digitalWrite(up, HIGH);
  }
  else
  {
    digitalWrite(up, LOW);
  }
    
  if (ypos < 100)
  {
    digitalWrite(down, HIGH);
  }
  else
  {
    digitalWrite(down, LOW);
  }

  if (xpos > 1000)
  {
    digitalWrite(right, HIGH);
  }
  else
  {
    digitalWrite(right, LOW);
  }

  if (xpos < 100)
  {
    digitalWrite(left, HIGH);
  }
  else
  {
    digitalWrite(left, LOW);
  }

  if (SW_state == LOW)
  {
    digitalWrite(up, HIGH);
    digitalWrite(right, HIGH);
    digitalWrite(down, HIGH);
    digitalWrite(left, HIGH);
  }
    
}

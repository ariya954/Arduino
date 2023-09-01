void setup() 
{
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  int x = random(20, 100);
  Serial.println(x);
}

void loop() 
{}

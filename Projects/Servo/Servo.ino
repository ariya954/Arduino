#include <Servo.h>
Servo servo;

void setup() 
{
  servo.attach(3);
}

void loop()
{
  int angle;
  for(angle = 0; angle < 180; angle++)
  {
    servo.write(angle);
    delay(5);
  }
  for(angle = 180; angle > 0; angle--)
  {
    servo.write(angle);
    delay(5);
  }
}

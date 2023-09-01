int array1[] = {1,2,3,4,5,6};
int array2[5];
int x;

void setup()
{
  Serial.begin(9600);
  array2[2] = 4;
  x = array2[3];
  Serial.println(x);
}

void loop() {
  // put your main code here, to run repeatedly:

}

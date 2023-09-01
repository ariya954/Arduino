String str1 = "Mohammad";
String str2 = "Mohammad";
String str3 = "1234";

void setup()
{
  Serial.begin(9600);
  bool x = str2.equals(str1);
  Serial.println(x);
}

void loop() 
{}

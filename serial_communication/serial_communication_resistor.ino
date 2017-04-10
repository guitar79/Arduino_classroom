void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int read_Val = analogRead(A0);  
  Serial.println (read_Val);
}

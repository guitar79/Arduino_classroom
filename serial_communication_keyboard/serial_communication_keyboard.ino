void setup()
{
Serial.begin(9600); pinMode(13, 1);
}
void loop()
{
  if (Serial.available()>0)  {
char read_Val = Serial.read();
if(read_Val == 'a'){
  digitalWrite(13 ,1);
}
if(read_Val == 'b'){
  digitalWrite(13 ,0);
}
  }
}

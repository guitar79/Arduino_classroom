int ledPin = 13;
 
void setup()
{
  Serial.begin(9600);
   pinMode(ledPin, OUTPUT);
}
void loop()
{
  Serial.write(1);
   digitalWrite(ledPin, HIGH);
  delay(200);
  Serial.write(0);
   digitalWrite(ledPin, LOW);
  delay(200);
}

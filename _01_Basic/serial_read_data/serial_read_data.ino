
int lightValue = 0;
void setup(){
  Serial.begin(9600);
}
  void loop(){
  lightValue = analogRead(6);
  Serial.println(lightValue);
  Serial.println(" ");
  delay(1000);
}


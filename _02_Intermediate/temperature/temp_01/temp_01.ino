
/*
 LM35 Temp sonsor
 analog 0: V out
*/
void setup(){
Serial.begin(9600);
pinMode(5,1);
}

void loop() {
  int randomValue = random(0,1023);
  float temp;
  int arA0; int arA1; int arA2;
  arA0 = analogRead(A0);
  arA1 = analogRead(A1);
  arA2 = analogRead(A2);
  temp = arA1/1024*5000/10;
  Serial.println(arA0);
  Serial.println(arA1);
  Serial.println(arA2);
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.println("\n");  
  delay(3000);
}

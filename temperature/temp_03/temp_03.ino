
/*
 NTC 3470 Temp sonsor
 analog 0: V out
*/

const int inPin =1;
//const int putPin = 5;
//const int threshold = 25;

void setup(){
Serial.begin(9600);
//pinMode(putPin,1);
}

void loop() {
  float ohm = 0.0, value1 = 0.0;
  value1 = analogRead(inPin);
  ohm = 10000*(1024-value1)/value1;
  Serial.print("Resist is = ");
  Serial.print(ohm);
  Serial.println("\n"); 
   Serial.print(value1);
  Serial.println("\n");   
  delay(3000);
}

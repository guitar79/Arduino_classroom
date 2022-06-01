
/*
 LM35 Temp sonsor
 analog 0: V out
*/

const int inPin =1;
const int putPin = 5;
const int threshold = 25;

void setup(){
Serial.begin(9600);
pinMode(putPin,1);
}

void loop() {
  int value1 = analogRead(inPin);
  long celsius = (value1 * 500L) / 1024;
  float temp = (value1 / 5000) * 102.4;
//  float temp;
  int arA0; int arA1; int arA2;
  arA0 = analogRead(A0);
  arA1 = analogRead(A1);
  arA2 = analogRead(A2);

  Serial.println(arA0);
  Serial.println(arA1);
  Serial.print(value1);
  Serial.println("\n");  
  Serial.println(arA2);
  Serial.print("Temperature = ");
  Serial.print(celsius);
  Serial.println("\n"); 
   Serial.print(temp);
  Serial.println("\n");   
  delay(3000);
}


/*
 NTC 3470 Temp sonsor
 analog 0: V out
*/
int analPin = 1;
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
long x=0, vcc=4840;
float th=0,ce=0;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analPin);    // read the value from the sensor
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  x = map(val,0,1023,0,vcc);
  th = (((float)(vcc-x)*10.0)/(float)x)*1000.0;
  ce = ((log(4.0*th - 3000.0) / (-0.024119329) + 473)-32.0)/1.8;
  
  Serial.print(vcc-x);
  Serial.print(", ");
  Serial.print(x);
  Serial.print(", ");
  Serial.println(th);
  //Serial.print(", ");
  Serial.println(ce);
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(3000);                  // stop the program for some time
}

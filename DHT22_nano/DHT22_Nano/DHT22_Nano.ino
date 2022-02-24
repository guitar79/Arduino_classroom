/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  pinMode(A7, INPUT); 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  led_check();
  analog_read_printSerial();
  degital_read_printSerial();
}

void led_check(){
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(100);               // wait for a second
}

void analog_read_printSerial(){
    // read the input on analog pin 0:
  int sensorValue = analogRead(A7);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);  
}

void degital_read_printSerial(){
    // read the input on analog pin 0:
  int sensorValue = digitalRead(A7);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);  
}

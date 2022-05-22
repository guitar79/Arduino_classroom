int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT); 
}
 
void loop() {
    analogWrite(redPin, 50); 
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 80); 
    delay(1000);    
}
 
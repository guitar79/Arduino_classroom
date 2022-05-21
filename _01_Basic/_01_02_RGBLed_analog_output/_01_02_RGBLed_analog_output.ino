int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup(){
    pinMode(redPin, OUTPUT); 
    pinMode(greenPin, OUTPUT); 
    pinMode(bluePin, OUTPUT); 
}

void loop() {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(500);
    analogWrite(redPin, 64);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(500);
    analogWrite(redPin, 128);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(500);
    analogWrite(redPin, 256);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(500);
}
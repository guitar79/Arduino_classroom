int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT); 
}
 
void loop() {
//Fading the redLED
    for(int redB=0; redB<255; redB++){
        analogWrite(redPin, redB);
        delay(5);
    }
    for(int redB=255; redB>0; redB--){
        analogWrite(redPin, redB);
        delay(5);
    }
    delay(1000);

//Fading the greenLED
    for(int greenB=0; greenB<255; greenB++){
        analogWrite(greenPin, greenB);
        delay(5);
    }
    for(int greenB=255; greenB>0; greenB--){
        analogWrite(greenPin, greenB);
        delay(5);
    }
    delay(1000);

//Fading the blueLED
    for(int blueB=0; blueB<255; blueB++){
        analogWrite(bluePin, blueB);
        delay(5);
    }
    for(int blueB=255; blueB>0; blueB--){
        analogWrite(bluePin, blueB);
        delay(5);
    }
    delay(1000);
}
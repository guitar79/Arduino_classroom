int redPin = 2;
int greenPin = 3;
int bluePin =42;

void setup(){
    pinMode(redPin, OUTPUT); 
    pinMode(greenPin, OUTPUT); 
    pinMode(bluePin, OUTPUT); 
}
 
void loop(){
    //the LED module lights up in red
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    delay(1000);
}

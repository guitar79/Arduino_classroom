int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup(){
    pinMode(redPin, OUTPUT); 
    pinMode(greenPin, OUTPUT); 
    pinMode(bluePin, OUTPUT); 
}
 
void loop(){
    //the LED module lights up in red
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(1000);
    //lthe LED module lights up in green
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    delay(1000);
    //the LED module lights up in and blue
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(1000);
    //the LED module lights up in red and green
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    delay(1000);
    //the LED module lights up in green and blue
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    delay(1000);
    //the LED module lights up in blue and red
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(1000);
    //the LED module lights up in red, green and blue
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
    delay(2000);
}
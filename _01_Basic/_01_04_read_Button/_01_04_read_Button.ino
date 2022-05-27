int buttonpin = 2;
int LED = 11;

void setup(){
    Serial.begin(9600); 

    pinMode(buttonpin, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    int buttoninput = digitalRead(buttonpin);
    if (buttoninput == LOW) {
        Serial.println("button is not pressed.");
        digitalWrite(LED, LOW);
    }
    else {
        Serial.println("button is pressed.");
        digitalWrite(LED, HIGH);
    }
}

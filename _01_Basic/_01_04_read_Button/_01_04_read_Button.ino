int buttonpin = 4;
int LED = 12;

void setup(){
    Serial.begin(9600); 

    pinMode(buttonpin, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    int buttoninput = digitalRead(buttonpin);
    if (buttoninput == LOW) {
        Serial.println("button is not pressed.");
        pinMode(LED, LOW);
    }
    else {
        Serial.println("button is pressed.");
        pinMode(LED, HIGH);
    }
}
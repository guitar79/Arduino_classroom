<<<<<<< HEAD
int buttonpin = 2;
int LED = 11;
=======
int buttonpin = 4;
int LED = 12;
>>>>>>> 90718fe9bf76f07c8150f59fea708595a6dcda89

void setup(){
    Serial.begin(9600); 

    pinMode(buttonpin, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    int buttoninput = digitalRead(buttonpin);
    if (buttoninput == LOW) {
        Serial.println("button is not pressed.");
<<<<<<< HEAD
        digitalWrite(LED, LOW);
    }
    else {
        Serial.println("button is pressed.");
        digitalWrite(LED, HIGH);
    }
}
=======
        pinMode(LED, LOW);
    }
    else {
        Serial.println("button is pressed.");
        pinMode(LED, HIGH);
    }
}
>>>>>>> 90718fe9bf76f07c8150f59fea708595a6dcda89

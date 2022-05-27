int dataPin = 10;
int latchPin = 11;
int clockPin = 12;
byte dec_digits[] = {
    0b00111111, 0b00000110,
    0b01011011, 0b01001111,
    0b01100110, 0b01101101,
    0b01111100, 0b00000111,
    0b01111111, 0b01100111 
    };

void setup() {
    //set pins to output so you can control the shift register
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

void loop() {
    for (int numberToDisplay = 0; numberToDisplay < 10; numberToDisplay++) {
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, dec_digits[numberToDisplay]); 
        digitalWrite(latchPin, HIGH);
    delay(300);
    }
}
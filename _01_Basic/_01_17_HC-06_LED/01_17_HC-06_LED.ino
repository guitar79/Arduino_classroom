#include <SoftwareSerial.h>

SoftwareSerial bluetooth(8, 9); // 8¹ø TX, 9¹ø RX
int R_pin = 8;
int G_pin = 6;

void setup() {
    Serial.begin(9600);
    bluetooth.begin(9600);

    pinMode(R_pin, OUTPUT); // LED OUTPUT
    pinMode(G_pin, OUTPUT); // LED OUTPUT
}

void loop() {
    char val = bluetooth.read();

    if (bluetooth.available()){
        Serial.write(bluetooth.read());
    }

    if(val == 'r') {
        digitalWrite(R_pin,HIGH);
    }

    if(val == 'g') {
        digitalWrite(G_pin, HIGH);
    }

    else if(val == 'of')
    {
        digitalWrite(R_pin, LOW);
        digitalWrite(G_pin, LOW);
    }
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.print(123);
    Serial.print("Hello world.");
    Serial.print("\n");
    delay(1000);
    Serial.println(456);
    Serial.println("Hi  Everyone.");
    Serial.println("\"\"");
    delay(1000);
}

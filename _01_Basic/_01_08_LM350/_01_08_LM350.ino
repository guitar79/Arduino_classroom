int potPin = A0; //Set analog interface #0 accessed to LM350

void setup() {
    Serial.begin(9600);//Set baud rate as 9600
}

void loop() {
    int val;//
    int dat;//define variable
    val=analogRead(potPin);// read the analog value and assign to val
    dat = (125*val) >> 8;//temperature calculation formula
    Serial.print("Temperature: ");
    Serial.print(dat);//output dat value
    Serial.println(" C");//output character string C
    delay(500);//delay 0.5 s
}

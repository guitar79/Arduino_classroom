int potPin = A0;  //set analog interface #0 to connect photocell

int lightValue = 0;
void setup(){
    Serial.begin(9600);
}
void loop(){
    lightValue = analogRead(potPin);
    Serial.print("light Value: ");
    Serial.println(lightValue);
    Serial.println(" ");
    delay(100);
}
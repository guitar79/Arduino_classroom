int xpin = A0;
int ypin = A1;
int buttonpin = 2;

void setup() {
   Serial.begin(9600);
   pinMode(buttonpin, INPUT);
}
void loop() {
   int xval = analogRead(xpin);
   int yval = analogRead(ypin);
   int buttonpressed = digitalRead(buttonpin);

   Serial.print(xval);
   Serial.print("   ");
   Serial.print(yval);
   Serial.print("   ");
   Serial.println(buttonpressed);
}

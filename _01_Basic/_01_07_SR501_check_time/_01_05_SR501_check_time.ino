int ir_pin = 8 ; 
int led = 13; 

unsigned long startTime;
unsigned long elapsedTime;

void setup() {
    pinMode(ir_pin, INPUT); //Declaramos pines E/S
    pinMode(led, OUTPUT); 
    Serial.begin(9600); //Configuramos la velocidad del monitor serial
}
 
void loop(){
    Serial.print("Sensor status: ");
    Serial.println(digitalRead(ir_pin));
    if (digitalRead(ir_pin) == HIGH) { 
        elapsedTime = millis() - startTime; // How long did that take?
        Serial.print("Elapsed time(in milliseconds): ");
        Serial.println(elapsedTime);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
    } else {
        startTime = millis(); // Note when the button was pushed
    }
}
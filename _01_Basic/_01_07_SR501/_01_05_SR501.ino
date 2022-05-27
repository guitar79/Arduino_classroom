int ir_pin = 8 ; 
int led = 13; 
 
void setup() {
    pinMode(ir_pin, INPUT); //센서 핀 번호
    pinMode(led, OUTPUT);   //빌트인 LED
    Serial.begin(9600);  //시리얼 통신 시작
}
 
void loop(){
    Serial.print("Sensor status: ");
    Serial.println(digitalRead(ir_pin));
    if (digitalRead(ir_pin) == HIGH) { 
        Serial.println("motion detected");
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
    } 
}
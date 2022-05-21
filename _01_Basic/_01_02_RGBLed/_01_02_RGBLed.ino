
int R_pin = 10 ; 
int G_pin = 9 ; 
int B_pin = 8 ; 

void setup(){
    pinMode(R_pin, OUTPUT); 
    pinMode(G_pin, OUTPUT); 
    pinMode(B_pin, OUTPUT); 
}
 
void loop(){
    //the LED module lights up in red
    digitalWrite(R_pin, HIGH);
    digitalWrite(G_pin, LOW);
    digitalWrite(B_pin, LOW);
    delay(1000);
    //lthe LED module lights up in green
    digitalWrite(R_pin, LOW);
    digitalWrite(G_pin, HIGH);
    digitalWrite(B_pin, LOW);
    delay(1000);
    //the LED module lights up in and blue
    digitalWrite(R_pin, LOW);
    digitalWrite(G_pin, LOW);
    digitalWrite(B_pin, HIGH);
    delay(1000);
    //the LED module lights up in red and green
    digitalWrite(R_pin, HIGH);
    digitalWrite(G_pin, HIGH);
    digitalWrite(B_pin, LOW);
    delay(1000);
    //the LED module lights up in green and blue
    digitalWrite(R_pin, LOW);
    digitalWrite(G_pin, HIGH);
    digitalWrite(B_pin, HIGH);
    delay(1000);
    //the LED module lights up in blue and red
    digitalWrite(R_pin, HIGH);
    digitalWrite(G_pin, LOW);
    digitalWrite(B_pin, HIGH);
    delay(1000);
    //the LED module lights up in red, green and blue
    digitalWrite(R_pin, HIGH);
    digitalWrite(G_pin, HIGH);
    digitalWrite(B_pin, HIGH);
    delay(2000);
}
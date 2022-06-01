#define LEDR 6
int i=0;
int a=1;

void setup() {
pinMode(LEDR, OUTPUT);
}
void loop() {
    analogWrite(LEDR, i);
    i=i+a;
    if(i==0||i==255){
      a=-a;
    }
    delay(30);
}
//  delay(1000);
//  digitalWrite(12, 1) ;   digitalWrite(13, 0) ;   digitalWrite(11, 0) ;   digitalWrite(10, 1) ; 
//  delay(1000);
//  digitalWrite(12, 1) ;   digitalWrite(13, 1) ;   digitalWrite(11, 0) ;   digitalWrite(10, 0) ; 
//  delay(1000);
//  digitalWrite(12, 1) ;   digitalWrite(13, 0) ;   digitalWrite(11, 1) ;   digitalWrite(10, 0) ; 
//  delay(1000);
//  digitalWrite(12, 1) ;   digitalWrite(13, 0) ;   digitalWrite(11, 0) ;   digitalWrite(10, 0) ; 
//  delay(1000);

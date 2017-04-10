#define LEDR 6
#define BTN 7
int val=0;
//int i=0;
//int a=1;

void setup() {
pinMode(LEDR, OUTPUT);
pinMode(BTN, INPUT);
}
void loop() {
  val=digitalRead(BTN);
    if(val==1){
      digitalWrite(LEDR, 0);
    }
    else{
      digitalWrite(LEDR, 1);
    }
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

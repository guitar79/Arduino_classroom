#include <Stepper.h>
const int stepsPerRevolution = 2000;  // change this to fit the number of steps per revolution

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(11, 1);
pinMode(12, 1);
pinMode(13, 1);
}

void loop() {
while(!Serial.available()); //시리얼로 데이터 들어올 때까지 대기
char com = Serial.read(); //들어온 데이터를 변수 com에 저장
Serial.print(com);
switch(com) {
   case 'q':
   digitalWrite(12, 1) ; 
   delay(50);
   break;
   case 'w':
   digitalWrite(12, 0) ; 
   delay(50);
   break;
   case 'a':
   digitalWrite(13, 1) ; 
   delay(50);
   break;
   case 's':
   digitalWrite(13, 0) ; 
   delay(50);
   break;
   case 'z':
   for (int i=1; i <= 10000; i++){
      digitalWrite(11, 1) , digitalWrite(11, 0) ; 
   delay(1);
   
}
}
}



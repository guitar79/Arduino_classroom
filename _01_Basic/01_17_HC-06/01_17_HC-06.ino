/*
<<<<<<< HEAD
스마트폰과 블루투스 모듈과의 통신을 통한 문자열 전송
 https://deneb21.tistory.com/267
*/
#include <SoftwareSerial.h>
//시리얼통신?라이브러리?호출?
int blueTx=2; //Tx (보내는핀?설정)
int blueRx=3; //Rx (받는핀?설정)

SoftwareSerial mySerial(blueTx, blueRx); //시리얼?통신을?위한?객체선언?
void setup() {
  Serial.begin(9600); //시리얼모니터?
  mySerial.begin(9600); //블루투스?시리얼
=======
 https://deneb21.tistory.com/267
*/
#include <SoftwareSerial.h>

int blueTx=2; //Tx
int blueRx=3; //Rx

SoftwareSerial mySerial(blueTx, blueRx); 
void setup() {
  Serial.begin(9600); 
  mySerial.begin(9600); 
>>>>>>> 18a0d5e (add)
}

void loop(){
    if (mySerial.available()) {
<<<<<<< HEAD
        Serial.write(mySerial.read());  //블루투스측?내용을?시리얼모니터에?출력
        }
    if (Serial.available()) {
        mySerial.write(Serial.read());  //시리얼?모니터?내용을?블루추스?측에?WRITE
=======
        Serial.write(mySerial.read());  
        }
    if (Serial.available()) {
        mySerial.write(Serial.read()); 
>>>>>>> 18a0d5e (add)
        }
}
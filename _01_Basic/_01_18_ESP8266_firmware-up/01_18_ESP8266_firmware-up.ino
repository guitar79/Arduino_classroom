/*
https://m.blog.naver.com/eduino/221152914869
*/
#include <SoftwareSerial.h>
//�ø������?���̺귯��?ȣ��?
int blueTx=2; //Tx (��������?����)
int blueRx=3; //Rx (�޴���?����)

SoftwareSerial mySerial(blueTx, blueRx); //�ø���?�����?����?��ü����?
void setup() {
  Serial.begin(9600); //�ø�������?
  mySerial.begin(9600); //�������?�ø���
}

void loop(){
    if (mySerial.available()) {
        Serial.write(mySerial.read());  //���������?������?�ø������Ϳ�?���
        }
    if (Serial.available()) {
        mySerial.write(Serial.read());  //�ø���?�����?������?����߽�?����?WRITE
        }
}
/*
<<<<<<< HEAD
����Ʈ���� ������� ������ ����� ���� ���ڿ� ����
 https://deneb21.tistory.com/267
*/
#include <SoftwareSerial.h>
//�ø������?���̺귯��?ȣ��?
int blueTx=2; //Tx (��������?����)
int blueRx=3; //Rx (�޴���?����)

SoftwareSerial mySerial(blueTx, blueRx); //�ø���?�����?����?��ü����?
void setup() {
  Serial.begin(9600); //�ø�������?
  mySerial.begin(9600); //�������?�ø���
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
        Serial.write(mySerial.read());  //���������?������?�ø������Ϳ�?���
        }
    if (Serial.available()) {
        mySerial.write(Serial.read());  //�ø���?�����?������?����߽�?����?WRITE
=======
        Serial.write(mySerial.read());  
        }
    if (Serial.available()) {
        mySerial.write(Serial.read()); 
>>>>>>> 18a0d5e (add)
        }
}
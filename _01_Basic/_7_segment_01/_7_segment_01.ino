#include <DHT11.h>
int pin=2;    // 연결한 아두이노 디지털 핀 번호
DHT11 dht11(pin); 
//캐소드 공통의 7 세그먼트 사용
byte digits[10][7] = 
{
   {1,1,1,1,1,1,0}, //0
   {0,1,1,0,0,0,0}, //1
   {1,1,0,1,1,0,1}, //2
   {1,1,1,1,0,0,1}, //3
   {0,1,1,0,0,1,1}, //4
   {1,0,1,1,0,1,1}, //5
   {1,0,1,1,1,1,1}, //6
   {1,1,1,0,0,1,0}, //7
   {1,1,1,1,1,1,1}, //8
   {1,1,1,1,0,1,1}  //9
};
/*   {0,0,0,0,0,0,1}, //0
//   {0,0,0,0,0,1,1}, //1
//   {0,0,0,0,1,1,1}, //2
//   {0,0,0,1,1,1,1}, //3
//   {0,0,1,1,1,1,1}, //4
//   {0,1,1,1,1,1,1}, //5
//   {1,1,1,1,1,1,1}, //6
*/
void setup() {
  for(int i=3;i<11;i++){
    pinMode(i, OUTPUT);
  }
  digitalWrite(10,HIGH);
}
void loop() {
for (int i=0;i<10;i++){
 delay(1000);
 displayDigit(4);
 //displayDigit(i);
}
}

void displayDigit(int num){
  int pin = 3;
  for(int i=0;i<7;i++){
    digitalWrite(pin+i, digits[num][i]);
  }
}

/*
{
  int err;
  float temp = 0.0, humi = 0.0;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print("C, ");
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println("% " );
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
}
*/

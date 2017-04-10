#include <SoftwareSerial.h>
#include <DHT11.h>
int pin=8;    // 연결한 아두이노 디지털 핀 번호
DHT11 dht11(pin); 
int blueTx=2;
int blueRx=3;
SoftwareSerial mySerial(blueTx, blueRx);
String myString="";
  
void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
  int err;
  float temp = 0.0, humi = 0.0;
  if((err=dht11.read(humi, temp))==0)
  
  while(mySerial.available())
  { 
    mySerial.print("temperature:");
    mySerial.print(temp);
    mySerial.print("C, ");
    mySerial.print(" humidity:");
    mySerial.print(humi);
    mySerial.println("% " );
  }
  else
  {
    mySerial.println();
    mySerial.print("Error No :");
    mySerial.print(err);
    mySerial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
}




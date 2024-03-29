#include <DHT11.h>
int pin=2;    // 연결한 아두이노 디지털 핀 번호
DHT11 dht11(pin); 
void setup()
{
   Serial.begin(9600);
}
 
void loop()
{
  int err;
  float temp = 0.0, humi = 0.0;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print("C, ");
    int Temp10=temp/10;
    Serial.print(Temp10);
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

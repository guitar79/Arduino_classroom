/*
https://devicemart.blogspot.com/2019/12/gp2y1010au0f.html
미세 먼지 센서 값 출력
http://www.devicemart.co.kr/
*/

// 미세 먼지 없을 때 초기 V 값 0.35
// 공기청정기 위 등에서 먼지를 가라앉힌 후 voltage값 개별적으로 측정 필요
#define no_dust 0.35

// 아두이노 - 미세 먼지 센서 연결
int dustout=A0;
int v_led=13;
float vo_value=0;    // 센서로 읽은 값 변수 선언
float sensor_voltage=0;  // 센서로 읽은 값을 전압으로 측정 변수
float dust_density=0;  // 실제 미세 먼지 밀도 변수

void csvPM251()
  {
   vo_value=analogRead(dustout); // 데이터를 읽음
   sensor_voltage=get_voltage(vo_value);
   dust_density=get_dust_density(sensor_voltage);
   Serial.print(dust_density);  //" [ug/m^3]")
  }


String strPM25() {
  String PM25String ; 
  vo_value=analogRead(dustout); // 데이터를 읽음
  sensor_voltage = get_voltage(vo_value);
  dust_density=get_dust_density(sensor_voltage);
  PM25String = "";
  PM25String += String(sensor_voltage);
  PM25String += ",";
  PM25String += String(dust_density);  //" [ug/m^3]")
  return PM25String ;
}


void printPM25()
  {
   sensor_voltage=get_voltage(vo_value);
   dust_density=get_dust_density(sensor_voltage);
  
    Serial.print("value = ");
    Serial.println(vo_value);
    Serial.print("Voltage = ");
    Serial.print(sensor_voltage);
    Serial.println(" [V]");
    Serial.print("Dust Density = ");
    Serial.print(dust_density);
    Serial.println(" [ug/m^3]");\
  }

float get_voltage(float value)
  {
   // 아날로그 값을 전압 값으로 바꿈
   float V= value * 5.0 / 1024; 
   return V;
  }

float get_dust_density(float voltage)
  {
   // 데이터 시트에 있는 미세 먼지 농도(ug) 공식 기준
   float dust=(voltage-no_dust) / 0.005;
   return dust;
  }

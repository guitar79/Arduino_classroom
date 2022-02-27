//https://forum.arduino.cc/t/how-to-set-an-alarm-with-the-ds1302-real-time-clock/594882
//https://m.blog.naver.com/chandong83/221451714944


#define cipherkey 0xA831


#include <EEPROM.h>
int eep_addr_firmwareStr = 0;
String firmwareStr = "arduino AMS by Kevin";

int eep_addr_firmwareVer = 64;
#define firmver "1.04"

int eep_addr_focusStep = 128;
String versionStr = "arduino AMS by Kevin";

unsigned long stepnow = 50000; //256
unsigned long desiredstep = 50000;
bool savepos = 1; //10

int eep_addr_srno = 74;
int eep_addr_srno_chksum = 84;



#include <ThreeWire.h>  
#include <RtcDS1302.h>

//ThreeWire myWire(4,5,2); // IO, SCLK, CE
ThreeWire myWire(3,2,4); // IO, SCLK, RST
//RTC 라이브러리 생성
RtcDS1302<ThreeWire> Rtc(myWire);

// for the temperature and hubmidity sensor
 #include <DHT.h>
 #define DHT22_PIN 2
 #define DHTTYPE DHT22
 DHT dht(DHT22_PIN, DHTTYPE);
 int chkSensor;
 String Temperature;
 String Humidity;

  
void setup () 
  {
    Serial.begin(9600);

    //EEPROM
    //writeStringToEEPROM(0, versionStr);
    //startEEPROMsetup();
        
    //컴파일 시점의 날짜(__DATE__)와 시간(__TIME__)을 시리얼모니터에 표시
    Serial.print("compiled: ");
    Serial.print(__DATE__);
    Serial.print(" ");
    Serial.println(__TIME__);

    //RTC 모듈 라이브러리 시작
    Rtc.Begin();
    //RTC 시간을 설정 컴파일된 날짜로
    setTRTCDateTime();
  }

void loop () 
  {
    //RTC 모듈의 현재 시간 얻기
    RtcDateTime now = Rtc.GetDateTime();
    //시리얼 모니터에 시간 출력
    printDateTime(now);
    Serial.print(",");

    actionBykey();
  }

void actionBykey() 
  {  
  while(!Serial.available()); //시리얼로 데이터 들어올 때까지 대기
  char com = Serial.read(); //들어온 데이터를 변수 com에 저장
  switch(com) 
    {
      case 'q':
      Serial.println(com);
      break;
      
      case 'a':
      Serial.println(com);
      break;
       
      case 'w':
      Serial.println(com);
      break;
      
      case 's':
      Serial.println(com);
      break;
    }
  }

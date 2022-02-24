//https://www.arduino.cc/en/Tutorial/LibraryExamples/Datalogger


#include <EEPROM.h>
String versionSrt = "arduino DLS by Kevin";

/*
#include <ThreeWire.h>  
#include <RtcDS1302.h>
//ThreeWire myWire(4,5,2); // IO, SCLK, CE
//ThreeWire myWire(3,2,4); // IO, SCLK, RST
//ThreeWire myWire(7,A5,5); // IO, SCLK, RST
//RTC 라이브러리 생성
RtcDS1302<ThreeWire> Rtc(myWire);
*/

/* RTC 모듈에 PC를 이용하여 현재의 일시를 동기화 하기 */
#include <RTClib.h> // RTC 기본 라이브러리
#include <Wire.h>   // i2c 통신 라이브러리

//RTC_DS1307 RTC;    // RTC클래스 생성
DS1307 RTC;    // RTC클래스 생성


#include <SPI.h>
#include <SD.h>

const int chipSelect = 8;


/*
미세 먼지 센서 값 출력
http://www.devicemart.co.kr/
*/

// 미세 먼지 없을 때 초기 V 값 0.35
// 공기청정기 위 등에서 먼지를 가라앉힌 후 voltage값 개별적으로 측정 필요
#define no_dust 0.35
// 아두이노 - 미세 먼지 센서 연결
int dustout=A0;
int v_led=13;
// 센서로 읽은 값 변수 선언
float vo_value=0;
// 센서로 읽은 값을 전압으로 측정 변수
float sensor_voltage=0;
// 실제 미세 먼지 밀도 변수
float dust_density=0;


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
    while (!Serial);
      Serial.print("Initializing SD card...");
      if (!SD.begin(chipSelect)) 
        {
          Serial.println("initialization failed. Things to check:");
          Serial.println("1. is a card inserted?");
          Serial.println("2. is your wiring correct?");
          Serial.println("3. did you change the chipSelect pin to match your shield or module?");
          Serial.println("Note: press reset or reopen this serial monitor after fixing your issue!");
          while (true);
        }
    
    Serial.println("initialization done.");
  }


void loop() 
  {

    // make a string for assembling the data to log:
    String dataString = "";
  
    // read three sensors and append to the string:
    for (int analogPin = 0; analogPin < 3; analogPin++) 
      {
        int sensor = analogRead(analogPin);
        dataString += String(sensor);
        if (analogPin < 2) 
          {
            dataString += ",";
          }

      }

      // open the file. note that only one file can be open at a time,
      // so you have to close this one before opening another.

    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    
    // if the file is available, write to it:
    if (dataFile) 
      {
        dataFile.println(dataString);
        dataFile.close();
    
        // print to the serial port too:
        Serial.println(dataString);
      }

    // if the file isn't open, pop up an error:
    else 
      {
        Serial.println("error opening datalog.txt");
      }
  }

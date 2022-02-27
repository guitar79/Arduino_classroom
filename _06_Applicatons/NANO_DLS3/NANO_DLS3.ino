//https://www.arduino.cc/en/Tutorial/LibraryExamples/Datalogger

#include <EEPROM.h>
String versionSrt = "arduino DLS by Kevin";

#include <Wire.h>   // i2c 통신 라이브러리
#include <RTClib.h> // RTC 기본 라이브러리
//RTC_DS1307 RTC;    // RTC클래스 생성
DS1307 RTC;    // RTC클래스 생성
#define DS1307_I2C_ADDRESS 0x68
char TmeStrng[] = "0000/00/00,00:00:00";     //19 ascii characters 

#include <SPI.h>
#include <SdFat.h>

SdFat SD;
#define MOSIpin 11
#define MISOpin 12
const int chipSelect = 8; 

//String datalog_fname = "datalog1.txt";
char datalog_fname[] = "datalog1.txt";

// for the temperature and hubmidity sensor
 #include <DHT.h>
 #define DHT22_PIN 2
 #define DHTTYPE DHT22
 DHT dht(DHT22_PIN, DHTTYPE);
 
void setup () {
  pinMode(10, OUTPUT);
  Serial.begin(9600);
  Wire.begin();                        // start the i2c interface
  RTC.begin();                         // start the RTC 
  RTC.adjust(DateTime((__DATE__), (__TIME__)));

  while (!Serial);
  Serial.println("Finding SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("1. is a card inserted?");
    Serial.println("2. is your wiring correct?");
    Serial.println("3. did you change the chipSelect pin to match your shield or module?");
    Serial.println("Note: press reset or reopen this serial monitor after fixing your issue!");
    while (true);
    return;
  }
  else {
    Serial.println("ooooooo SD card OK ooooooo");   
   
    File dataFile = SD.open(datalog_fname, FILE_WRITE);
    if (dataFile) {                     // if the file is available, write to it:
      dataFile.println("NANO Logger");
      dataFile.close();
    }
    else {
      Serial.println("xxxxxxxx file error xxxxxxxx");     // if the file is not open, pop up an error:
    }
  }
}


void loop() {
  //prtSerialRTCDateTime();
  //Serial.println("");

    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    String DT = strRTCDateTime();
    String humitemp = strTempHumi();
    String PM25 = strPM25();
 
    File dataFile = SD.open(datalog_fname, FILE_WRITE);
    // if the file is available, write to it:    
    if (dataFile) 
      {
        dataFile.print(DT);
        dataFile.print(humitemp);
        dataFile.println(PM25);
        dataFile.println("");
        dataFile.close();
    
        // print to the serial port too:
        Serial.print(DT);
        Serial.print(humitemp);
        Serial.print(PM25);
        Serial.println("");
      }

    // if the file isn't open, pop up an error:
    else 
      {
        Serial.print("error opening ");
        Serial.println(datalog_fname);
      }
   delay(10000); 
  }

/* Based on Ed Mallon's simplified version of his Cave Pearl Logger sketch.
C. Fastie simplified it more (e.g., removed LED blinks) and replaced SD library with SdFat, 
added support for BMP280 or BME280 sensors, 
added seconds to the time string, added utc time to the data file,
shortened error messages to save memory.
*/
<<<<<<< HEAD
#include <SdFat.h>
=======
#include <SdFat.h>  //SdFat by Bill Greiman <fat16lib@sbcglobal.net> Version 2.1.2 INSTALLED
>>>>>>> 18a0d5e (add)
SdFat SD;
#include  <SPI.h>
const int chipSelect = 10;    //CS moved to pin 10 on the arduino
#include <Wire.h>
#include "LowPower.h"     // from https://github.com/rocketscream/Low-Power
#include <RTClib.h>       // library from   https://github.com/MrAlvin/RTClib
<<<<<<< HEAD
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
//#include <Adafruit_BME280.h>
=======
#include <Adafruit_Sensor.h>   
//#include <Adafruit_BMP280.h>  //Adafruit BMP280 Library by Adafruit Version 2.6.2 INSTALLED
>>>>>>> 18a0d5e (add)
#define DS3231_I2C_ADDRESS 0x68
#define MOSIpin 11
#define MISOpin 12
RTC_DS3231 RTC;
<<<<<<< HEAD
=======

>>>>>>> 18a0d5e (add)
int RTC_INTERRUPT_PIN = 2; 
byte Alarmhour;
byte Alarmminute;
byte Alarmday;
char TmeStrng[ ] = "0000/00/00,00:00:00"; //16 ascii characters (without seconds) [clf added seconds]
#define SampleIntervalMinutes 5
volatile boolean clockInterrupt = false;  //this flag is set to true when the RTC interrupt handler is executed
float hgInches = 29.99;                   // Enter the sealevel barometric pressure here (xx.xx inches Hg)
#define SEALEVELPRESSURE_HPA (hgInches/0.02952998751)      // hPa=(inches Hg)/0.02952998751
<<<<<<< HEAD
Adafruit_BMP280 bme;                      // The BMP280 will be an I2C device
=======
>>>>>>> 18a0d5e (add)
//Adafruit_BME280 bme;                    // The BME280 will be an I2C device
//variables for reading the DS3231 RTC temperature register
float temp3231;
byte tMSB = 0;
byte tLSB = 0;

void setup() {
<<<<<<< HEAD
  // Setting the SPI pins high helps some sd cards go into sleep mode 
  // the following pullup resistors only need to be enabled for the stand alone logger builds - not the UNO loggers
  pinMode(chipSelect, OUTPUT); digitalWrite(chipSelect, HIGH); //Always pullup the CS pin with the SD library
  //and you may need to pullup MOSI/MISO
  //  pinMode(MOSIpin, OUTPUT); digitalWrite(MOSIpin, HIGH);   //pullup the MOSI pin
  //  pinMode(MISOpin, INPUT); digitalWrite(MISOpin, HIGH);    //pullup the MISO pin
  delay(1);
  
  Serial.begin(9600);    // Open serial communications and wait for port to open:
  Wire.begin();          // start the i2c interface for the RTC
  RTC.begin();           // start the RTC
  
// RTC.adjust(DateTime((__DATE__), (__TIME__)));         //sets the RTC to the computer time.
 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Finding SD card  ");
// see if the card is present and can be initialized
  if (!SD.begin(chipSelect)) {
    Serial.println("No card");
    // don�셳 do anything more:
    return;
  }
  Serial.println("card OK");  
  // You must already have a plain text file file named �쁡atalog.txt�� on the SD already for this to work!(not true?)
  //�붴�붴�붴��-print a header to the data file�붴�붴��-
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {          // if the file is available, write to it:
    dataFile.println("First cave pearl, ");
    dataFile.close();
  }
  else {
    Serial.println("file error1"); // if the file isn�셳 open, pop up an error:
  }
    bool status;    
    status = bme.begin(0x76);
    if (!status) {
        Serial.println("No BMP280");
        while (1);
=======
    // Setting the SPI pins high helps some sd cards go into sleep mode 
    // the following pullup resistors only need to be enabled for the stand alone logger builds - not the UNO loggers
    pinMode(chipSelect, OUTPUT); digitalWrite(chipSelect, HIGH); 
    // Always pullup the CS pin with the SD library
    // and you may need to pullup MOSI/MISO
    //  pinMode(MOSIpin, OUTPUT); digitalWrite(MOSIpin, HIGH);   //pullup the MOSI pin
    //  pinMode(MISOpin, INPUT); digitalWrite(MISOpin, HIGH);    //pullup the MISO pin
    delay(1000);
    
    Serial.begin(9600);    // Open serial communications and wait for port to open:
    Wire.begin();          // start the i2c interface for the RTC
    RTC.begin();           // start the RTC
    RTC.adjust(DateTime((__DATE__), (__TIME__)));         //sets the RTC to the computer time.
 
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
  
    Serial.print("Finding SD card : ");
    // see if the card is present and can be initialized

    if (!SD.begin(chipSelect)) {
        Serial.println("No card");
        // anything more:
        delay(3000);
        return;
    }
    
    Serial.println("card OK");  
    delay(3000);
    
    // You must already have a plain text file file named datalog.txt on the SD already for this to work!(not true?)
    //�붴�붴�붴��-print a header to the data file�붴�붴��-
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {          // if the file is available, write to it:
        dataFile.println("Data logging started... ");
        dataFile.close(); 
        Serial.println("datalog.txt file is ready..."); // if the file isn�셳 open, pop up an error:
    } else {
        Serial.println("error with datalog.txt..."); // if the file isn�셳 open, pop up an error:
    }
    //bool status;    
    //status = bme.begin(0x76);
    //if (!status) {
    //   Serial.println("No BMP280");
    //   while (1);
>>>>>>> 18a0d5e (add)
    }
}                                                 // end of setup

void loop() {
<<<<<<< HEAD
  //�붴�밫his part reads the time and disables the RTC alarm
  DateTime now = RTC.now(); //this reads the time from the RTC
  sprintf(TmeStrng, "%04d/%02d/%02d,%02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second()); // [added seconds]
  //loads the time into a string variable
  //the interrupt to time reading interval is <1s, so seconds are always ��00��
  
  // We set the clockInterrupt in the ISR, deal with that now:
  if (clockInterrupt) {
    if (RTC.checkIfAlarm(1)) {       //Is the RTC alarm still on?
      RTC.turnOffAlarm(1);              //then turn it off.
    }
    //print (optional) debugging message to the serial window if you wish
    Serial.print("RTC Alarm on INT-0 triggered at ");
    Serial.println(TmeStrng);
    Serial.print("RTC utc Time: ");
    Serial.print(now.unixtime());
    Serial.println();
    clockInterrupt = false;                //reset the interrupt flag to false
  }
  // read the RTC temp register and print that out
  // Note: the DS3231 temp registers (11h-12h) are only updated every 64seconds
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x11);                     //the register where the temp data is stored
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 2);   //ask for two bytes of data
  if (Wire.available()) {
  tMSB = Wire.read();             //2�셲 complement int portion
  tLSB = Wire.read();             //fraction portion
  temp3231 = ((((short)tMSB << 8) | (short)tLSB) >> 6) / 4.0;  // Allows for readings below freezing: thanks to Coding Badly
  temp3231 = (temp3231 * 1.8) + 32.0; // To Convert Celcius to Fahrenheit
}
else {
  temp3231 = 0;  //if temp3231 contains zero, there was a problem reading from the RTC
}
   float BMEt = (bme.readTemperature());
//   float BMEh = (bme.readHumidity());           // only the BME280 has humidity, not the BMP280
   float BMEp = (bme.readPressure() / 100.0F);
   float BMEslp = (bme.readAltitude(SEALEVELPRESSURE_HPA));
   Serial.print("RTC temp: ");
   Serial.print(temp3231);
   Serial.println(" F");
   Serial.print("BMP280 temp: ");
   Serial.print(BMEt);
   Serial.println(" C");
//   Serial.print(BMEh);                         // only the BME280 has humidity, not the BMP280
//   Serial.println(" %");                       // only the BME280 has humidity, not the BMP280
   Serial.print("Pressure = ");
   Serial.print(BMEp);
   Serial.println(" hPa");
   Serial.print("Elevation: ");
   Serial.print(BMEslp);
   Serial.println(" m");
//�붴�붴�� concatenate data into a string �붴�붴��-
   String dataString = "";                  //start with a new empty string
   dataString += TmeStrng;
   dataString += ",";                       //puts a comma between two strings of data
   dataString += String(now.unixtime());
   dataString += ","; 
   dataString += String(temp3231);
   dataString += ",";   
   dataString += String(BMEt);
   dataString += ",";     
//dataString += String(BMEh);            // only the BME280 has humidity, not the BMP280
//dataString += ",";     
   dataString += String(BMEp);
   dataString += ",";     
   dataString += String(BMEslp);

//�붴�붴�� Now write the data to the SD card �붴�붴��
File dataFile = SD.open("datalog.txt", FILE_WRITE);    // if the file is available, write to it:
if (dataFile) {
  dataFile.println(dataString);
  dataFile.close();
}
else {
  Serial.println("file error");                        // if the file isn�셳 open, pop up an error:
}
//�붴�붴�� Set the next alarm time �붴�붴�붴�붴��
Alarmhour = now.hour();
Alarmminute = now.minute() + SampleIntervalMinutes;
Alarmday = now.day();
=======
    //This part reads the time and disables the RTC alarm
    DateTime now = RTC.now(); //this reads the time from the RTC
    sprintf(TmeStrng, "%04d/%02d/%02d,%02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second()); // [added seconds]
    //loads the time into a string variable
    //the interrupt to time reading interval is <1s, so seconds are always ��00��
    
    // We set the clockInterrupt in the ISR, deal with that now:
    if (clockInterrupt) {
        if (RTC.checkIfAlarm(1)) {       //Is the RTC alarm still on?
            RTC.turnOffAlarm(1);              //then turn it off.
        }
        //print (optional) debugging message to the serial window if you wish
        Serial.print("RTC Alarm on INT-0 triggered at ");
        Serial.println(TmeStrng);
        Serial.print("RTC utc Time: ");
        Serial.println(now.unixtime());
        
        clockInterrupt = false;                //reset the interrupt flag to false
    }
  
    // read the RTC temp register and print that out
    // Note: the DS3231 temp registers (11h-12h) are only updated every 64seconds
    Wire.beginTransmission(DS3231_I2C_ADDRESS);
    Wire.write(0x11);                     //the register where the temp data is stored
    Wire.endTransmission();
    Wire.requestFrom(DS3231_I2C_ADDRESS, 2);   //ask for two bytes of data
    
    if (Wire.available()) {
        tMSB = Wire.read();             //2�셲 complement int portion
        tLSB = Wire.read();             //fraction portion
        temp3231 = ((((short)tMSB << 8) | (short)tLSB) >> 6) / 4.0;  // Allows for readings below freezing: thanks to Coding Badly
        temp3231 = (temp3231 * 1.8) + 32.0; // To Convert Celcius to Fahrenheit
    } else {
        temp3231 = 0;  //if temp3231 contains zero, there was a problem reading from the RTC
    }
    //float BMEt = (bme.readTemperature());
    //   float BMEh = (bme.readHumidity());           // only the BME280 has humidity, not the BMP280
    // float BMEp = (bme.readPressure() / 100.0F);
    //float BMEslp = (bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.print("RTC temp: ");
    Serial.print(temp3231);
    Serial.println(" F");
    //Serial.print("BMP280 temp: ");
    //Serial.print(BMEt);
    //Serial.println(" C");
    //   Serial.print(BMEh);                         // only the BME280 has humidity, not the BMP280
    //   Serial.println(" %");                       // only the BME280 has humidity, not the BMP280
    //Serial.print("Pressure = ");
    //Serial.print(BMEp);
    //Serial.println(" hPa");
    //Serial.print("Elevation: ");
    //Serial.print(BMEslp);
    //Serial.println(" m");
    //concatenate data into a string -
    String dataString = "";                  //start with a new empty string
    dataString += TmeStrng;
    dataString += ",";                       //puts a comma between two strings of data
    dataString += String(now.unixtime());
    dataString += ","; 
    dataString += String(temp3231);
    dataString += ",";   
    //dataString += String(BMEt);
    //dataString += ",";     
    //dataString += String(BMEh);            // only the BME280 has humidity, not the BMP280
    //dataString += ",";     
    //dataString += String(BMEp);
    //dataString += ",";     
    //dataString += String(BMEslp);

    //Now write the data to the SD card 
    File dataFile = SD.open("datalog.txt", FILE_WRITE);    // if the file is available, write to it:
    if (dataFile) {
        dataFile.println(dataString);
        dataFile.close();
    } else {
        Serial.println("file error");                        // if the file isn�셳 open, pop up an error:
    }
    //�붴�붴�� Set the next alarm time �붴�붴�붴�붴��
    Alarmhour = now.hour();
    Alarmminute = now.minute() + SampleIntervalMinutes;
    Alarmday = now.day();
>>>>>>> 18a0d5e (add)

// check for roll-overs
if (Alarmminute > 59) {                                //error catching the 60 rollover!
  Alarmminute = 0;
  Alarmhour = Alarmhour + 1;
  if (Alarmhour > 23) {
    Alarmhour = 0;
    // put ONCE-PER-DAY code here -it will execute on the 24 hour rollover
  }
}
      //  set the alarm
RTC.setAlarm1Simple(Alarmhour, Alarmminute);
RTC.turnOnAlarm(1);
if (RTC.checkAlarmEnabled(1)) {
  //you would comment out most of this message printing
  //if your logger was actually being deployed in the field
  Serial.print("RTC Alarm On: ");
  Serial.print("Sleeping for : ");
  Serial.print(SampleIntervalMinutes);
  Serial.println(" minutes");
  Serial.println();                                      // adds a carriage return
}
// instead of using the delay we use RTC interrupted sleeps
// delay(5000);  
  //�붴�붴�� sleep and wait for next RTC alarm �붴�붴�붴�붴��
  // Enable interrupt on pin2 & attach it to rtcISR function:
  attachInterrupt(0, rtcISR, LOW);
  // Enter power down state with ADC module disabled to save power:
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_ON);
  //processor starts HERE AFTER THE RTC ALARM WAKES IT UP
  detachInterrupt(0); // immediately disable the interrupt on waking

}                   // END of the MAIN LOOP

  // This is the Interrupt subroutine that only executes when the rtc alarm goes off
void rtcISR() {
    clockInterrupt = true;
  }
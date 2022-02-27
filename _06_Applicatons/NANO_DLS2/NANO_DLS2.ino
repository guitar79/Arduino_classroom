/* Derived from Ed Mallon's starter logging code.
 *  
C. Fastie modified to run without sleeping anything.
added BME280 sensor, added seconds to time readout
added unixtime

//http://kaptery.com/files/documents/nanodataloggerguide.pdf
*/


#include <SdFat.h>
#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>               

SdFat SD;
#define MOSIpin 11
#define MISOpin 12
const int chipSelect = 10; 


//RTC_DS1307 RTC;
DS1307 RTC;

#define DS1307_I2C_ADDRESS 0x68
char TmeStrng[] = "0000/00/00,00:00:00";     //19 ascii characters 

void setup() {  
  Serial.begin(9600);                  // Open serial communications and wait for port to open:
  Wire.begin();                        // start the i2c interface
  RTC.begin();                         // start the RTC 
  RTC.adjust(DateTime((__DATE__), (__TIME__)));    //sets the RTC to the computer time when the sketch is loaded
  
  Serial.println("Finding SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("xxxxxxxx Card failed xxxxxxxx");
    //while(1);
    return;
  }
  else {
    Serial.println("ooooooo SD card OK ooooooo");   
  //â€”â€”â€”â€”-print a header to the data fileâ€”â€”â€”-
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile) {                     // if the file is available, write to it:
      dataFile.println("Nano Logger");
      dataFile.close();
    }
    else {
      Serial.println("xxxxxxxx file error xxxxxxxx");     // if the file isnâ€™t open, pop up an error:
    }
  }

}                                   // end of setup

void loop() {
   
    DateTime now = RTC.now();              //this reads the time from the RTC
    sprintf(TmeStrng, "%04d/%02d/%02d,%02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second()); // [added seconds]

    //Serial.print("RTC utc Time: ");
    //Serial.print(now.unixtime());
    Serial.println();
    Serial.print("RTC time: ");
    Serial.println(TmeStrng);
    
                //Construct a data string to write to ÂµSD card
    String dataString = "";                  //this erases the previous string
    dataString += TmeStrng;
    dataString += ",";    
    dataString += String(now.unixtime());
    dataString += ",";      

    
//â€”â€”â€“ write the data to the SD card â€”â€”â€“
File dataFile = SD.open("datalog.txt", FILE_WRITE);  // if the file is available, write to it:
if (dataFile) {
  dataFile.println(dataString);
  dataFile.close();
}
else {
  Serial.println("xxxxxxxx file error xxxxxxxx");        // if the file isnâ€™t open, pop up an error:
}
 delay(3000);                          // write data every 3 seconds
}             // END of the MAIN LOOP

//https://turtleshell.kr/88
#include <TimeLib.h>
#include <DS1302RTC.h>

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 


#define TIME_MSG_LEN  11   // time sync to PC is HEADER and unix time_t as ten ascii digits
#define TIME_HEADER  255   // Header tag for serial time sync message

//
// Set pins:  CE, IO,CLK
DS1302RTC RTC(4, 3, 2);
//
void setup() {
Serial.begin(9600);
Serial.println("DS1302RTC Read Test");
Serial.println("-------------------");
// clock 정지 체크
if (RTC.haltRTC()) { // 만약 1 이면 정지된 상태
  Serial.println("The DS1302 is stopped.");
  RTC.haltRTC(0);
  Serial.println("The DS1302 is started.");
  delay(100);
} else { // 0 이면 실행 상태
  Serial.println("The DS1302 is working.");
}
// write protected check
if (RTC.writeEN() == 0) {
  Serial.println("The DS1302 is write protected.");
} else {
  Serial.println("The DS1302 can write.");
  RTC.writeEN(false);
  Serial.println("Write protected is started.");
}
//

tmElements_t tm;
//
tm.Year = CalendarYrToTm(2018);
tm.Month = 3;
tm.Day = 20;
tm.Hour = 18;
tm.Minute = 50;
tm.Second = 40;
time_t t = makeTime(tm);
//
if (RTC.set(t) == 0) {
  setTime(t);
}

//
Serial.print(year());
Serial.print("/");
Serial.print(month());
Serial.print("/");
Serial.print(day());
Serial.print(" - ");
Serial.print(hour());
Serial.print(":");
Serial.print(minute());
Serial.print(":");
Serial.println(second());
//
setSyncProvider(RTC.get);
if(timeStatus() == timeSet)
  Serial.println(" Ok!");
else
  Serial.println(" FAIL!");
//

  while (!Serial) ; // Needed for Leonardo only
  pinMode(4, OUTPUT);
  setSyncProvider(requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");
  
}
void loop() {
// put your main code here, to run repeatedly:

if (Serial.available()) {
    processSyncMessage();
//    getPCtime();
  }
  if (timeStatus()!= timeNotSet) {
    serialPRT_time();
  }
  if (timeStatus() == timeSet) {
    digitalWrite(4, HIGH); // LED on if synced
  } else {
    digitalWrite(4, LOW);  // LED off if needs refresh
  }
  
  delay(1000);
  
}

void serialPRT_time() {
    // Start printing elements as individuals
    Serial.print("Current Date / Time: ");
    Serial.print(year());
    Serial.print("/");
    Serial.print(month());
    Serial.print("/");
    Serial.print(day());
    Serial.print(" - ");
    Serial.print(hour());
    Serial.print(":");
    Serial.print(minute());
    Serial.print(":");
    Serial.println(second());
}


void processSyncMessage() {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     if( pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
       setTime(pctime); // Sync Arduino clock to the time received on the serial port
     }
  }
}

time_t requestSync()
{
  Serial.write(TIME_REQUEST);  
  return 0; // the time will be sent later in response to serial mesg
}

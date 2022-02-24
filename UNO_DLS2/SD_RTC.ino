//https://forum.arduino.cc/t/how-to-set-an-alarm-with-the-ds1302-real-time-clock/594882
//https://m.blog.naver.com/chandong83/221451714944

String strRTCDateTime() {
  DateTime now = RTC.now();              //this reads the time from the RTC
  sprintf(TmeStrng, "%04d-%02d-%02d %02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second()); // [added seconds]
return TmeStrng ; 
}

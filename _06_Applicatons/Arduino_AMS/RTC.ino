//https://forum.arduino.cc/t/how-to-set-an-alarm-with-the-ds1302-real-time-clock/594882
//https://m.blog.naver.com/chandong83/221451714944

#define countof(a) (sizeof(a) / sizeof(a[0]))

/*
//시리얼 모니터에 날짜 시간 표시하는 함수
void printDateTime(const RtcDateTime& dt)
{
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    Serial.print(datestring);
}
*/

void prtSerialRTCDateTime()
  {
    DateTime now=RTC.now(); // RTC에 저장된 값을 불러옴
    // 시리얼 모니터창에 아래의 형식으로 출력함
    Serial.print(now.year(), DEC); 
    Serial.print('/'); 
    Serial.print(now.month(), DEC); 
    Serial.print('/'); 
    Serial.print(now.day(), DEC); 
    Serial.print(' '); 
    Serial.print(now.hour(), DEC); 
    Serial.print(':'); 
    Serial.print(now.minute(), DEC); 
    Serial.print(':'); 
    Serial.print(now.second(), DEC); 
    Serial.println(); 
  }

/*
void setTRTCDateTime()
{
//RTCDateTime 클래스 생성(컴파일된 시간으로 설정)
    RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
    printDateTime(compiled);
    Serial.println();
    
    //RTC모듈에 쓰기 금지 모드인지 확인
    if (Rtc.GetIsWriteProtected())
    {
        Serial.println("RTC was write protected, enabling writing now");
        //쓰기 금지 모드이면 해제
        Rtc.SetIsWriteProtected(false);
    }
    
    //RTC 모듈이 동작중이 아니라면
    if (!Rtc.GetIsRunning())
    {
        Serial.println("RTC was not actively running, starting now");
        // 시작해라!!!
        Rtc.SetIsRunning(true);
    }

    // RTC 모듈의 현재 시간 얻기
    RtcDateTime now = Rtc.GetDateTime();

    //RTC 모듈하고 위에 만든 RTC클래스(컴파일된 시간을 가지고 있는)와 비교해서
    //RTC 시간이 더 늦다면.. 
    if (now < compiled) 
    {
        //RTC가 컴파일 시간보다 느려!(시간을 갱신한다.)
        Serial.println("RTC is older than compile time!  (Updating DateTime)");
        //컴파일 시간을 RTC 모듈에 적용
        Rtc.SetDateTime(compiled);
    }
    //RTC 모듈이 컴파일한 시간보다 빠르다면
    else if (now > compiled) 
    {
        //RTC가 컴파일 시간보다 더 새것이다(그치 이래야지!!!)
        Serial.println("RTC is newer than compile time. (this is expected)");
    }
    //RTC와 컴파일한 시간이 같다면.
    else if (now == compiled) 
    {
        //RTC와 컴파일 시간이 같다. (그..그럴이가... 뭐 그래도 오케!)
        Serial.println("RTC is the same as compile time! (not expected but all is fine)");
    }
}
*/

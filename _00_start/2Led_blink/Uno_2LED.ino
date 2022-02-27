int led1 = 12;
int led2 = 13;
void setup()
   {
       pinMode(led1, OUTPUT);  // 12번 핀을 출력(OUTPUT)으로 함
       pinMode(led2, OUTPUT);  // 13번 핀을 출력(OUTPUT)으로 함
   }
void loop()
   {
       digitalWrite(led1, HIGH); // 12번 핀에 5V를 인가함 (HIGH)
       digitalWrite(led2, LOW);  // 13번 핀에 0V를 인가함 (HIGH)
       delay(1000);             // 1초 (1000ms)간 상태를 유지함
       digitalWrite(led1, LOW);  // 12번 핀에 0V를 인가함 (LOW)
       digitalWrite(led2, HIGH);  // 13번 핀에 5V를 인가함 (LOW)
       delay(1000);             // 1초 (1000ms)간 상태를 유지함
   }
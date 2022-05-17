int led = 13;
void setup()
   {
       pinMode(led, OUTPUT);  // 13번 핀을 출력(OUTPUT)으로 함
   }
void loop()
   {
       digitalWrite(led, HIGH); // 13번 핀에 5V를 인가함 (HIGH)
       delay(1000);             // 1초 (1000ms)간 상태를 유지함
       digitalWrite(led, LOW);  // 13번 핀에 0V를 인가함 (LOW)
       delay(1000);             // 1초 (1000ms)간 상태를 유지함
   }
}
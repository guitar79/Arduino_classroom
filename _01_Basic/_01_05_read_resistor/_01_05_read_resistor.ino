int pin = A0; // 아날로그 핀 설정 

void setup() {
    Serial.begin(9600); //시리얼 통신을 시작한다.(기본 통신속도 9600)
}

void loop() {
    int val = analogRead(pin);//아날로그 입력값(A0)를 읽기 위해 analogRead 를 사용하고 
                            //읽어들인 값을 변수 val에 전달한다. 

    Serial.println(val); // 값을 시리얼 모니터에 출력해준다. 
    delay(500);
}
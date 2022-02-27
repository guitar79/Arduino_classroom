int potpin=A0;  //set analog interface #0 to connect photocell
int ledpin=13;
int val=0;  //define variable val
void setup()
{
	pinMode(ledpin,OUTPUT);//set digital interface #11 as output
	Serial.begin(9600);//set baud rate as 9600
}
void loop()
{
	val=analogRead(potpin);//read analog
	Serial.println(val);
	delay(10);//delay 0.01 s
}



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


//캐소드 공통의 7 세그먼트 사용
//A~G = 3~9  H = 10
//아두이노 - 7세그먼트  아래와 같이
//3-4,4-5,5-9,6-7,7-6,8-2,9-1,10-10
byte digits[10][7] = 
{
   {1,1,1,1,1,1,0}, //0
   {0,1,1,0,0,0,0}, //1
   {1,1,0,1,1,0,1}, //2
   {1,1,1,1,0,0,1}, //3
   {0,1,1,0,0,1,1}, //4
   {1,0,1,1,0,1,1}, //5
   {1,0,1,1,1,1,1}, //6
   {1,1,1,0,0,1,0}, //7
   {1,1,1,1,1,1,1}, //8
   {1,1,1,1,0,1,1}  //9
};

void displayDigit(int num){
  int pin = 3;
  for(int i=0;i<7;i++){
    digitalWrite(pin+i, digits[num][i]);
  }
}

void setup() {
     Serial.begin(9600);
  for(int i=3;i<13;i++){
    pinMode(i, OUTPUT);
  }
}
void loop() {
  float temp = 13;
 
      int Temp10=(temp/10);
      int Temp1=temp-Temp10*10;
    for(int te=1;te<1000;te++){
      digitalWrite(11,0);
      digitalWrite(13,1);
      digitalWrite(10,0); //온도는 . 빼고 표시
      displayDigit(Temp10);
      delay(5);
      digitalWrite(11,1);
      digitalWrite(13,0);
      displayDigit(Temp1);
      }
      delay(5);
      for(int i=3;i<13;i++){
        digitalWrite(i, 0);
      }
 
      delay(1000);   

    Serial.print(temp);
    Serial.print("C, ");
    Serial.print(Temp10);
    Serial.print(" ");
    Serial.print(Temp1);
    Serial.println(" ");

  }
 
  


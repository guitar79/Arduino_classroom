#define MOTOR_A_a 3     //모터A의 +출력핀은 3번핀입니다
#define MOTOR_A_b 11    //모터A의 -출력핀은 11번핀입니다
#define MOTOR_B_a 5     //모터B의 +출력핀은 5번핀입니다
#define MOTOR_B_b 6     //모터B의 -출력핀은 6번핀입니다
#define MOTOR_SPEED 150 //모터의 기준속력입니다(0~255)

const int TriggerPin = 2;    //Trig pin
const int EchoPin = 4;    //Echo pin
long Duration = 0;

unsigned char m_a_spd = 0, m_b_spd = 0; //모터의 속력을 저장하는 전역변수
boolean m_a_dir = 0, m_b_dir = 0;       //모터의 방향을 결정하는 전역변수

void setup(){
    Serial.begin(9600);  
    pinMode(TriggerPin,OUTPUT); //Trigger is an output pin
    pinMode(EchoPin,INPUT);     // Echo is an input pin
    pinMode(MOTOR_A_a, OUTPUT);
    pinMode(MOTOR_A_b, OUTPUT);
    pinMode(MOTOR_B_a, OUTPUT);
    pinMode(MOTOR_B_b, OUTPUT);
    }

void loop(){
    digitalWrite(TriggerPin, LOW);                  
    delayMicroseconds(2);
    digitalWrite(TriggerPin, HIGH);  // Trigger pin to HIGH
    delayMicroseconds(10);           // 10us high
    digitalWrite(TriggerPin, LOW);   // Trigger pin to HIGH
    Duration = pulseIn(EchoPin,HIGH);
    long Distance_mm = Distance(Duration);  
    if (Distance_mm > 300) {
        Serial.print("Distance = ");   // Output to serial
        Serial.print(Distance_mm);
        Serial.println(" mm");
        GOfront();
        delay(2000);
        Left();
        delay(500);
        Goback();
        delay(1000);
        Right();
        delay(800);
    } else {
        Serial.print("Distance = ");   // Output to serial
        Serial.print(Distance_mm);
        Serial.println(" mm");
        Stop();
        delay(3000);
        Goback();
        delay(1000);
        Right();
        delay(800);
    }
}

long Distance(long time)
{
    // Calculates the Distance in mm
    // ((time)*(Speed of sound))/ toward and backward of object) * 10
   
    long DistanceCalc; // Calculation variable
    DistanceCalc = ((time /2.9) / 2);  
  // Actual calculation in mm
    //DistanceCalc = time / 74 / 2;        
 // Actual calculation in inches
    return DistanceCalc;                  
 // return calculated value
}

void GOfront() {
    digitalWrite(MOTOR_A_a, LOW);     //모터A+ LOW
    analogWrite(MOTOR_A_b, MOTOR_SPEED);  //모터A-의 속력을 PWM 출력
    digitalWrite(MOTOR_B_a, MOTOR_SPEED);     //모터A+ LOW
    analogWrite(MOTOR_B_b, LOW);  //모터A-의 속력을 PWM 출력
}

void Goback() {
    digitalWrite(MOTOR_A_a, MOTOR_SPEED);     //모터A+ LOW
    analogWrite(MOTOR_A_b, LOW);  //모터A-의 속력을 PWM 출력
    digitalWrite(MOTOR_B_a, LOW);     //모터A+ LOW
    analogWrite(MOTOR_B_b, MOTOR_SPEED);  //모터A-의 속력을 PWM 출력
}

void Stop() {
    digitalWrite(MOTOR_A_a, 0);     //모터A+ LOW
    analogWrite(MOTOR_A_b, 0);  //모터A-의 속력을 PWM 출력
    digitalWrite(MOTOR_B_a, 0);     //모터A+ LOW
    analogWrite(MOTOR_B_b, 0);  //모터A-의 속력을 PWM 출력
}

void Left() {
    digitalWrite(MOTOR_A_a, LOW);     //모터A+ LOW
    analogWrite(MOTOR_A_b, 0);  //모터A-의 속력을 PWM 출력
    digitalWrite(MOTOR_B_a, MOTOR_SPEED);     //모터A+ LOW
    analogWrite(MOTOR_B_b, LOW);  //모터A-의 속력을 PWM 출력
}

void Right() {
    digitalWrite(MOTOR_A_a, LOW);     //모터A+ LOW
    analogWrite(MOTOR_A_b, MOTOR_SPEED);  //모터A-의 속력을 PWM 출력
    digitalWrite(MOTOR_B_a, 0);     //모터A+ LOW
    analogWrite(MOTOR_B_b, LOW);  //모터A-의 속력을 PWM 출력
}

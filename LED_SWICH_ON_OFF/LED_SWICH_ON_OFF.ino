void setup()
{
pinMode(6, INPUT_PULLUP);
pinMode(13, 1);
//pinMode(11, OUTPUT);
//pinMode(10, OUTPUT);
}
void loop() {
  int state;
  state = digitalRead(6);
  digitalWrite(13, state);
  delay(1);
}
//  digitalWrite(12, 1) ;   digitalWrite(13, 0) ;   digitalWrite(11, 0) ;   digitalWrite(10, 1) ; 
//  delay(1000);
//  digitalWrite(12, 1) ;   digitalWrite(13, 1) ;   digitalWrite(11, 0) ;   digitalWrite(10, 0) ; 
//  delay(1000);
//  digitalWrite(12, 1) ;   digitalWrite(13, 0) ;   digitalWrite(11, 1) ;   digitalWrite(10, 0) ; 
//  delay(1000);
//  digitalWrite(12, 1) ;   digitalWrite(13, 0) ;   digitalWrite(11, 0) ;   digitalWrite(10, 0) ; 
//  delay(1000);

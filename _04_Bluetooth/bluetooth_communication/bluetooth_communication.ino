String mystring=" ";
  
void setup(){
  Serial.begin(9600);
}

void loop(){
  int my;
  while(Serial.available())
  {
    my=(int)Serial.read();
    mystring=mystring+my;
    
    delay(100);
  }
  if(!mystring.equals(""))
  {
    Serial.println(mystring);
    mystring="";
  }
}

//  Serial.print(123);
//  Serial.print("Hello world.");
//  Serial.print("\n");
  
//  Serial.println(456);
//  Serial.println("Hi  Everyone.");
//  Serial.println("""");
  
//  delay(1000);



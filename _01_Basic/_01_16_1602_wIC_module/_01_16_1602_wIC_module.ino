#include <LiquidCrystal_I2C.h>
<<<<<<< HEAD
LiquidCrystal_I2C lcd(0x27,16,2);
=======
LiquidCrystal_I2C lcd(0x27, 16, 2);
>>>>>>> 18a0d5e (add)
// LiquidCrystal I2C by Frank de Brabander Version 1.1.2 
// set the LCD address to 0x3F for a 16 chars and 1 line display
// set the LCD address to 0x27 for a 16 chars and 2 line display
   
void setup(){
   lcd.init(); // initialize the lcd
   lcd.backlight();
   lcd.print("GS system");
   delay(1000);
}

void loop() {
   delay(1000);
   lcd.clear();
   lcd.setCursor(0,0);
   delay(1000);
   lcd.print("GSHS");
   lcd.setCursor(0,1);
   delay(1000);
   lcd.print("gs.hs.kr");
   lcd.noCursor();
   lcd.noBlink();
   delay(1000);
<<<<<<< HEAD
}
=======
}
>>>>>>> 18a0d5e (add)

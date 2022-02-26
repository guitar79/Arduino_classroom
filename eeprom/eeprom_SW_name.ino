
#include <EEPROM.h>

// start reading from the first byte (address 0) of the EEPROM
int address = 0;
byte value;

void setup() {
  // initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {

}

void eeprom_read() {
    /*
    * EEPROM Read
    *
    * Reads the value of each byte of the EEPROM and prints it
    * to the computer.
    * This example code is in the public domain.
    */

    // read a byte from the current address of the EEPROM
    value = EEPROM.read(address);

    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();

    /***
    Advance to the next address, when at the end restart at the beginning.

    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
    ***/
    address = address + 1;
    if (address == EEPROM.length()) {
    address = 0;
    }

    /***
    As the EEPROM sizes are powers of two, wrapping (preventing overflow) of an
    EEPROM address is also doable by a bitwise and of the length - 1.

    ++address &= EEPROM.length() - 1;
    ***/

    delay(500);
}


void eeprom_clear() {
    /*
    * EEPROM Clear
    *
    * Sets all of the bytes of the EEPROM to 0.
    * Please see eeprom_iteration for a more in depth
    * look at how to traverse the EEPROM.
    *
    * This example code is in the public domain.
    */
    // initialize the LED pin as an output.
    pinMode(13, OUTPUT);

    /***
    Iterate through each byte of the EEPROM storage.

    Larger AVR processors have larger EEPROM sizes, E.g:
    - Arduno Duemilanove: 512b EEPROM storage.
    - Arduino Uno:        1kb EEPROM storage.
    - Arduino Mega:       4kb EEPROM storage.

    Rather than hard-coding the length, you should use the pre-provided length function.
    This will make your code portable to all AVR processors.
    ***/

    for (int i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, 0);
    }

    // turn the LED on when we're done
    digitalWrite(13, HIGH);
}

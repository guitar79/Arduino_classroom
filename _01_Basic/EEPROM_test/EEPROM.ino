// https://roboticsbackend.com/arduino-write-string-in-eeprom/


void writeSerialNo(unsigned int srno) {
  unsigned int srno_encoded = srno ^ cipherkey;
  unsigned int srno_chksum = (srno<<8 | srno>>8) ^ cipherkey ^ cipherkey ^ cipherkey;
  EEPROMWriteInt(eep_addr_srno, srno_encoded);
  EEPROMWriteInt(eep_addr_srno_chksum, srno_chksum);
}


unsigned int readSerialNo() {
  unsigned int srno = EEPROMReadInt(eep_addr_srno);
  unsigned int srno_chksum = EEPROMReadInt(eep_addr_srno_chksum);
  unsigned int chksum_decoded = srno_chksum ^ cipherkey ^ cipherkey ^ cipherkey;
  chksum_decoded = (chksum_decoded<<8 | chksum_decoded>>8);
  srno = srno ^ cipherkey;
  if (srno != chksum_decoded) {
    Serial.println(F("Mem corrupt"));
    delay(1000);
    return 9999;
  }
  return srno;
}


void EEPROMWriteInt(int p_address, unsigned int p_value) 
  {
    byte lByte = ((p_value >> 0) & 0xFF);
    byte hByte = ((p_value >> 8) & 0xFF);
    
    EEPROM.update(p_address, lByte);
    EEPROM.update(p_address + 1, hByte);
  }



unsigned int EEPROMReadInt(int p_address) 
   {
    byte lByte = EEPROM.read(p_address);
    byte hByte = EEPROM.read(p_address + 1);
    
    return ((lByte << 0) & 0xFF) + ((hByte << 8) & 0xFF00);
  }



void EEPROMWriteLong(int p_address, unsigned long p_value) 
  {
    byte b0 = ((p_value >> 0) & 0xFF);
    byte b1 = ((p_value >> 8) & 0xFF);
    byte b2 = ((p_value >> 16) & 0xFF);
    byte b3 = ((p_value >> 24) & 0xFF);
    
    EEPROM.update(p_address, b0);
    EEPROM.update(p_address + 1, b1);
    EEPROM.update(p_address + 2, b2);
    EEPROM.update(p_address + 3, b3);
  }

unsigned long EEPROMReadLong(int p_address) 
  {
    byte b0 = EEPROM.read(p_address);
    byte b1 = EEPROM.read(p_address + 1);
    byte b2 = EEPROM.read(p_address + 2);
    byte b3 = EEPROM.read(p_address + 3);
    
    return (((unsigned long)b0 << 0) & 0xFF) + (((unsigned long)b1 << 8) & 0xFF00) + (((unsigned long)b2 << 16) & 0xFF0000) + (((unsigned long)b3 << 24) & 0xFF000000);
  }



void startEEPROMsetup() {
  Serial.begin(9600);
  int eepromOffset = 0;
  // Writing
  String str1 = "Today's tutorial:";
  String str2 = "Save String to EEPROM.";
  String str3 = "Thanks for reading!";
  int str1AddrOffset = writeStringToEEPROM(eepromOffset, str1);
  int str2AddrOffset = writeStringToEEPROM(str1AddrOffset, str2);
  writeStringToEEPROM(str2AddrOffset, str3);
  // Reading
  String newStr1;
  String newStr2;
  String newStr3;
  int newStr1AddrOffset = readStringFromEEPROM(eepromOffset, &newStr1);
  int newStr2AddrOffset = readStringFromEEPROM(newStr1AddrOffset, &newStr2);
  readStringFromEEPROM(newStr2AddrOffset, &newStr3);
  
  Serial.println(newStr1);
  Serial.println(newStr2);
  Serial.println(newStr3); 
  delay(2000);
}




int writeStringToEEPROM(int addrOffset, const String &strToWrite)
  {
    byte len = strToWrite.length();
    EEPROM.write(addrOffset, len);
    for (int i = 0; i < len; i++)
    {
      EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
    }
    return addrOffset + 1 + len;
  }
  
int readStringFromEEPROM(int addrOffset, String *strToRead)
  {
    int newStrLen = EEPROM.read(addrOffset);
    char data[newStrLen + 1];
    for (int i = 0; i < newStrLen; i++)
    {
      data[i] = EEPROM.read(addrOffset + 1 + i);
    }
    data[newStrLen] = '\ 0'; // !!! NOTE !!! Remove the space between the slash "/" and "0" (I've added a space because otherwise there is a display bug)
    *strToRead = String(data);
    return addrOffset + 1 + newStrLen;
  }

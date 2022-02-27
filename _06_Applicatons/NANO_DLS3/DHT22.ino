int chkSensor;
String Temperature;
String Humidity;
 
String strTempHumi() {
  String THString;
  chkSensor = digitalRead(DHT22_PIN);
  Temperature = String(dht.readTemperature(),1);
  Humidity = String(dht.readHumidity(),1);
  switch (chkSensor) {
    case 1:
      THString = "" ;
      THString += Temperature ;
      THString += ",";
      THString += Humidity;
      THString += "," ; 
    case 0:
      THString = "Checksum_err,Checksum_err," ; 
    default:
      THString = "Unknown_err,Unknown_err," ;
  }
  return THString ;
}

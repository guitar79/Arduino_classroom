String strTempHumi() {
  String THString;
  int chkSensor = digitalRead(DHT22_PIN);
  String Temperature = String(dht.readTemperature(),1);
  String Humidity = String(dht.readHumidity(),1);
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

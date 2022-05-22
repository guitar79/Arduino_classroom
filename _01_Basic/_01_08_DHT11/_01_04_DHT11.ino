#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11, DHT시리즈중 11을 선택합니다.
#define DHTPIN 2     // DHT11이 연결된 핀
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin(); // dht 라이브러리를 시작합니다.
}

void loop() {
    delay(1000);

    float h = dht.readHumidity();// 습도를 측정합니다.
    float t = dht.readTemperature();// 온도를 측정합니다.

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C ");
}
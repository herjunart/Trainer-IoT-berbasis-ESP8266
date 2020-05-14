#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
char auth[] = "xxxx"; //masukkan kode auth device yang dikirimkan ke email anda
char ssid[] = "xxxx"; //masukkan nama wifi 
char pass[] = "xxxx"; //masukkan password wifi 
#define DHTPIN 16          //ke PIN Wemos D2
#define DHTTYPE DHT11     // DHT 11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
void sendSensor(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Blynk.virtualWrite(V5,"Failed to read from DHT sensor!");
    Blynk.virtualWrite(V6,"Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}
void setup(){
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
}
void loop(){
  Blynk.run();
  timer.run();
}

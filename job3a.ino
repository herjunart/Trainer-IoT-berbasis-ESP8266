#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "xxxx"; //masukkan kode auth device yang dikirimkan ke email anda
char ssid[] = "xxxx"; //masukkan nama wifi 
char pass[] = "xxxx"; //masukkan password wifi
void setup(){
   Blynk.begin(auth, ssid, pass);
}
void loop(){
  Blynk.run();
}

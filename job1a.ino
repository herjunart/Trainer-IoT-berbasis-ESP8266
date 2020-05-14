#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 16     //ke PIN WEMOS D2
#define DHTTYPE DHT11   //untuk tipe DHT 11
LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  lcd.begin();
  dht.begin();
  lcd.setCursor(0,0); lcd.print("Trainer IoT");
  lcd.setCursor(0,1); lcd.print("berbasis ESP8266");
  delay(2000);
}
void loop() {
  delay(2000);
  lcd.clear(); 
  float h = dht.readHumidity(); //membaca tingkat kelembaban
  float t = dht.readTemperature(); //membaca suhu dalam celcius
  if (isnan(h) || isnan(t)) {
    int i;
    lcd.setCursor(1,0);lcd.print("Gagal membaca sensor DHT11!");
    for(i=0;i<16;i++){
    lcd.scrollDisplayLeft();
    delay(1000);}
    return;
  }
  else {
    lcd.setCursor(0,0);lcd.print("Lembab:");lcd.print(h);lcd.print("%");
    lcd.setCursor(0,1);lcd.print("Suhu:");lcd.print(t);lcd.print("*C");
  }
}

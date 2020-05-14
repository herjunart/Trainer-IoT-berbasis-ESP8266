#include <LiquidCrystal_I2C.h>
#define LDRPIN A0 //ke PIN A0 NODEMCU
LiquidCrystal_I2C lcd(0x27,16,2);
int sensorValue = 0;
float Vin = 5; 
float voltage = 0;
float ohm = 0;
float Rref = 1000; //sesuaikan resistor yang anda gunakan  
void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0); lcd.print("Trainer IoT");
  lcd.setCursor(0,1); lcd.print("berbasis ESP8266");
  delay(2000);
}
void loop() {
  lcd.clear();
  sensorValue = analogRead(LDRPIN);
  voltage = (sensorValue/1024.0) * Vin;
  lcd.setCursor(0,0); lcd.print(voltage); lcd.print(" V");
  ohm = Rref * (1 / ((Vin / voltage)-1));
  lcd.setCursor(0,1); lcd.print(ohm); lcd.print(" Ohm");
  delay(100);
}

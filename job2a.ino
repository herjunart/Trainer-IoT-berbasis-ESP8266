#include <LiquidCrystal_I2C.h>
#define RLYPIN 0    //ke PIN WEMOS D8
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.begin();
  pinMode(RLYPIN,OUTPUT);
  lcd.setCursor(0,0); lcd.print("Trainer IoT");
  lcd.setCursor(0,1); lcd.print("berbasis ESP8266");
  delay(2000);
}
void loop() {
  lcd.clear(); 
  lcd.setCursor(0,0);lcd.print("Relay ");
  digitalWrite(RLYPIN,LOW);
  lcd.setCursor(6,0);lcd.print("On");
  delay(1000);
  digitalWrite(RLYPIN,HIGH);
  lcd.setCursor(6,0);lcd.print("Off");
  delay(2000);
}

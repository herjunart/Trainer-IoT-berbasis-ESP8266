#include <LiquidCrystal_I2C.h>
#define BZPIN 16    //ke PIN NODEMCU D0
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.begin();
  pinMode(BZPIN,OUTPUT);
  lcd.setCursor(0,0); lcd.print("Trainer IoT");
  lcd.setCursor(0,1); lcd.print("berbasis ESP8266");
  delay(2000);
}
void loop() {
  lcd.clear(); 
  lcd.setCursor(0,0);lcd.print("Buzzer ");
  digitalWrite(BZPIN,LOW);
  lcd.setCursor(7,0);lcd.print("On");
  delay(100);
  digitalWrite(BZPIN,HIGH);
  lcd.setCursor(7,0);lcd.print("Off");
  delay(2000);
}

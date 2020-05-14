#include <ESP8266WiFi.h>	
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <RFID.h>
#define SS_PIN 15 //pin SDA modul RFID ke D10 wemos
#define RST_PIN 2
#define BZPIN 0  //pin D8 wemos
#define RLYPIN 16 //pin D2 wemos
RFID rfid(SS_PIN,RST_PIN);
LiquidCrystal_I2C lcd(0x27,16,2); 
BlynkTimer timer;
char auth[] = "xxxx"; //masukkan kode auth device yang dikirimkan ke email anda
char ssid[] = "xxxx"; //masukkan nama wifi 
char pass[] = "xxxx"; //masukkan password wifi
int serNum0= xxxx; //isikan kode pada kartu rfid
int serNum1= xxxx;
int serNum2= xxxx;
int serNum3= xxxx;
void setup() {                      
  Blynk.begin(auth, ssid, pass);
  SPI.begin();
  rfid.init();
  lcd.begin();
  lcd.backlight();
  pinMode(BZPIN,OUTPUT); pinMode(RLYPIN,OUTPUT);
  digitalWrite(BZPIN,HIGH); digitalWrite(RLYPIN,HIGH);
  lcd.setCursor(0,0); lcd.print("Trainer IoT");
  lcd.setCursor(0,1); lcd.print("berbasis ESP8266");
  delay(2000);
  lcd.clear();
  timer.setInterval(1000L,readrfid);
}
void readrfid() {
   lcd.clear();
   lcd.setCursor(0,0); lcd.print("Tempelkan");
   lcd.setCursor(0,1); lcd.print("kartu anda");
   delay(1000);
   if(rfid.isCard()){
        if(rfid.readCardSerial()){
            if (rfid.serNum[0] == serNum0
                && rfid.serNum[1] == serNum1
                && rfid.serNum[2] == serNum2
                && rfid.serNum[3] == serNum3
            ){
            lcd.clear();lcd.setCursor(0,0); lcd.print("Akses Diterima");
            delay(2000);
            digitalWrite(BZPIN,LOW); delay(100); 
            digitalWrite(BZPIN,HIGH); digitalWrite(RLYPIN,LOW); 
            Blynk.virtualWrite(V1,LOW); Blynk.virtualWrite(V2,LOW);
        }else{
          lcd.clear();lcd.setCursor(0,0); lcd.print("Akses Ditolak");
          digitalWrite(BZPIN,LOW); delay(2000);
          digitalWrite(BZPIN,HIGH); digitalWrite(RLYPIN,HIGH);
          Blynk.virtualWrite(V1,HIGH); Blynk.virtualWrite(V2,HIGH);
        }
      } 
   }
   rfid.halt();
}
void loop(){
  Blynk.run();
  timer.run();
}

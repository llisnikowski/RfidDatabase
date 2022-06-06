#if defined(arduino_main)
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.hpp"
#include "rfid/rfidRc522.hpp"
#include "wifi/wifiCommunication.hpp"
#include "configWifi.hpp"
#include "database/database.hpp"
#include "buzzer/buzzer.hpp"
#include "led/led.hpp"

RfidRc522 rfid(rfidSS, rfidReset);
WifiCommunication wifi;
Database database;
Buzzer buzzer(buzzerPin);
Led ledGreen(ledGreenPin);
Led ledRed(ledRedPin);
Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire);

void setup() 
{
  Serial.begin(115200);
  ledGreen.begin();
  ledRed.begin();
  SPI.begin();
  rfid.begin();
  wifi.begin(WIFI_SSID, WIFI_PASSWORD);
  wifi.setHostName(HOST_NAME);
  buzzer.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, screenAddress)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  while(wifi.status() != WL_CONNECTED) {  //łączenie z wifi
    delay(500);
  }
  database.setWifiCommunication(&wifi);
  Serial.println("Hello");
  if(database.ping()){
    Serial.println("--ping--");
  }
  else{
    Serial.println("--noping--");
  }
  buzzer.impuls(100,1000);
  
  ledRed.blink(500);
  ledGreen.blink(50,50);
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.setCursor(0,20);
  display.print(F("HelloWorld"));
  display.display();
}

void loop() 
{

  if(rfid.detectCard()){
    RfidUid uid = rfid.getUid();
    Serial.println(uid.getFullUid());
    if(database.findUid(uid)){
      Person person = database.getPerson();
      Serial.print(person.name);
      Serial.print("  ");
      Serial.print(person.lastName);
      Serial.print("  ");
      Serial.println(static_cast<int>(person.status));
    }
    else{
      Serial.println("Brak osoby");
    }
  }
  
  rfid.stop();
  buzzer.update();
  ledGreen.update();
  ledRed.update();
  delay(10);
}

#endif
#if defined(arduino_main)
#include <Arduino.h>
#include <SPI.h>
#include "config.hpp"
#include "rfid/rfidRc522.hpp"
#include "wifi/wifiCommunication.hpp"
#include "configWifi.hpp"
#include "database/database.hpp"

RfidRc522 rfid(rfidSS, rfidReset);
WifiCommunication wifi;
Database database;

void setup() 
{
  Serial.begin(115200);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  SPI.begin();
  rfid.begin();
  wifi.begin(WIFI_SSID, WIFI_PASSWORD);
  wifi.setHostName(HOST_NAME);

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
  delay(10);
}

#endif
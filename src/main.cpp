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
  SPI.begin();
  rfid.begin();
  wifi.begin(WIFI_SSID, WIFI_PASSWORD);
  wifi.setHostName(HOST_NAME);

  while(wifi.status() != WL_CONNECTED) {  //łączenie z wifi
    delay(500);
  }
  database.setWifiCommunication(&wifi);

  
  WifiExample(wifi);
}

void loop() 
{

  rfidExample(rfid);

  

  delay(100);
}

#endif
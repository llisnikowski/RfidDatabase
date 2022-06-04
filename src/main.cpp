#if defined(arduino_main)
#include <Arduino.h>
#include <SPI.h>
#include "config.h"
#include "rfid/rfidRc522.h"


RfidRc522 rfid(rfidSS, rfidReset);

void setup() 
{
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();

}

void loop() 
{
  delay(100);
  rfidExample(rfid);


}

#endif
#include "rfidRc522.hpp"

RfidRc522::RfidRc522(uint8_t ss, uint8_t reset)
    :MFRC522(ss, reset)
{
}

bool RfidRc522::detectCard()
{
    if(PICC_IsNewCardPresent() && PICC_ReadCardSerial()){
        RfidUid newUid(uid.uidByte[0],uid.uidByte[1],uid.uidByte[2],uid.uidByte[3]);
        isNew = lastUid != newUid;
        lastUid = newUid;
        return true; 
    }
    return false; 
}

void rfidExample(RfidRc522 &rfid)
{
    if ( ! rfid.detectCard())
        return;

    if (rfid.cardIsNew()) {
        Serial.println(F("A new card has been detected."));

        RfidUid uid = rfid.getUid();
   
        Serial.println(F("The NUID tag is:"));
        Serial.print(F("In hex: "));
        Serial.print(uid.getFullUid(),HEX);
        Serial.println();
        Serial.print(F("In dec: "));
        Serial.print(uid.getFullUid(),DEC);
        Serial.println();
        for(int i=0;i<4;i++){
            Serial.print(uid[i],DEC);
            Serial.print(F(" "));
        }
        Serial.println();
        for(int i=0;i<4;i++){
            Serial.print(uid[i],HEX);
            Serial.print(F(" "));
        }
        Serial.println();
    }
    else Serial.println(F("Card read previously."));

    rfid.stop();
}
#pragma once
#include <MFRC522.h>
#include "rfidUid.h"

class RfidRc522 :public MFRC522
{
public:
    RfidRc522(uint8_t ss, uint8_t reset);

    void init(){ MFRC522::PCD_Init();}

    bool detectCard();
    bool cardIsNew(){return isNew;}
    RfidUid getUid(){return lastUid;}
    void stop(){PICC_HaltA(); PCD_StopCrypto1();};

private:
    RfidUid lastUid;
    bool isNew;
};

void rfidExample(RfidRc522 &rfid);
#pragma once
#include <stdint.h>
#include <initializer_list>
#include <Arduino.h>

class RfidUid
{
public:
    explicit RfidUid(uint8_t n1=0, uint8_t n2=0, uint8_t n3=0, uint8_t n4=0);

    uint8_t& operator[](uint8_t i);
    uint8_t count(){return 4;}

    void operator=(std::initializer_list<uint8_t> list);
    bool operator==(RfidUid uid2);
    bool operator!=(RfidUid uid2);

    uint32_t getFullUid();
    String getUidTextDec();
    String getUidTextHex();

private:
    uint8_t uid[4];
};


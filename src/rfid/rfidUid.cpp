#include "rfidUid.hpp"

RfidUid::RfidUid(uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4)
    :uid{n1,n2,n3,n4}
{
}

uint8_t& RfidUid::operator[](uint8_t i)
{
    return uid[i];
}

void RfidUid::operator=(std::initializer_list<uint8_t> list)
{
    int i = 0;
    for(const uint8_t &n : list){
        uid[i++] = n;
        if(i>=4) break;
    }
}

bool RfidUid::operator==(RfidUid uid2)
{
    return uid[0] == uid2[0]
        && uid[1] == uid2[1]
        && uid[2] == uid2[2]
        && uid[3] == uid2[3];
}

bool RfidUid::operator!=(RfidUid uid2)
{
    return !(this->operator==(uid2));
}

uint32_t RfidUid::getFullUid()
{
    return (uint32_t)uid[0]<<24 | (uint32_t)uid[1]<<16 | (uint32_t)uid[2]<<8 | (uint32_t)uid[3];
}
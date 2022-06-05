#pragma once
#include "person.hpp"

class RfidUid;
class WifiCommunication;

class Database
{
public:
    Database();
    ~Database();

    void setWifiCommunication(WifiCommunication* wifi){this->wifi = wifi;}
    
    bool ping();
    bool findUid(RfidUid uid);
    Person& getPerson(){return person;}

private:
    Person person;
    WifiCommunication *wifi;
};



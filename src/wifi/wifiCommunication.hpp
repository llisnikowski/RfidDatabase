#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class WifiCommunication : public WiFiClass
{
public:
    WifiCommunication();
    ~WifiCommunication();
    void begin(const char* ssid, const char *password){WiFiClass::begin(ssid, password);}
    void setHostName(String name){hostName = name;}

    wl_status_t status(){return WiFiClass::status();}
    IPAddress localIP(){return WiFiClass::localIP();}

    bool query(String query);
    bool query(String query, String& response);

    bool ping();

private:
    String hostName;
};

void WifiExample(WifiCommunication& wifi);

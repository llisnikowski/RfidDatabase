#include "wifiCommunication.hpp"

WifiCommunication::WifiCommunication()
{
}

WifiCommunication::~WifiCommunication()
{
}

bool WifiCommunication::query(String query)
{
    int success = false;
    HTTPClient http;

    http.begin(hostName+query);
    int httpCode = http.GET();

    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            success = true;
        }
    }

    http.end();
    return success;
}

bool WifiCommunication::query(String query, String& response)
{
    int success = false;
    HTTPClient http;

    http.begin(hostName+query);
    int httpCode = http.GET();

    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            response = http.getString();
            success = true;
        }
    }

    http.end();
    return success;
}


bool WifiCommunication::ping()
{
    String response;
    if(query("ping.php",response)){
        return response=="true";
    }
    return false;
}


String PATH_NAME   = "/insert_temp.php";
String queryString = "?temperature=30.5";
void WifiExample(WifiCommunication& wifi)
{
    if(wifi.ping()){
        Serial.println("Ping");
    }
    else Serial.println("No response from the server");

    String response;
    if(wifi.query(PATH_NAME + queryString, response)){
        Serial.println(response);
    }
    else{
       Serial.println("error");
    }
}
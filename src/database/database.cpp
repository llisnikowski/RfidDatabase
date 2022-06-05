#include "database.hpp"
#include "../rfid/rfidUid.hpp"
#include "../wifi/wifiCommunication.hpp"

Database::Database()
    :person(), wifi()
{
}

Database::~Database()
{
}

bool Database::ping()
{
    return wifi->ping();
}


bool Database::findUid(RfidUid uid)
{
    if(!wifi) return false;

    person = Person(uid);
    String resoult;
    wifi->query("isUid.php?uid="+uid.getUidText(),resoult);
    if(resoult == "true"){
        wifi->query("getPerson.php?uid="+uid.getUidText(),resoult);

        int splitFrom = 0;
        int splitTo = resoult.indexOf(";");
        person.name = resoult.substring(splitFrom, splitTo);

        splitFrom = splitTo+1;
        splitTo = resoult.indexOf(";", splitFrom);
        person.lastName = resoult.substring(splitFrom, splitTo);

        splitFrom = splitTo+1;
        splitTo = resoult.indexOf(";", splitFrom);
        person.status = static_cast<PersonStatus>
                    (resoult.substring(splitFrom, splitTo).toInt());
        
    }
    
    return false;
    
}


#pragma once
#include <Arduino.h>
#include "../rfid/rfidUid.hpp"

enum class PersonStatus{
    unknown,
    noaccess,
    fullaccess
};

class Person
{
public:
    Person();
    explicit Person(RfidUid uid,
        String name = "",
        String lastName = "",
        PersonStatus status = PersonStatus::unknown);
    ~Person();

    RfidUid rfidUid;
    String name;
    String lastName;
    PersonStatus status;

private:

};



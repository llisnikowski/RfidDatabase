#include "person.hpp"

Person::Person()
    :rfidUid(), name(), lastName(), status(PersonStatus::unknown)
{
}
Person::Person(RfidUid uid, String name, String lastName, PersonStatus status)
    :rfidUid(uid), name(name), lastName(lastName), status(status)
{
}

Person::~Person()
{
}
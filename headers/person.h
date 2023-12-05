// person.h
#ifndef PERSON_H
#define PERSON_H

#include "fault.h"
#include "ship.h"

enum PersonType {
    KONTROL_GOREVLISI,
    DUZELTME_GOREVLISI
};

typedef struct {
    int personID;
    char personName[50];
    char username[50];
    char password[50];
    enum PersonType type;
    Fault *findFaultsByPerson(struct Person *self);
} Person;

Fault *findFaultsByPerson(Person *self);

#endif // PERSON_H

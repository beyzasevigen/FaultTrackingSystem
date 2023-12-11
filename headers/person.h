// person.h
#ifndef PERSON_H
#define PERSON_H

#include "fault.h"
#include "ship.h"

typedef struct Fault;
typedef struct Ship;


enum PersonType {
    KONTROL_GOREVLISI,
    DUZELTME_GOREVLISI
};

typedef struct Person{
    int personID;
    char personName[100];
    char username[100];
    char password[100];
    enum PersonType type;
    //struct Fault *(*findFaultsByPerson)(struct Person *self);
} Person;


Person *createPerson(int personID, const char *personName, const char *username, const char *password, enum PersonType type);

void assignDuzeltmeGorevlisi(Fault *fault, int duzeltmeGorevlisiID);

//void listAssignedPersonels(struct Fault *faults, int faultCount);
//struct Fault *findFaultsByPerson(struct Person *self);

#endif // PERSON_H

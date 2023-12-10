// person.h
#ifndef PERSON_H
#define PERSON_H

#include "../headers/fault.h"
#include "../headers/ship.h"

struct Fault;
struct Ship;

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
    //struct Fault *(*findFaultsByPerson)(struct Person *self);
} Person;


struct Person *createPerson(int personID, const char *personName, const char *username, const char *password, enum PersonType type);

void assignDuzeltmeGorevlisi(struct Fault *fault, int duzeltmeGorevlisiID);

//void listAssignedPersonels(struct Fault *faults, int faultCount);
//struct Fault *findFaultsByPerson(struct Person *self);

#endif // PERSON_H

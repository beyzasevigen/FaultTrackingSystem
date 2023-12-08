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
    struct Fault *(*findFaultsByPerson)(struct Person *self);
} Person;

struct Fault *findFaultsByPerson(struct Person *self);

void assignDuzeltmeGorevlisi(struct Fault *fault, struct Person duzeltmeGorevlisi);
void listAssignedPersonels(struct Fault *faults, int faultCount);


#endif // PERSON_H

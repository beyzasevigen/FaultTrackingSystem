// person.h
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "ship.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct Fault;
//typedef struct Ship;


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


//void listAssignedPersonels(struct Fault *faults, int faultCount);
//struct Fault *findFaultsByPerson(struct Person *self);

#endif // PERSON_H

// fault.h
#ifndef FAULT_H
#define FAULT_H

#include <stdbool.h>
#include "../headers/ship.h"
#include "../headers/person.h"

struct Ship;
struct Person;

enum FaultLevel {
    SLIGHT,
    MEDIUM,
    SEVERE
};

enum FaultType {
    ELEKTRIK,
    MEKANIK,
    HARARET,
    // ... diğer hata tipleri
};

typedef struct Fault{
    int faultID;
    char faultExplanation[100];
    enum FaultType type;
    enum FaultLevel level;
    bool isRepaired;
    struct Person *duzeltmeGorevlisi;
    // ... diğer özellikler
} Fault;

void waterTempControl(Ship *ship, int waterTemp);


#endif // FAULT_H

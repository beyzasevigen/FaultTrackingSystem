// fault.h
#ifndef FAULT_H
#define FAULT_H

#include <stdbool.h>
#include "ship.h"
#include "person.h"

typedef struct Ship;
typedef struct Person;

enum FaultLevel {
    SLIGHT,
    MEDIUM,
    SEVERE,
};

enum FaultType {
    YAG_BASINCI,
    SU_SEVİYESİ,
    HARARET,
    // ... diğer hata tipleri
};

typedef struct Fault{
    int faultID;
    char faultExplanation[100];
    enum FaultType type;
    enum FaultLevel level;
    bool isRepaired;
    bool isThereProblem;
    Person *duzeltmeGorevlisi;
    // ... diğer özellikler
} Fault;

void waterTempControl(Ship *ship,  Fault *faults, int waterTemp);
void waterLevelControl(Ship *ship,  Fault *faults, int waterLevel);
void oilPressureControl(Ship *ship,  Fault *faults, int oilPressure);
#endif // FAULT_H

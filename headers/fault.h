// fault.h
#pragma once
#ifndef FAULT_H
#define FAULT_H

#include <stdbool.h>
#include <stdio.h>
#include "ship.h"
#include "person.h"

//typedef struct Ship;
//typedef struct Person;

enum FaultLevel {
    SLIGHT,
    MEDIUM,
    SEVERE,
};

enum FaultType {
    OIL_PRESSURE,
    WATER_LEVEL,
    TEMPERATURE,
    // ... diğer hata tipleri
};

typedef struct Fault {
    int faultID;
    char faultExplanation[100];
    enum FaultType type;
    enum FaultLevel level;
    bool isRepaired;
    bool isThereProblem;
    Person *duzeltmeGorevlisi;
    //void (*waterTempControl)(Ship *ship, struct Fault *faults, int waterTemp)
    // ... diğer özellikler
} Fault;

void waterTempControl(Ship *ship,  Fault *faults, int waterTemp);
void waterLevelControl(Ship *ship,  Fault *faults, int waterLevel);
void oilPressureControl(Ship *ship,  Fault *faults, int oilPressure);
void assignDuzeltmeGorevlisi(Fault *fault, int faultID, int duzeltmeGorevlisiID);
void listRepairedProblems(Fault *faults, int faultCount);
void listUnrepairedProblems(Fault *faults, int faultCount);
void listAssignedFaults(Fault *faults, int faultCount, int duzeltmeGorevlisiID);
void markFaultsAsRepairedByPersonID(Fault *faults, int faultCount, int duzeltmeGorevlisiID);

#endif // FAULT_H

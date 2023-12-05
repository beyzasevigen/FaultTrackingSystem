// fault.h
#ifndef FAULT_H
#define FAULT_H

#include "ship.h"
#include "person.h"

enum FaultLevel {
    SLIGHT,
    MEDIUM,
    SEVERE
};

enum FaultType {
    ELEKTRIK,
    MEKANIK,
    YANGIN,
    SU_BATMASI,
    // ... diğer hata tipleri
};

typedef struct {
    int faultID;
    char faultExplanation[100];
    enum FaultType type;
    enum faultLevel level;
    Person *kontrolgörevlisi;
    // ... diğer özellikler
} Fault;

#endif // FAULT_H

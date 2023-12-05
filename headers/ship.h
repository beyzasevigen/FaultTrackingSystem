// ship.h
#ifndef SHIP_H
#define SHIP_H

enum ShipDepartmentType {
    MOTOR,
    GOVDENE,
    GOVDE,
    YAKIT_TANKI,
    // ... diğer gemi bölüm tipleri
};


typedef struct {
    int shipID;
    char shipName[50];
    ShipDepartmentType ShipDepartmentType;
    // ... diğer özellikler
} Ship;

#endif // SHIP_H

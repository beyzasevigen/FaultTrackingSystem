// ship.h
#ifndef SHIP_H
#define SHIP_H

enum ShipDepartmentType {
    MOTOR,
    GOVDE,
    YAG_TANKI,
    SU_TANKI,
    // ... diğer gemi bölüm tipleri
};



typedef struct {
    int shipID;
    char shipName[50];
    enum ShipDepartmentType departmentType;
    int waterTemp;
    int waterLevel;
    int oilPressure;
    
   // ... diğer özellikler
 } Ship;

Ship *createShip(int shipID, const char *shipName);

#endif // SHIP_H

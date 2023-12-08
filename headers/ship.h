// ship.h
#ifndef SHIP_H
#define SHIP_H

enum ShipDepartmentType {
    MOTOR,
    GOVDE,
    YAKIT_TANKI,
    SU_TANKI,
    // ... diğer gemi bölüm tipleri
};

typedef struct {
    int departmentID;
    char departmentName[50];
    enum ShipDepartmentType departmentType;
    int waterTemp;
} ShipDepartment;

typedef struct {
    int shipID;
    char shipName[50];
    ShipDepartment shipDepartments[5];
    // ... diğer özellikler
} Ship;


#endif // SHIP_H

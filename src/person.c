#include "../headers/person.h"
#include "../headers/fault.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void assignDuzeltmeGorevlisi( Fault *fault, int duzeltmeGorevlisiID) {
    // Hataya düzeltme görevlisi atama işlemleri
    if (fault->duzeltmeGorevlisi != NULL && fault->duzeltmeGorevlisi->type== KONTROL_GOREVLISI) {
        // Hata: Düzeltme görevlisi zaten atanmış ve kontrol görevlisi ise
        printf("Error: The assigned person is already a control officer.\n");
    } else {
        // Atama işlemini gerçekleştir
        fault->duzeltmeGorevlisi->type= duzeltmeGorevlisiID;
    }
}


void markFaultsAsRepairedByPersonID(Fault *faults, int faultCount, int duzeltmeGorevlisiID) {
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].isThereProblem && !faults[i].isRepaired && faults[i].duzeltmeGorevlisi != NULL &&
            faults[i].duzeltmeGorevlisi->personID == duzeltmeGorevlisiID) {
            faults[i].isRepaired = true;
        }
    }
}

Person *createPerson(int personID, const char *personName, const char *username, const char *password, enum PersonType type) {
    Person *newPerson = (Person*)malloc(sizeof(Person));

    if (newPerson == NULL) {
        // Bellek tahsisi başarısız oldu
        return NULL;
    }

    newPerson->personID = personID; 
    strncpy(newPerson->personName, personName, sizeof(newPerson->personName) - 1);
    strncpy(newPerson->username, username, sizeof(newPerson->username) - 1);
    strncpy(newPerson->password, password, sizeof(newPerson->password) - 1);
    newPerson->type = type;

    return newPerson;
}









/*void listAssignedPersonels(struct Fault *faults, int faultCount) {
    // Atanan görevlileri listeleyen işlemler
    printf("Atanan Gorevliler:\n");
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].duzeltmeGorevlisi != -1) {
            printf("Hata ID: %d - Duzeltme Gorevlisi ID: %d\n", faults[i].faultID, faults[i].duzeltmeGorevlisi);
        }
    }
}*/

// ... diğer atama işlemleri

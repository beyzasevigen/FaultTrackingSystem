
#include "../headers/fault.h"
#include "../headers/person.h"
#include <stdio.h>

void assignDuzeltmeGorevlisi(struct Fault *fault, Person duzeltmeGorevlisi) {
    // Hataya düzeltme görevlisi atama işlemleri
    fault->duzeltmeGorevlisi = duzeltmeGorevlisi.personID;

    // Hatayı dosyaya yazma işlemleri
    //writeHataToFile(hata);
}

void listAssignedPersonels(struct Fault *faults, int faultCount) {
    // Atanan görevlileri listeleyen işlemler
    printf("Atanan Gorevliler:\n");
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].duzeltmeGorevlisi != -1) {
            printf("Hata ID: %d - Duzeltme Gorevlisi ID: %d\n", faults[i].faultID, faults[i].duzeltmeGorevlisi);
        }
    }
}

// ... diğer atama işlemleri

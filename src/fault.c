#include "../headers/fault.h"

/*static const char *const faults_names[]= {
    [SLIGHT] = "SLIGHT",
    [MEDIUM] = "MEDIUM",
    [SEVERE] = "SEVERE",
}; */

void waterTempControl(Ship *ship, Fault *faults, int waterTemp) {
    
        //if (ship->departmentType == MOTOR) {
            // Su sıcaklığı kontrolü
            ship->waterTemp = waterTemp;
            if (ship->waterTemp > 100) {
                // Hararet hatası
                Fault tempError;
                tempError.faultID = 1; // Örnek bir hata ID üretme fonksiyonu
                tempError.type = TEMPERATURE;
                tempError.level = SEVERE;
                tempError.isRepaired = false;
                tempError.isThereProblem = true;
                tempError.duzeltmeGorevlisi = NULL; // İlk başta atanmamış.
                
                sprintf(tempError.faultExplanation, "The water temperature reached %d degrees. Temperature error!", ship->waterTemp);
                
                for (int j = 0; j < 100; ++j) {
                    if (!faults[j].isThereProblem) {
                        faults[j] = tempError;
                        break;
                    }

                }
                // Kullanıcıyı uyar
                printf("Warning: Temperature error on board! Error ID: %d\n, faulty section: %s\n, Level: %s\n", 
                       tempError.faultID, "MOTOR", "SEVERE");
            }   
        }
    //}


void waterLevelControl(Ship *ship, Fault *faults, int waterLevel) {
    //if (ship->departmentType == SU_TANKI) {
        ship->waterLevel=waterLevel;
        if (ship->waterLevel < 30) {
            // Su seviyesi hatası
            Fault waterLevelError;
            waterLevelError.faultID = 2;
            waterLevelError.type = WATER_LEVEL; // Örnek bir hata tipi, uygun olanı seçiniz
            waterLevelError.level = SEVERE; // Örnek bir hata seviyesi, uygun olanı seçiniz
            waterLevelError.isRepaired = false;
            waterLevelError.isThereProblem = true;
            waterLevelError.duzeltmeGorevlisi = NULL; // İlk başta atanmamış.
            //waterLevelError.waterTempControl = waterTempControl;

                sprintf(waterLevelError.faultExplanation, "The water level dropped below %f%%. Water level error!", waterLevel);

                for (int j = 0; j < 100; ++j) {
                    if (!faults[j].isThereProblem) {
                    faults[j] = waterLevelError;
                    break;
                    }       
                }

                printf("Warning: Water level error! Error ID: %d, Level: %s\n", waterLevelError.faultID, "SEVERE");
            }
        }
    //}

void oilPressureControl(Ship *ship, Fault *faults, int oilPressure) {
    
        //if (ship->departmentType == YAG_TANKI) {
            // Yağ basıncı kontrolü
            ship->oilPressure=oilPressure;

            if (ship->oilPressure < 20) {
                // Yağ basıncı düşük uyarısı
                Fault oilPressureError;
                oilPressureError.faultID = 3;
                oilPressureError.type = OIL_PRESSURE;
                oilPressureError.level = SLIGHT;
                oilPressureError.isRepaired = false;
                oilPressureError.isThereProblem = true;
                oilPressureError.duzeltmeGorevlisi = NULL;

                sprintf(oilPressureError.faultExplanation, "Oil pressure dropped below %d%%. Low oil pressure warning!",
                        oilPressure);

                // Hata bilgilerini dizisine ekle
                for (int j = 0; j < 100; ++j) {
                    if (!faults[j].isThereProblem) {
                        faults[j] = oilPressureError;
                        break;
                    }
                }

                // Kullanıcıyı uyar
                printf("Warning: Oil pressure low! Error ID: %d, Level: %s\n",
                       oilPressureError.faultID, "SLIGHT");
            } 
        }
    //}


void markFaultsAsRepairedByPersonID(Fault *faults, int faultCount, int duzeltmeGorevlisiID) {
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].isThereProblem && !faults[i].isRepaired && faults[i].duzeltmeGorevlisi != NULL &&
            faults[i].duzeltmeGorevlisi->personID == duzeltmeGorevlisiID) {
            faults[i].isRepaired = true;
        }
    }
}



void assignDuzeltmeGorevlisi(Fault *faults, int faultID, int duzeltmeGorevlisiID) {
    // Hataya düzeltme görevlisi atama işlemleri
    int hataIndisi = -1;

    // faults dizisi içinde hata kontrolü ve hataID'ye göre indis bulma
    for (int i = 0; i < 100; ++i) {
        if (faults[i].isThereProblem && faults[i].faultID == faultID) {
            hataIndisi = i;
            break;
        }
    }

    // Hata bulunamadıysa
    if (hataIndisi == -1) {
        printf("Error: Fault with ID %d not found.\n", faultID);
        return;
    }

    // Düzeltme görevlisinin zaten atanmış olup olmadığını kontrol et
    if (faults[hataIndisi].duzeltmeGorevlisi != NULL && faults[hataIndisi].duzeltmeGorevlisi->type == DUZELTME_GOREVLISI) {
        printf("Error: The assigned person is already a repair officer.\n");
    } else {
        // Atama işlemini gerçekleştir
        faults[hataIndisi].duzeltmeGorevlisi = malloc(sizeof(Person));
        faults[hataIndisi].duzeltmeGorevlisi->personID = duzeltmeGorevlisiID;
        // Diğer duzeltmeGorevlisi özelliklerini de atayabilirsiniz.
    }
}


void listAssignedFaults(Fault *faults, int faultCount, int duzeltmeGorevlisiID) {
    printf("Errors Belonging to Appointed Officials:\n");

    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].duzeltmeGorevlisi != NULL && faults[i].duzeltmeGorevlisi->personID == duzeltmeGorevlisiID) {
            printf("Assigned officer name: %s, ID: %d\n", faults[i].duzeltmeGorevlisi->personName, faults[i].duzeltmeGorevlisi->personID);
            printf("Error ID: %d - Error Type: %d - Error Level: %d - Error Description: %s\n", 
                   faults[i].faultID, faults[i].type, faults[i].level, faults[i].faultExplanation);
        }
    }
}

void listUnrepairedProblems(Fault *faults, int faultCount) {
    printf("Unrepaired faults:\n");
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].isThereProblem && !faults[i].isRepaired) {
            printf("Error ID: %d, Type: %d, Level: %d\n", 
                   faults[i].faultID, faults[i].type, faults[i].level);
        }
    }
}

void listRepairedProblems(Fault *faults, int faultCount) {
    printf("Repaired faults:\n");
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].isThereProblem && faults[i].isRepaired) {
            printf("Error ID: %d, Type: %d, Level: %d\n", 
                   faults[i].faultID, faults[i].type, faults[i].level);
        }
    }
}




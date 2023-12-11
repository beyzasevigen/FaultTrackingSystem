#include "../headers/fault.h"
#include "../headers/ship.h"
#include <stdio.h>

void waterTempControl(Ship *ship, Fault *faults, int waterTemp) {
    for (int i = 0; i < 5; ++i) { // Varsayılan olarak 5 bölümü varsayalım
        if (ship->departmentType == MOTOR) {
            // Su sıcaklığı kontrolü
            if (ship->waterTemp > 100) {
                // Hararet hatası
                Fault tempError;
                tempError.faultID = 1; // Örnek bir hata ID üretme fonksiyonu
                tempError.type = HARARET;
                tempError.level = SEVERE;
                tempError.isRepaired = false;
                tempError.isThereProblem = true;
                tempError.duzeltmeGorevlisi = NULL; // İlk başta atanmamış.

                sprintf(tempError.faultExplanation, "Su sıcaklığı %d dereceye ulaştı. Hararet hatası!", ship->waterTemp);
                
                for (int j = 0; j < 100; ++j) {
                    if (!faults[j].isThereProblem) {
                        faults[j] = tempError;
                        break;
                    }

                }
                // Kullanıcıyı uyar
                printf("Uyarı: Gemide hararet hatası! Hata ID: %d, hatalı bölüm: %s\n, Seviye: %s\n", 
                       tempError.faultID, "MOTOR", "CİDDİ");
            }   else {
                // Su sıcaklığı sorunu olmadığında
                Fault tempError;
                tempError.isThereProblem = false; // Hata yok
            }
        }
    }
}

void waterLevelControl(Ship *ship, Fault *faults, int waterLevel) {
    if (ship->departmentType == SU_TANKI) {
        if (ship->waterLevel < 30) {
            // Su seviyesi hatası
            Fault waterLevelError;
            waterLevelError.faultID = 2;
            waterLevelError.type = SU_SEVİYESİ; // Örnek bir hata tipi, uygun olanı seçiniz
            waterLevelError.level = SEVERE; // Örnek bir hata seviyesi, uygun olanı seçiniz
            waterLevelError.isRepaired = false;
            waterLevelError.isThereProblem = true;
            waterLevelError.duzeltmeGorevlisi = NULL; // İlk başta atanmamış.

                sprintf(waterLevelError.faultExplanation, "Su seviyesi %f%%'nın altına düştü. Su seviyesi hatası!", waterLevel);

                for (int j = 0; j < 100; ++j) {
                    if (!faults[j].isThereProblem) {
                    faults[j] = waterLevelError;
                    break;
                    }       
                }

                printf("Uyarı: Su seviyesi hatası! Hata ID: %d, Seviye: %s\n", waterLevelError.faultID, "CİDDİ");
            }
        }
    }

void oilPressureControl(Ship *ship, Fault *faults, int oilPressure) {
    for (int i = 0; i < 5; ++i) {
        if (ship->departmentType == YAG_TANKI) {
            // Yağ basıncı kontrolü

            if (oilPressure < 20) {
                // Yağ basıncı düşük uyarısı
                Fault oilPressureError;
                oilPressureError.faultID = 3;
                oilPressureError.type = YAG_BASINCI;
                oilPressureError.level = SLIGHT;
                oilPressureError.isRepaired = false;
                oilPressureError.isThereProblem = true;
                oilPressureError.duzeltmeGorevlisi = NULL;

                sprintf(oilPressureError.faultExplanation, "Yağ basıncı %d%%'nin altına düştü. Yağ basıncı düşük uyarısı!",
                        oilPressure);

                // Hata bilgilerini dizisine ekle
                for (int j = 0; j < 100; ++j) {
                    if (!faults[j].isThereProblem) {
                        faults[j] = oilPressureError;
                        break;
                    }
                }

                // Kullanıcıyı uyar
                printf("Uyarı: Yağ basıncı düşük! Hata ID: %d, Seviye: %s\n",
                       oilPressureError.faultID, "HAFİF");
            } else {
                // Yağ basıncı sorunu olmadığında
                Fault oilPressureError;
                oilPressureError.isThereProblem = false;
            }
        }
    }
}
    

void listAssignedFaults(Fault *faults, int faultCount, int duzeltmeGorevlisiID) {
    printf("Atanan Gorevlilere Ait Hatalar:\n");

    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].duzeltmeGorevlisi != NULL && faults[i].duzeltmeGorevlisi->personID == duzeltmeGorevlisiID) {
            printf("Hata ID: %d - Hata Tipi: %d - Hata Seviyesi: %d - Hata Aciklama: %s\n", 
                   faults[i].faultID, faults[i].type, faults[i].level, faults[i].faultExplanation);
        }
    }
}

void listUnrepairedProblems(Fault *faults, int faultCount) {
    printf("Onarilmamis Sorunlar:\n");
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].isThereProblem && !faults[i].isRepaired) {
            printf("Hata ID: %d, Tip: %d, Seviye: %d\n", 
                   faults[i].faultID, faults[i].type, faults[i].level);
        }
    }
}

void listRepairedProblems(Fault *faults, int faultCount) {
    printf("Onarilmis Sorunlar:\n");
    for (int i = 0; i < faultCount; ++i) {
        if (faults[i].isThereProblem && faults[i].isRepaired) {
            printf("Hata ID: %d, Tip: %d, Seviye: %d\n", 
                   faults[i].faultID, faults[i].type, faults[i].level);
        }
    }
}




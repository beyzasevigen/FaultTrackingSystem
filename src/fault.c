#include "../headers/fault.h"
#include "../headers/ship.h"
#include <stdio.h>

void waterTempControl(Ship *ship, int waterTemp) {
    for (int i = 0; i < 5; ++i) { // Varsayılan olarak 5 bölümü varsayalım
        if (ship->shipDepartments[i].departmentType == SU_TANKI) {
            // Su sıcaklığı kontrolü
            if (ship->shipDepartments[i].waterTemp > 100) {
                // Hararet hatası
                struct Fault tempError;
                tempError.faultID = generateHataID(); // Örnek bir hata ID üretme fonksiyonu
                tempError.type = HARARET;
                tempError.level = SEVERE;
                sprintf(tempError.faultExplanation, "Su sıcaklığı %d dereceye ulaştı. Hararet hatası!", ship->shipDepartments[i].waterTemp);
                
                // Hata bilgilerini dosyaya yaz
                //writeHataToFile(&tempError);
                
                // Kullanıcıyı uyar
                printf("Uyarı: Gemide hararet hatası! Hata ID: %d, Bölüm: %s, Seviye: %s\n", 
                       tempError.faultID, ship->shipDepartments[i].departmentName, "CİDDİ");
            }
        }
    }
}
#include <stdio.h>
#include <stdbool.h>
#include "../headers/fault.h"
#include "../headers/person.h"
#include "../headers/ship.h"

int main() {
    // Kullanıcı girişi için örnek
    char username[50];
    char password[50];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // Örnek kullanıcı oluşturuldu, gerçek kullanıcı doğrulama burada yapılacak
    Person user;
    user.personID = 1;
    strcpy(user.personName, "Beyza Sevigen");
    strcpy(user.username, "beyzas");
    strcpy(user.password, "123");
    user.type = KONTROL_GOREVLISI;

    Fault *faults;

    // Kullanıcı doğrulama
    if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
        printf("Giriş başarılı!\n");

        if (user.type == KONTROL_GOREVLISI) {
        int choice;
        do {
            // Kullanıcıya seçenekleri gösterme
            printf("1) Bilgi Girme\n");
            printf("2) Hataları Listele\n");
            printf("3) Duzeltme Gorevlisi Ata\n");
            printf("4) Hataları Listele (Duzeltme Gorevlisine Gore)\n");
            printf("0) Cikis\n");
            printf("Seciminiz: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    // Bilgi girme fonksiyonu burada çağrılacak
                    int waterTemp;
                    Ship *ship;
                    printf("Su Sıcaklığını Girin: ");
                    scanf("%d", &waterTemp);
                    
                    int waterLevel;
                    printf("Su Seviyesini Girin: ");
                    scanf("%d", &waterLevel);
                    
                    int oilPressure;
                    printf("Yağ Basıncını Girin: ");
                    scanf("%d", &oilPressure);
                    
                    waterTempControl(&ship, faults, waterTemp);
                    waterLevelControl(&ship, faults, waterLevel);
                    oilPressureControl(&ship, faults, oilPressure); 

                    break;
                }
            
            case 2: {
                    // Hataları Listeleme
                    int choice2;
                    printf("Lütfen bir seçenek girin:\n");
                    printf("1) Çözülen Hatalar\n");
                    printf("2) Çözülmeyen Hatalar\n");
                    printf("Seçim: ");
                    scanf("%d", &choice2);

                    if (choice2 == 1) {
                        listRepairedProblems(NULL, 0); // İlgili metodu çağırın
                    } else if (choice2 == 2) {
                        listUnrepairedProblems(NULL, 0); // İlgili metodu çağırın
                    } else {
                        printf("Geçersiz seçenek!\n");
                    }
                    break;
                }
                case 3: {
                    // Hatalara Eleman Atama
                    int duzeltmeGorevlisiID;
                    printf("Düzeltme Görevlisi ID'sini Girin: ");
                    scanf("%d", &duzeltmeGorevlisiID);
                    assignDuzeltmeGorevlisi(NULL, duzeltmeGorevlisiID); // İlgili metodu çağırın
                    break;
                }
                case 4: {
                    // Atanan Hataları Listeleme
                    listAssignedFaults(NULL, 0, user.personID); // İlgili metodu çağırın
                    break;
                }
                case 5:
                    printf("Çıkış yapılıyor...\n");
                    break;
                default:
                    printf("Geçersiz seçenek!\n");
            }
        } while (choice != 5);
    } else if (user.type == DUZELTME_GOREVLISI) {
        // Düzeltme Görevlisi Kontrol Paneli
        int choice;
        do {
            printf("Lütfen bir seçenek girin:\n");
            printf("1) Kendine Atanan Hataları Listeleme\n");
            printf("2) Kendine Atanan Hataları Çözüldü Olarak İşaretleme\n");
            printf("3) Çıkış\n");
            printf("Seçim: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    // Kendine Atanan Hataları Listeleme
                    listAssignedFaults(NULL, 0, user.personID); // İlgili metodu çağırın
                    break;
                }
                case 2: {
                    // Kendine Atanan Hataları Çözüldü Olarak İşaretleme
                    int faultID;
                    printf("Hata ID'sini Girin: ");
                    scanf("%d", &faultID);
                    markFaultsAsRepairedByPersonID(NULL, 0, faultID); // İlgili metodu çağırın
                    break;
                }
                case 3:
                    printf("Çıkış yapılıyor...\n");
                    break;
                default:
                    printf("Geçersiz seçenek!\n");
            }
        } while (choice != 3);
    } else {
        printf("Tanımsız kullanıcı tipi!\n");
    }
}
}

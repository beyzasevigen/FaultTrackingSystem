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
                    waterTempControl(&ship, faults, waterTemp);
                    break;
                }
            }
        }
    }
}


#include <stdio.h>
#include <stdbool.h>
#include "../src/database.c"
#include "../headers/fault.h"
#include "../headers/person.h"
#include "../headers/ship.h"
#include "../src/person.c"
#include "../src/ship.c"
#include "../src/fault.c"


void defaultInfo();

int main() {

    //defaultInfo();
    readPerson(people);
    //printf("%s", people[1].personName);
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

    
    Ship *ship = malloc(sizeof(Ship));
    ship->shipID=1;
    strcpy(ship->shipName, "abc");
    ship->oilPressure;
    ship->waterTemp;
    ship->waterLevel;
    Fault faults[100];
    int faultCount=5;

    // Kullanıcı doğrulama
    if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
        printf("Login successful!\n");

        if (user.type == KONTROL_GOREVLISI) {
        int choice;
        do {
            // Kullanıcıya seçenekleri gösterme
            printf("1) Entering Information\n");
            printf("2) List faults\n");
            printf("3) Assign duzeltme gorevlisi\n");
            printf("4) List faults (according to duzeltme gorevlisi)\n");
            printf("0) Exit\n");
            printf("Your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    // Bilgi girme fonksiyonu burada çağrılacak
                    int waterTemp;
                   
                    printf("Enter Water Temperature: ");
                    scanf("%d", &waterTemp);
                    
                    int waterLevel;
                    printf("Enter Water Level: ");
                    scanf("%d", &waterLevel);
                    
                    int oilPressure;
                    printf("Enter Oil Pressure: ");
                    scanf("%d", &oilPressure);
                    
                    faults[0].waterTempControl(ship, faults, waterTemp);
                    waterLevelControl(ship, faults, waterLevel);
                    oilPressureControl(ship, faults, oilPressure); 

                    break;
                }
            
            case 2: {
                    // Hataları Listeleme
                    int choice2;
                    printf("Please enter a choice:\n");
                    printf("1) Repaired Faults\n");
                    printf("2) Unrepaired Faults\n");
                    printf("choice: ");
                    scanf("%d", &choice2);

                    if (choice2 == 1) {
                        listRepairedProblems(faults, faultCount); // İlgili metodu çağırın
                    } else if (choice2 == 2) {
                        listUnrepairedProblems(faults, faultCount); // İlgili metodu çağırın
                    } else {
                        printf("Invalid choice!\n");
                    }
                    break;
                }
                case 3: {
                    // Hatalara Eleman Atama
                    int personID;
                    printf("Enter ID of duzeltme gorevlisi ");
                    scanf("%d", &personID);
                    assignDuzeltmeGorevlisi(faults, user.personID); // İlgili metodu çağırın
                    break;
                }
                case 4: {
                    // Atanan Hataları Listeleme
                    listAssignedFaults(faults, faultCount, user.personID); // İlgili metodu çağırın
                    break;
                }
                case 5:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } while (choice != 5);
    } else if (user.type == DUZELTME_GOREVLISI) {
        // Düzeltme Görevlisi Kontrol Paneli
        int choice;
        do {
            printf("Please enter a choice:\n");
            printf("1) List Self-Assigned Faults\n");
            printf("2) Marking Self-Assigned Faults as Repaired\n");
            printf("3) Exit\n");
            printf("Choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    // Kendine Atanan Hataları Listeleme
                    listAssignedFaults(faults, faultCount, user.personID); // İlgili metodu çağırın
                    break;
                }
                case 2: {
                    // Kendine Atanan Hataları Çözüldü Olarak İşaretleme
                    int personID;
                    printf("Enter fault ID: ");
                    scanf("%d", &personID);
                    markFaultsAsRepairedByPersonID(faults, faultCount, user.personID); // İlgili metodu çağırın
                    break;
                }
                case 3:
                    printf("Exiting...\n");
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } while (choice != 3);
    } else {
        printf("Undefined user type!\n");
    }
}
}

void defaultInfo() {

    Person *person1 = createPerson(1, "gonul", "gonul", "123", DUZELTME_GOREVLISI);
    Person *person2 = createPerson(2, "yusuf", "yusuf", "123", DUZELTME_GOREVLISI);
    Person *person3 = createPerson(3, "yasar", "yasar", "123", DUZELTME_GOREVLISI);
    Person *person4 = createPerson(4, "a", "a", "123", DUZELTME_GOREVLISI);
    Person *person5 = createPerson(5, "b", "b", "123", DUZELTME_GOREVLISI);
    Person *person6 = createPerson(6, "c", "c", "123", DUZELTME_GOREVLISI);
}

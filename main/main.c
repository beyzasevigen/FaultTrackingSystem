#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../src/database.c"
#include "../headers/fault.h"
#include "../headers/person.h"
#include "../headers/ship.h"
#include "../src/person.c"
#include "../src/ship.c"
#include "../src/fault.c"


void defaultInfo();
int display();

int main() {
    
    
    defaultInfo();
    readPerson(people);
    display();

}
int display(){
    Person *account = (Person *)malloc(sizeof(Person));
    int isLoggedIn=0;

    while(1) {
   
    
    
    printf("Number of users read: %d\n", userCount);
    // Kullanıcı girişi için örnek
    char username[50];
    char password[50]; 
    

    // Örnek kullanıcı oluşturuldu, gerçek kullanıcı doğrulama burada yapılacak
    
    
    
    Ship *ship = malloc(sizeof(Ship));
    ship->shipID=1;
    strcpy(ship->shipName, "abc");
    ship->oilPressure;
    ship->waterTemp;
    ship->waterLevel;
    Fault faults[100];
    int faultCount=5;
 

    
    

    // Kullanıcı doğrulama
         

        if (account->type== 0 && isLoggedIn) {

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
                    
                    waterTempControl(ship, faults, waterTemp);
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
                    int faultID;
                    printf("Enter fault ID ");
                    scanf("%d", &faultID);
                    assignDuzeltmeGorevlisi(faults,faultID, personID); // İlgili metodu çağırın
                    break;
                }
                case 4: {
                    // Atanan Hataları Listeleme
                    int personID;
                    printf("Enter person ID: ");
                    scanf("%d", &personID);
                    listAssignedFaults(faults, faultCount, personID); // İlgili metodu çağırın
                    break;
                }
                case 0:
                    printf("Exiting...\n");
                    isLoggedIn=0;
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } while (choice != 0);
    } else if (account->type==1 && isLoggedIn) {
        // Düzeltme Görevlisi Kontrol Paneli
        int choice;
        do {
            printf("Please enter a choice:\n");
            printf("1) List Self-Assigned Faults\n");
            printf("2) Marking Self-Assigned Faults as Repaired\n");
            printf("0) Exit\n");
            printf("Choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    // Kendine Atanan Hataları Listeleme
                    listAssignedFaults(faults, faultCount, account->personID); // İlgili metodu çağırın
                    break;
                }
                case 2: {
                    // Kendine Atanan Hataları Çözüldü Olarak İşaretleme
                    int personID;
                    printf("Enter person ID: ");
                    scanf("%d", &personID);
                    markFaultsAsRepairedByPersonID(faults, faultCount, personID); // İlgili metodu çağırın
                    break;
                }
                case 0:
                    printf("Exiting...\n");
                    isLoggedIn=0;
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } while (choice != 0);
    } else {
         printf("\nEnter your username: ");
               
                fflush(stdin);
                gets(username);

                
                printf("Enter your password: ");
                
                fflush(stdin);
                gets(password);

                
                printf("\nLogging in...\n\n");
                
                account = login(username, password);
                if (account != NULL)
                {
                    isLoggedIn = 1;
                    
                }
                else
                {
                 
                    printf("User not found! Please try again.\n");
                    
                    continue;
                }
                
    }
}return 0;
    }

    


void defaultInfo() {

    Person *person0 = createPerson(1, "beyza", "beyza", "123", KONTROL_GOREVLISI);
    Person *person1 = createPerson(2, "gonul", "gonul", "123", DUZELTME_GOREVLISI);
    Person *person2 = createPerson(3, "yusuf", "yusuf", "123", DUZELTME_GOREVLISI);
    Person *person3 = createPerson(4, "yasar", "yasar", "123", DUZELTME_GOREVLISI);
    Person *person4 = createPerson(5, "a", "a", "123", DUZELTME_GOREVLISI);
    Person *person5 = createPerson(6, "b", "b", "123", DUZELTME_GOREVLISI);
    Person *person6 = createPerson(7, "c", "c", "123", DUZELTME_GOREVLISI);
}

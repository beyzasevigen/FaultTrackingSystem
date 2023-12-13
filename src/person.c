#include "../headers/person.h"


int insertPerson(Person person);

Person *createPerson(int personID, const char *personName, const char *username, const char *password, enum PersonType type) {
    Person *newPerson = (Person*)malloc(sizeof(Person));

    if (newPerson == NULL) {
        // Bellek tahsisi başarısız oldu
        return 0;
    }

    newPerson->personID = personID; 
    strncpy(newPerson->personName, personName, sizeof(newPerson->personName) - 1);
    strncpy(newPerson->username, username, sizeof(newPerson->username) - 1);
    strncpy(newPerson->password, password, sizeof(newPerson->password) - 1);
    newPerson->type = type;
    insertPerson(*newPerson);
    people[userCount] = *newPerson;
    userCount++;

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

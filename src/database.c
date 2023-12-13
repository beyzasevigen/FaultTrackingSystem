#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/person.h"


Person people[50];
int userCount=0;

int insertPerson(Person person)
{
    FILE *file = fopen("person.txt", "a");

    if (file == NULL)
    {
        printf("Error while opening the file!");
        return 1;
    }
    fprintf(file, "%d\n", person.personID);
    fprintf(file, "%s\n", person.personName);
    fprintf(file, "%s\n", person.username);
    fprintf(file, "%s\n", person.password);

    fclose(file);
    return 0;
}

int readPerson(Person *persons){
    FILE *file = fopen("person.txt", "r");

    if (file == NULL)
    {
        printf("Error while opening the file!");
        return 1;
    }

    userCount = 0;

    while (fscanf(file, "%d\n%s\n%s\n%s\n", 
                  &persons[userCount].personID, 
                  persons[userCount].personName, 
                  persons[userCount].username, 
                  persons[userCount].password) == 4)
    {
        userCount++;
    }

    fclose(file);
    return 0;
}

int deletePersonFromFile(int personID) {
    FILE *inputFile = fopen("person.txt", "r");
    FILE *outputFile = fopen("temp_person.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error while opening the file!\n");
        return 1;
    }

    Person currentPerson;

    // Dosyadan kişileri oku ve silmek istediğimiz kişiyi dışarıda tut
    while (fscanf(inputFile, "%d %s %s %s %d",
                  &currentPerson.personID,
                  currentPerson.personName,
                  currentPerson.username,
                  currentPerson.password,
                  &currentPerson.type) == 5) {

        if (currentPerson.personID != personID) {
            // Silmek istediğimiz kişiyi dışarıda tut
            fprintf(outputFile, "%d %s %s %s %d\n",
                    currentPerson.personID,
                    currentPerson.personName,
                    currentPerson.username,
                    currentPerson.password,
                    currentPerson.type);
        }
    }

    // Dosyaları kapat
    fclose(inputFile);
    fclose(outputFile);

    // Orjinal dosyayı sil ve geçici dosyayı orijinal adıyla yeniden adlandır
    remove("person.txt");
    rename("temp_person.txt", "person.txt");

    return 0;
}


/*void loadPeopleDataFromFile() {
    FILE *file = fopen("person.txt", "r");
    if (file == NULL) {
        printf("person information cannot read!\n");
        return;
    }

    // Dosyadan verilerini okuyun ve veritabanına ekleyin
    while (fscanf(file, "%d %s %s %s %d", 
    &people[userCount].personID, 
    people[userCount].personName, 
    people[userCount].username, 
    people[userCount].password, 
    (int *)&people[userCount].type) == 5) {
        userCount++;
    }

    fclose(file);
}*/

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
    fprintf(file, "%d ", person.personID);
    fprintf(file, "%s ", person.personName);
    fprintf(file, "%s ", person.username);
    fprintf(file, "%s\n ", person.password);
   
    //fprintf(file, "%d\n", person.type);

    fclose(file);
    return 0;
}

int readPerson(){

    FILE *file = fopen("person.txt", "r");

    if (file == NULL)
    {
        printf("Error while opening the file!");
        return 1;

    }

    userCount = 0;

    while (fscanf(file, "%d %s %s %s\n", 
                  &people[userCount].personID, 
                  people[userCount].personName, 
                  people[userCount].username, 
                  people[userCount].password) == 4
                  )
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
    int found = 0;

    // Dosyadan kişileri oku ve silmek istediğimiz kişiyi dışarıda tut
    while (fscanf(inputFile, "%d %s %s %s %d",
                  &currentPerson.personID,
                  currentPerson.personName,
                  currentPerson.username,
                  currentPerson.password,
                  &currentPerson.type) == 5) {

        if (currentPerson.personID == personID) {
            found=1;
        } else {
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

    if (found) {
        readPerson();
    }

    return 0;
}

Person *login(char *username, char *password)
{

    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(people[i].username, username) == 0 && strcmp(people[i].password, password) == 0)
        {
            return &people[i];
        }
    }
    Person *nullP = NULL;
    return nullP;
}






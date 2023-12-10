#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/person.h"

int insertPerson(Person person)
{
    FILE *file = fopen("../txtFiles/person.txt", "a");

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

int readPerson(Person *persons, int *personCount)
{
    FILE *file = fopen("../txtFiles/person.txt", "r");

    if (file == NULL)
    {
        printf("Error while opening the file!");
        return 1;
    }

    int i = 0;
    while (fscanf(file, "%d\n%s\n%s\n%s\n", 
                  &persons[i].personID, 
                  persons[i].personName, 
                  persons[i].username, 
                  persons[i].password) == 4)
    {
        i++;
    }

    *personCount = i;

    fclose(file);
    return 0;
}

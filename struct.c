#include <stdio.h>
#include "struct.h"
#include <string.h>

TODO todos[100];



//input title
void title() {
    for (int i = 0; i < 100; i++) {
        char name[20];
        printf("Titel eingeben:");
        scanf("%s", name);
        fgets(name, sizeof(name), stdin);
        strcpy(todos[i].header, name);
        char description[500];
        printf("Beschreibung hinzufuegen:\n");
        scanf("%s", description);
        fgets(description, sizeof(description) ,stdin);
        strcpy(todos[i].description, description);

for (int j = 0; description[j] != '\0'; j++) {
    if (description[j] == '\n' || description[j] == ' ')description[j] = '_';
}

        printf("(%d) %s \n ---------- \n Beschreibung: %s \n",i, todos[i].header, todos[i].description);
        int a;
        printf("Fortfahren?\n");
        scanf("%d", &a);

        //printf("Debugging: %s", todos[2].header);


    }
}

void description() {

}
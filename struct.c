#include <stdio.h>
#include "struct.h"
#include <string.h>

TODO todos[100];
//Aufgaben anyeigen
void Tasks(){
    FILE *fp = fopen("saves.txt", "r");
if (fp == NULL) {
    printf("Fehler bei lesen der Datei!\n");
    return;

}
char line[300];//Max pro Zeile
printf("Aufgaben: \n");
while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
}
fclose(fp);
 }



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
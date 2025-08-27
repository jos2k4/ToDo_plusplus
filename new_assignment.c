#include "struct.h"

//create a assignment
void newAssignment() {

    FILE *f = fopen("saves.txt", "a");
    if (f == NULL) {
        printf("Fehler");
        return;
    }

    FILE *l = fopen("log.txt", "a");
    if (!l) {perror("log.txt"); fclose(f); return;}


    for (int i = 0; i < 100; i++) {
        char name[50];
        char description[500];

        read_line("Titel eingeben: ", name, sizeof(name));
        if (name[0] == '\0')break;

        read_line("Description: ", description, sizeof(description));
        if (description[0] == '\0')break;


        //kopieren der Eingabe in struct
        strncpy(todos[i].header, name , sizeof(todos[i].header));
        todos[i].header[sizeof(todos[i].header) -1] = '\0';

        strncpy(todos[i].description, description, sizeof(todos[i].description));
        todos[i].description[sizeof(todos[i].description) -1] = '\0';



        printf("(%d) Titel: %s || Beschreibung: %s \n",i, todos[i].header, todos[i].description);
        //Backup in Datei
        fprintf(f,"(%d) Titel: %s || Beschreibung: %s \n",i, todos[i].header, todos[i].description);

        fflush(f);




        fprintf(l,"[%s] AUFGABE ERSTELLT: (%d) [%s || %s]\n",currentTime(), i, todos[i].header, todos[i].description);

        fflush(l);


        //Fortfahren?
        char line[16];
        read_line("Fortfahren ? (1 = ja / 0 = nein): " ,line, sizeof(line));
        if (line[0] == '0')break;

        //printf("Debugging: %s", todos[2].header);

    }
    fclose(f);
    fclose(l);
}
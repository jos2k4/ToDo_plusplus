#include <stdio.h>
#include "struct.h"
#include <string.h>
#include "date_time.h"

TODO todos[100];
//Aufgaben anzeigen
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


static void read_line(const char *promt, char *buf, size_t n) {
    if (promt) printf("%s",promt);
    if (!fgets(buf,n,stdin)) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf,"\n")] = '\0';

}



//input title
void title() {
FILE *f = fopen("saves.txt", "a");
    if (f == NULL) {
        printf("Fehler");
        return;
    }

FILE *l = fopen("log.txt", "a");
    if (!l) {perror("log.txt"); fclose(f); return;}


    for (int i = 0; i < 100; i++) {
        char name[20];
        char description[500];

        read_line("Titel eingeben: ", name, sizeof(name));
        if (name[0] == '\0')break;

        read_line("Description: ", description, sizeof(description));
        if (description[0] == '\0')break;

        char deadline[20];
        read_line("Deadline (DD-MM-YYYY HH:MM): ", deadline, sizeof(deadline));
        if (deadline[0] == '\0') break;




        //kopieren der Eingabe in struct
        strncpy(todos[i].header, name , sizeof(todos[i].header));
        todos[i].header[sizeof(todos[i].header) -1] = '\0';

        strncpy(todos[i].description, description, sizeof(todos[i].description));
        todos[i].description[sizeof(todos[i].description) -1] = '\0';


        strncpy(todos[i].deadline, deadline, sizeof(todos[i].deadline));
        todos[i].deadline[sizeof(todos[i].deadline)-1] = '\0';

        printf("(%d) %s \n ---------- \n Beschreibung: %s \n Deadline: %s\n",i, todos[i].header, todos[i].description,todos[i].deadline);
        //Backup in Datei
        fprintf(f,"(%d) Titel: %s \n Beschreibung: %s \n Deadline: %s\n",i, todos[i].header, todos[i].description, todos[i].deadline);

        fflush(f);




        fprintf(l,"[%s] AUFGABE ERSTELLT: (%d) [%s || %s || %s ]\n",currentTime(), i, todos[i].header, todos[i].description, todos[i].deadline);

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

void description() {

}
void cleanupTask()
{
    FILE *f = fopen("saves.txt", "r");
    if (!f) return;
    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {fclose(f); return;}

    char header[200], description[500], deadline[50];
    int id;
    while (fscanf(f, "(%d) Titel: %[^\n]\n Beschreibung: %[^\n]\n Deadline: %[^\n]\n", &id , header, description, deadline) == 4)
    {
        if (!isPastDeadline(deadline))
        {
            fprintf(temp,"(%d) Titel: %s\n Beschreibung: %s\n Deadline: %s\n", id, header, description, deadline);
        }else
        {
            printf("Aufgabe \"%s\" geloescht. Deadline wurde ueberschritten)\n" , header, deadline);
        }
    }
    fclose(f);
    fclose(temp);
    remove("saves.txt");            //alte Datei loeschen
    rename("temp.txt", "saves.txt");
}
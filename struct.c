#include <stdio.h>
#include "struct.h"
#include <string.h>
#include "date_time.h"


//definition of read_linw
static void read_line(const char *promt, char *buf, size_t n) {
    if (promt) printf("%s",promt);
    if (!fgets(buf,n,stdin)) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf,"\n")] = '\0';
}

//Aufgaben anzeigen
void showAssignments(){

    FILE *fp = fopen("saves.txt", "r");
    if (fp == NULL) {
        printf("Error reading file saves.txt!\n");
        return;
    }

char line[300];//Max pro Zeile
printf("All Assignments: \n");
while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
}
fclose(fp);
 }
void cleanupAssignments()
{
    FILE *f = fopen("saves.txt", "r");
    if (!f) return;
    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {fclose(f); return;}

    char header[200], description[500], deadline[50];
    int id;
    while (fscanf(f, "|%*d| (%d) Header: %[^|] || Description: %[^|] || Deadline: %[^\n]\n", &id , header, description, deadline) == 4)
    {
        if (!PastDeadline(deadline))
        {
            fprintf(temp,"|%d| (%d) Header: %s || Description: %s || Deadline: %s\n", id, id, header, description, deadline);
        }else
        {
            printf("Aufgabe \"%s\" geloescht. Deadline wurde ueberschritten)\n" , header);
        }
    }
    fclose(f);
    fclose(temp);
    remove("saves.txt");            //alte Datei loeschen
    rename("temp.txt", "saves.txt");
}
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

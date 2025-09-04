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
 //split assignments
void cleanupAssignments()
{
    FILE *f = fopen("saves.txt", "r");
    if (!f) { printf("Error reading file!\n");return;}
    FILE *fopen_out = fopen("open.txt", "w");
    //past deadline = closed.txt
    FILE *fclosed_out = fopen ("closed.txt", "w");
    if (!fopen_out || !fclosed_out) {
      printf("Error creating file!\n");
      if (fopen_out) fclose(fopen_out);
      if (fclosed_out) fclose(fclosed_out);
      fclose(f);
      return;
    }

   char line[2000];
    while (fgets(line, sizeof(line), f))
    {
        int id_left = 0, idx = 0;
        char header[200],description[500], deadline[50];
        if (line[0] == '\n' || line[0] == '\r')
        {
            continue;
        }

        int got = sscanf(line,
        "|%d| (%d) Header: %199[^|] || Description: %499[^|] || Deadline: %49[^\r\n]", &id_left , &idx, header, description, deadline);
        if (got !=5)
        {
            continue;
        }


            if (!PastDeadline(deadline))
            {
                fprintf(fopen_out,"|%d| (%d) Header: %s || Description: %s || Deadline: %s\n", id_left, idx, header, description, deadline);
            }else
            {
                fprintf(fclosed_out, "|%d| (%d) Header: %s || Description: %s || Deadline: %s\n", id_left, idx, header, description, deadline);
            }

    }
    fclose(f);
    fclose(fopen_out);
    fclose(fclosed_out);
   printf("Open entries saved in \"open.txt\", expiered ones in \"closed.txt\". \n");
}
#include <stdlib.h>
#include <string.h>
#include "struct.h"

static long read_max_id_from_file(const char *path) {
    long max_id = -1;
    FILE *file = fopen(path, "r");
    if (!file) return -1;

    char line[1024];
    while (fgets(line, sizeof(line), file)) {

        char *p = strchr(line, '|');
        if (!p) continue;
        char *q = strchr(p + 1, '|');
        if (!q) continue;

        char saved = *q;
        *q = '\0';
        char *endptr = NULL;
        long id = strtol(p + 1, &endptr, 10);
        *q = saved;

        if (endptr == q && id > max_id) max_id = id;
    }
    fclose(file);
    return max_id;
}

//create a assignment
void newAssignment() {

    const char *path = "saves.txt";
    static int next_id = -1;

    if (next_id < 0) next_id = (int)read_max_id_from_file(path) +1;

    FILE *f = fopen("saves.txt", "a");
    if (f == NULL) {
        printf("Fehler");
        return;
    }

    FILE *l = fopen("log.txt", "a");
    if (!l) {perror("log.txt"); fclose(f); return;}


    for (int i = read_max_id_from_file("saves.txt") + 1; i < read_max_id_from_file("saves.txt") + 2; i++) {
        char name[50];
        char description[500];

        read_line("header: ", name, sizeof(name));
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

        todos[i].status = 0;

        todos[i].id = next_id++;

        printf("id = %d (%d) Header: %s || Description: %s || Deadline: %s \n",todos[i].id, i, todos[i].header, todos[i].description, todos[i].deadline);
        //Backup in Datei
        fprintf(f,"|%d| (%d) Header: %s || Description: %s || Deadline: %s \n",todos[i].id, i, todos[i].header, todos[i].description, todos[i].deadline);

        fflush(f);




        fprintf(l,"[%s] ASSIGNMENT CREATED: id = %d (%d) [%s || %s || %s ]\n",currentTime(),todos[i].id, i, todos[i].header, todos[i].description, todos[i].deadline);

        fflush(l);
        //i = todos[i].id;


        //Fortfahren?
        char line[16];
        read_line("Continue ? (1 = yes / 0 = no): " ,line, sizeof(line));
        if (line[0] == '0')break;

        //printf("Debugging: %s", todos[2].header);

    }
    fclose(f);
    fclose(l);
}
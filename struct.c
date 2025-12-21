#include "struct.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int readTODOS()
{
    FILE *saves = fopen("../saves.txt", "r");
    if (saves == NULL)perror("Problems opening saves.txt in struct.c/readTODOS please contact devs");

    int i = 0;
    char temp_header[100];
    char temp_description[100];
    int temp_id;
    while (i <  100 && fscanf(saves, "%s %s %d", temp_header, temp_description, &temp_id ) == 3)
    {
        todos[i].header = malloc(strlen(temp_header)+1);
        strcpy(todos[i].header, temp_header);

        for (int j = 0; j< strlen(temp_description); j++)
        {
            if (temp_description[j] == '-')temp_description[j] = ' ';
        }

        todos[i].description = malloc(strlen(temp_description) + 1);
        strcpy(todos[i].description, temp_description);

        todos[i].id = temp_id;
        i++;
    }
    fclose(saves);
    return i;
//test

}

void listTODOS()
{
    int anzahl = readTODOS();
    readTODOS();
    printf("*--------------------------------------*\n");
    for (int j = 0; j < anzahl; j++)
    {
        printf("(%d) %s - %s\n", todos[j].id, todos[j].header, todos[j].description);
    }
    printf("*--------------------------------------*\n");

}

void pushTODOS(char temp_header[100] , char temp_description[100], int temp_id)
{

    //swap spaces with - so the program can read it
    for (int i = 0; i < strlen(temp_description); i++)
    {
        if (temp_description[i] == ' ')temp_description[i] = '-';
    }

    //reserve memory for descrion
    char *description = malloc(strlen(temp_description) + 1);
    strcpy(description, temp_description);


    FILE *saves = fopen("../saves.txt","a");
    if (saves == NULL)perror("Problems opening saves.txt in struct.c/pushTODOS please contact devs");


    //print array in file
    fprintf(saves, "%s %s %d", temp_header, description, temp_id);
fclose(saves);

}

void deleteTODOS(int id_to_delete)
{
    int max_nr = readTODOS();

    int found_index = -1;

    // search array for given id
    for (int i = 0; i < max_nr; i++) {
        if (todos[i].id == id_to_delete) {
            found_index = i;
            break;
        }
    }

    // if not found return
    if (found_index == -1) {
        printf("ID %d nicht gefunden!\n", id_to_delete);
        return;
    }

    //clears the file
    FILE *delete = fopen("../saves.txt", "w");
    if (delete == NULL)perror("Problems with clearing saves.txt in struct.c/deleteTODOS please contact devs");
    fclose(delete);

    //overwrites assignment with given id
    for (int j = found_index; j < max_nr - 1; j++)
    {
        todos[j].header = todos[j+1].header;
        todos[j].description = todos[j+1].description;
        todos[j].id = todos[j-1].id;

    }

    //decrease the array by 1
    max_nr--;

    //print new array in file
    for (int i = 0; i < max_nr ; i++)pushTODOS(todos[i].header, todos[i].description, todos[i].id);


    printf("Todo %d successfully deleted\n", found_index);

}
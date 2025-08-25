#include <stdio.h>
#include "struct.h"
#include <string.h>

TODO todos[100];

//input title
void title() {
    for (int i = 0; i < 100; i++) {
        char name[20];
        printf("Titel eingeben:");
        scanf("%s",name);
        strcpy(todos[i].header, name);
        printf("(%d) %s \n",i, todos[i].header);


    }
}

void description() {

}
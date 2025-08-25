#include <stdio.h>
#include "struct.h"
#include <string.h>

TODO todos[100];

//input title
void title() {
    for (int i = 0; i < 100; i++) {
        strcpy(todos[i].header, " ");
    }
}
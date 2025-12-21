#ifndef STRUCT_C
#define STRUCT_C


typedef struct TODO{
    int id;
    char *header;    //working
    char *description;  //working
    char *deadline;
    //char editor[15];      //later
    //int duration;         //later
    int status; //0 = open, 1= finished //in progress
}TODO;

TODO todos[100];

int readTODOS();
void listTODOS();
void pushTODOS();
void deleteTODOS();


#endif
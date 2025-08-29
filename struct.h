#ifndef STRUCT_C
#define STRUCT_C


typedef struct TODO{
    int id;
    char header[50];    //working
    char description[500];  //working
    char deadline[20];
    //char editor[15];      //later
    //int duration;         //later
    int status; //0 = open, 1= finisched //in progress
}TODO;

TODO todos[100];


#endif
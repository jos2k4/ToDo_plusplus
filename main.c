#include "struct.c"
#include "new_assignment.c"
#include "date_time.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//
int main(){
for (;;) {


  int i = -1;
  char line[64];
  printf(todos[4].header);
  printf("/main \n");
  printf("Welcome. How do you want to continue? \n");
  printf("(1) List all Assignments \n(2) Create a new Assignment \n(3) List all open Assignments \n(4) still in development \n(5) exit program \n");

  read_line("Your choice: ", line, sizeof(line));
  i = (int) strtol(line, NULL, 10);


  switch(i) {
    case 1:
      printf("/main/all_assignments \n");
      showAssignments();
      cleanupAssignments();
      //printf("<-- back");
      //scanf("%d",&i);
    break;
    case 2:
      printf("/main/new_assignment \n");
      newAssignment();

    break;
    case 3:
      printf("/main/open_assignments \n");
    break;
    case 4:
      printf("/main/dev \n");
    break;
    case 5:
      printf("See you!");
      return 0;
      break;


    default:
      printf("ERROR");
  }


}


}

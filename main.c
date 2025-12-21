#include "struct.h"
#include <stdio.h>


int user_input(int i)
{
  switch(i) {
  case 1:
    printf("/main/all_assignments \n");

    listTODOS();

    break;
  case 2:
    printf("/main/new_assignment \n");
    pushTODOS();

    break;
  case 3:
    printf("/main/open_assignments \n");
    break;
  case 4:
    printf("/main/dev \n");

    break;

  case 5:
    return 0;
    break;


  default:
    printf("ERROR");
  }
}

int main(){

  for (;;)
{
  int i;
  printf("/main \n");
  printf("Welcome. How do you want to continue? \n");
  printf("(1) List all Assignments \n(2) Create a new Assignment \n(3) List all open Assignments \n(4) still in development \n(5) exit program \n");
  scanf("%d", &i);
user_input(i);
    int exit_flag = user_input(i);
    if (exit_flag == 0)return 0;

}
}



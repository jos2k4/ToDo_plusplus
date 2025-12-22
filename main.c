#include "struct.h"
#include <stdio.h>

int user_input(int i)
{
  switch(i) {
  case 1:
    //List all assignments
    printf("/main/all_todos \n");

    listTODOS();


    break;
  case 2:
    //create a new assignment
    printf("/main/new_todo \n");

    int temp_id = readTODOS() + 1;
    char temp_header[100];
    char temp_description[100];
    printf("Header: ");
    fgets(temp_header, 100, stdin);
    printf("Description: ");
    fgets(temp_description, 100, stdin);

    pushTODOS(temp_header, temp_description, temp_id);


    break;
  case 3:
    //delete assignment
    printf("/main/delete_todo \n");
    listTODOS();
    int j;
    printf("Select ID to delete");
    scanf(" %d", &j);
    deleteTODOS(j);
    listTODOS();

    break;
  case 4:
    printf("/main/dev \n");

    break;

  case 5:
    return 0;
    break;


  default:
    perror("Error in user input");
  }

  return 1;

}

int main(){
readTODOS();
  printf("Welcome. How do you want to continue? \n");

  for (;;)
{
  int i;
  printf("/main \n");
  printf("(1) List all Assignments \n(2) Create a new Assignment \n(3) Delete a Assignment \n(4) still in development \n(5) exit program \n");
  scanf("%d", &i);
    getchar();
//user_input(i);
    int exit_flag = user_input(i);
    if (exit_flag == 0)return 0;

}
}



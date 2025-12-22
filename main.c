#include "struct.h"
#include <stdio.h>

int user_input(int i)
{
  switch(i) {
  case 1:
    printf("/main/all_todos \n");

    listTODOS();

    break;
  case 2:
    printf("/main/new_todo \n");

    int temp_id = readTODOS() + 1;
    char temp_header[100];
    char temp_description[100];
    printf("Header: ");
    scanf("%s", temp_header);
    printf("Description: ");
    scanf(" %[^\n]", temp_description);

    pushTODOS(temp_header, temp_description, temp_id);

    break;
  case 3:
    printf("/main/delete_todo \n");
    //listTODOS();
    int i;
    printf("Select ID to delete");
    scanf(" %d", &i);
    deleteTODOS(i);
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

}

int main(){
readTODOS();
  for (;;)
{
  int i;
  printf("/main \n");
  printf("Welcome. How do you want to continue? \n");
  printf("(1) List all Assignments \n(2) Create a new Assignment \n(3) Delete a Assignment \n(4) still in development \n(5) exit program \n");
  scanf("%d", &i);
user_input(i);
    int exit_flag = user_input(i);
    if (exit_flag == 0)return 0;

}
}



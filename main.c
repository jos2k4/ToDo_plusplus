#include "struct.c"
#include "new_assignment.c"
#include "date_time.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
for (;;) {
  int i = -1;
  char line[64];
  /*printf(todos[0].header);    DEBUGGING
  printf(todos[1].header);
  printf(todos[2].header); */
  printf("/main \n");
  printf("Willkommen. Wie moechten Sie fortfahren? \n");
  printf("(1) Alle Aufgaben anzeigen \n(2) Neue Aufgabe erstellen \n(3) Offene Aufgaben anzeigen \n(4) Aufgabe nach Bearbeiter suchen \n(5) Programm beenden \n");

  read_line("Auswahl: ", line, sizeof(line));
  i = (int) strtol(line, NULL, 10);


  switch(i) {
    case 1:
      printf("/main/alle_aufgaben \n");
      showAssignments();
      //printf("<-- back");
      //scanf("%d",&i);
    break;
    case 2:
      printf("/main/neu_aufgaben \n");
      newAssignment();

    break;
    case 3:
      printf("/main/offene \n");
    break;
    case 4:
      printf("/main/bearbeiter \n");
    break;
    case 5:
      printf("Auf Wiedersehen!");
      return 0;
      break;


    default:
      printf("Fehler");
  }


}


}

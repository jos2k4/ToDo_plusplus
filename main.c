#include "struct.c"
#include "date_time.c"
#include <stdio.h>
#include <stdlib.h>

int main(){
for (;;) {
  int i = -1;
  char line[64];
  printf("/main \n");
  printf("Willkommen. Wie moechten Sie fortfahren? \n");
  printf("(1) Alle Aufgaben anzeigen \n(2) Neue Aufgabe erstellen \n(3) Offene Aufgaben anzeigen \n(4) Aufgabe nach Bearbeiter suchen \n");

  read_line("Auswahl: ", line, sizeof(line));
  i = (int) strtol(line, NULL, 10);


  switch(i) {
    case 1:
      printf("/main/alle_aufgaben \n");
    cleanupTask();
    Tasks();
      printf("<-- back");
      scanf("%d",&i);
    break;
    case 2:
      printf("/main/neu_aufgaben \n");
      title();

    break;
    case 3:
      printf("/main/offene \n");
    break;
    case 4:
      printf("/main/bearbeiter \n");
    break;


    default:
      printf("Fehler");
  }


}


}

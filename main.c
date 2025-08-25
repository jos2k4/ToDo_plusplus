#include "struct.c"
#include <stdio.h>

int main(){
while(1) {
  int i;
  printf("/main \n");
  printf("Wie moechten Sie fortfahren? \n");
  printf("(1) Alle Aufgaben anzeigen \n(2) Neue Aufgabe erstellen \n(3) Offene Aufgaben anzeigen \n(4) Aufgabe nach Bearbeiter suchen \n");
  scanf("%d",&i);
  printf("%d\n",i);


  switch(i) {
    case 1:
      printf("/main/alle_aufgaben \n");
      printf("<-- back");
      scanf("%d",&i);
    break;
    case 2:
      printf("/main/neu_aufgaben \n");
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
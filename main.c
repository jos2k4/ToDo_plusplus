#include "struct.c"
#include <stdio.h>

int main(){

  int i;
  printf("Wie moechten Sie fortfahren? \n");
  printf("(1) Alle Aufgaben anzeigen \n(2) Neue Aufgabe erstellen \n(3) Aufgabe nach Namen suchen \n(4) Aufgabe nach Bearbeiter suchen \n");
  scanf("%d",&i);
  printf("%d\n",i);

}
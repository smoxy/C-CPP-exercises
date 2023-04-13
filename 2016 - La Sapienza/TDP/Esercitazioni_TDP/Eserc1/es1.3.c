/* CONSEGNA
Esercizio 1.3

Scrivere un programma C che stampa sullo schermo il vostro nome, cognome e numero di matricola.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  char a[256];
  char b[256];
  int c=0;
  printf("Enter your Name: ");
  scanf("%s", a);
  printf("Enter your Surname: ");
  scanf("%s", b);
  printf("Enter your registration number : ");
  scanf("%d", &c);
  printf("\nYour data:\nName:\t\t%s\nSurname:\t%s\nID:\t\t%d\n", a, b, c);
	return 0; 
}

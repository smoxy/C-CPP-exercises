/**
   Argomenti Sintesi di programmi con cicli:
   - introduzione alle funzioni
   - struttura tipica di un ciclo
   - sintesi di due versioni di Massimo Comun Divisore
     - per sottrazioni ripetute (simpleMCD1 e 2)
     - con algoritmo dei resti (Euclide)

*/
#include <stdio.h>

/**
   Massimo comun divisore x, y
   d tale che x/d abbia resto nullo AND
          che y/d abbia resto nullo

   NOTA: IN TUTTI I PROGRAMMI SULL'MCD CHE SEGUONO ASSUMIAMO SEMPRE x>y.

*/

/*
  le due funzioni simpleMCD1 e simpleMCD2
  implementano un semplice algoritmo che
  decrementa un intero finche' questo non
  divide in maniera esatta i due argomenti della funzione (x e y).
*/

/*Variante 1: uso la condizione di terminazione  e la nego*/
int simpleMCD1(int x, int y) {
  int d=y; // questo sara' l'mcd;
  while ( !(!(x%d) && !(y%d)) )
      d--;
  return d;
}



/*Variante 2: uso la condizione di continuazione*/
int simpleMCD2(int x, int y) {
  int d=y; // questo sara' l'mcd;
  while ( (x%d) || (y%d) )
      d--;
  return d;
}



/* A proposito di MCD Euclide disse:
   
   mcd(x,y) = 
      y, se x%y==0
      mcd (y, r) altrimenti;

*/


/* Versione C di MCD (compatta)
*/
int euclideMCD(int x, int y) {
  while (x%y) {
    int r=x%y;
    x=y;
    y=r;
  }
  return y;
}



/*
  struttura generale di un ciclo
  <inizializzazione>
  <verifica condizione>
     < istruzioni >
     < perturbazione condizione>
*/

/*
  for (<inizializzazione>; <condizione>; <incremento>)
      <istruzione>;

  equivale a

  <inizializzazione>
  while(<condizione>){
     <istruzione>;
     <incremento>;
  }
**/

/*scriviamo l'algoritmo usando il for*/
int euclideMCDwithFor(int x, int y) {
  for (;x%y;) {
    int r=x%y;
    x=y;
    y=r;
  }
  return y;
}



/* Seguono altri esempi sul for*/

/*stampa N interi*/
void printFirstNNumbers(int N) {
  for (int i=1; i<=N; i++)
    printf("%d\n", i);
}

/*Stampa N interi saltando i dispari*/
void printFirstNNumbersSkippingOddOnes(int N) {
  for (int i=0; i<N; i+=2)
    printf("%d\n", i);
}

/*Stampa N interi saltando i dispari ed in ordine decrescente*/
void printFirstNNumbersSkippingOddOnesInRevertedOrder(int N) {
  for (int i=N-2; i>=0; i-=2)
    printf("%d\n", i);
}
 
/*stampa scacchiera di asterischi e spazi*/
void printCheckerboard(int side) {
  for (int r=0; r<side; r++){
    for (int c=0; c<side; c++)
      if( (r+c)%2)
	printf("-");
      else
	printf("*");
    printf("\n");
  }
}

/************************** ESERCIZIO **************************

Implementare una funzione che stampa una scacchiera di num_tiles*num_tiles mattonelle.
Ciascuna mattonella e' un quadratino di dimensione tile_size*tile_size

Esempio:   printCoolCheckerboard(4, 2) stampa questo:

**--**--
**--**--
--**--**
--**--**
**--**--
**--**--
--**--**
--**--**
*/


void printCoolCheckerboard(int num_tiles, int tile_size) {
  printf("please implement me\n");
  /* Scrivete qui la vostra soluzione */
}





int main (int argc, char** argv) {

  printf("\n\nSIMPLE MCD1\n");
  int x=30, y=20;
  int mcd=simpleMCD1(x,y);
  printf("simpleMCD %d, %d = %d\n", x, y, mcd );

  printf("\n\EUCLIDE MCD\n");
  mcd=euclideMCD(x,y);
  printf("euclideMCD %d, %d = %d\n", x, y, mcd );

  printf("\n\EUCLIDE MCD WITH FOR\n");
  mcd=euclideMCDwithFor(x,y);
  printf("euclideMCDwithFor %d, %d = %d\n", x, y, mcd );


  printf("\n PRINT FIRST N NUMBERS\n");
  printFirstNNumbers(10);

  printf("\n PRINT FIRST N NUMBERS, NO ODDS\n");
  printFirstNNumbersSkippingOddOnes(10);

  printf("\n PRINT FIRST N NUMBERS, NO ODDS, REVERSE\n");
  printFirstNNumbersSkippingOddOnesInRevertedOrder(10);
  
  printf("\n PRINT CHECKBOARD\n");
  printCheckerboard(10);

  printf("\n PRINT COOL CHECKBOARD\n");
  printCoolCheckerboard(3, 3);

}



/*************** NON LEGGERE QUI SOTTO ***************/

/* questa la una versione di MCD ricorsiva,
   acclamata a gran voce durante la lezione.

int recursiveMCD(int x, int y) {
  int r=x%y;
  if (!r) {
    return y;
  } else
    return recursiveMCD(y, r);
}

  // da aggiungere nel main
  mcd=recursiveMCD(x,y);
  printf("recursiveMCD %d, %d = %d\n", x, y, mcd );

*/

/****************************************************
tdp_00_00_variabili_funzioni_e_if_statement.c

  programma illustrativo sviluppato in classe durante 
  le lezioni

  Per compilare
  -> se si usa il compilatore gcc
  gcc -std=gnu99 -Wall -o primo tdp_00_00_variabili_funzioni_e_if_statement.c -lm     

  significato delle opzioni
   -std=gnu99   # setta come standard il recente c99
   -Wall        # abilita tutti i warning
   -o primo     # scrivi l'output sul file "primo"
   tdp_00_00_variabili_funzioni_e_if_statement.c # leggi il file tdp_00_00_variabili_funzioni_e_if_statement.c
   -lm          # linka la libreria matematica (libm.so)

  -> se si usa il compilatore g++
  g++ -Wall -o primo primo.c 

  significato delle opzioni
   -Wall        # abilita tutti i warning
   -o primo     # scrivi l'output sul file "primo"
   tdp_00_00_variabili_funzioni_e_if_statement.c       # leggi il file tdp_00_00_variabili_funzioni_e_if_statement.c
 
   Nota: g++ linka automaticamente con la libreria matematica

****************************************************/



/*
  questa roba qua sotto sono le  direttive del compilatore
*/
#include <stdio.h>
#include <math.h>



// questo e' cun commento su una linea

/* << qui incomincia
  questo e' un pratico commento su piu' linee

  qui finisce >> */  


/*intestazione di una funzione

  <tipo ritorno> <nome funzione> ( <lista parametri> )

  esempio;

  int main(int argc, char** argv)

*/


int parte_reale;

/*
  DICHIARAZIONE di funzione: serve a dire al compilatore che
  da qualche parte trovera' codice che implementa la funzione
  definita, e fornisce istruzioni su come
  preparare la sua invocazione.

  <intestazione di funzione>  ;		     
                             ^^^
			     nota il punto e virgola!

  esempio:
 

  int main(int argc, char** argv);


  In C (e C++) non e' legale invocare funzioni se queste non sono state almeno
  dichiarate.
  E' possibile invocate funzioni che siano 
   - dichiarate 
  oppure
  -  definite prima del punto di invocazione
*/


/*
  DEFINIZIONE di funzione: fornisce
  il "codice" che implementa la funzione;

  <intestazione di funzione>  {
    <istruzione 1>;
    <istruzione 2>;
    <istruzione 3>;
 }
 ^^^
 nota: le parentesi con le istruzioni della fuzione ne contengono il corpo.


 per l'esempio vedi sotto;
*/




//definizione della funzione main
int main (int argc, char** argv) {
  


/* dichiarazione di variabile
   <tipo> <nome>;

   NON E' POSSIBILE USARE UNA VARIABILE SE PRIMA
   NON LA SI E' DICHIARATA
 */

  int i=10;  // 
  int cosa=100;
  float f = 0.5;




/* stringhe di formattazione
   "<come stampo il primo argomento> <come stampo il secondo argomento> .. <come stampo l'argomento n>"

   intero: %d
   float: %f
   stringa: %s
   e tanti  altri da guardare sulle dispense

   Esempio: stampare la stringa

   "A vale <a> e b vale <b>"

   con: 
   <a> variabile intera
   <b> variabile float

   risulta nella seguente stringa di formattazione
   "A vale %d e b vale %f"

   la funzione  printf si invoca cosi;
   
   int a;
   float b;
   
   .. assegnazioni che mettono in a e b valori opportuni;

   printf("A vale %d e b vale %f", a, b);

*/

  // la riga sotto provova un warning perche' i non e' un float
  printf("cosa prima: %d , i vale %f \n", cosa, i);
  
  int altra_cosa;
  altra_cosa = cosa = (1+3)*i*cos(i);

  printf("cosa dopo: %d\n", cosa);
  
  /*

    operatori booleani

    a == b  // vera se a e b hanno lo stesso valore 
    a != b  // vera se a e b hanno lo valori diversi
    a > b
    a < b
    a >= b
    a <= b

    a && b //  a e b convertite a interi. Vera se entrambe vere
    a || b //  a e b convertite a interi. Vera se almeno una vera
    !a     //  a convertita a intero. vera se a e' falso, e false 
               se  a e' vero


   */


/*
  costrutto if

  if (<espressione booleana>)
    <istruzione>;
  

*/

  // if 1

  if (i) 
    printf("BB i: %d, cosa: %d, f: %f\n", i, cosa, f);
  
  i = 0;
  if (i) 
    printf("BB i: %d, cosa: %d, f: %f\n", i, cosa, f);

  
  // if 2
  
  i=0;
  cosa=8000;



/*
  costrutto if con else

  if (<espressione booleana>)
    <istruzione1>;
  else
    <istruzione2>;
*/

  if (!i && !cosa) 
    printf("1 i: %d, cosa: %d\n", i, cosa); // istruzione 1
  else 
    if (i && !cosa) 
      printf("2 i: %d, cosa: %d\n", i, cosa);
    else 
      if (!i && cosa) 
	printf("3 i: %d, cosa: %d\n", i, cosa);
      else if (i && cosa) 
	printf("4 i: %d, cosa: %d\n", i, cosa);


  /*

    blocco istruzioni: lista di istruzioni che vengono eseguite in sequenza
    (analogo al blocco di istruzioni indentate in python);

    {
     <istruzione 1>;
     <istruzione 2>;
     ....
     <istruzione n>;
    }

   */

  //float a=.5, b=10, c=2;
  float a=1, b=2, c=1;
  float det=b*b-4*a*c;
  if (det>0) {
    printf("ci sono due soluzioni reali e disgiunte\n");
    det=sqrt(det);
    float x1=(-b+det)/(2*a);
    float x2=(-b-det)/(2*a);
    printf("x1: %f, x2:%f\n", x1, x2);
  } else {
    if (det==0) {
      printf("ci sono due soluzioni reali e coincidenti\n");
      float x1=-b/(2*a);
      printf("x: %f\n", x1);
    } else if (det < 0) {
      printf("ci sono due soluzioni immaginarie coniugate\n");
      float parte_reale=-b/(2*a);
      float parte_immaginaria = sqrt(-det);
      printf("x1: %f+j%f\n ", parte_reale, parte_immaginaria);
      printf("x2: %f-j%f\n ", parte_reale, parte_immaginaria);
    }
  }
}


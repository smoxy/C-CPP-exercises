/****************************************************
tdp_01_00_visibilita_variabili_e_while.c

  programma illustrativo sviluppato in classe durante 
  le lezioni
  argomenti: 
  -visibilita' variabili
  -ciclo while


  Per compilare
  -> se si usa il compilatore gcc
  gcc -std=gnu99 -Wall -o secondo tdp_01_00_visibilita_variabili_e_while.c -lm     

  significato delle opzioni
   -std=gnu99   # setta come standard il recente c99
   -Wall        # abilita tutti i warning
   -o secondo     # scrivi l'output sul file "secondo"
   <nomefile.c>    # leggi il file <nomfile.c>
   -lm          # linka la libreria matematica (libm.so)

  -> se si usa il compilatore g++
  g++ -Wall -o primo primo.c 

  significato delle opzioni
   -Wall        # abilita tutti i warning
   -o secondo     # scrivi l'output sul file "secondo"
   <nomefile.c>    # leggi il file <nomfile.c>
 
   Nota: g++ linka automaticamente con la libreria matematica

****************************************************/

#include <stdio.h>
#include <math.h>

int main(int argc, char**argv) {
  int i =10;                        // reserve [abbastanza memoria per un
                                    //        intero]
                                    // pop(R1);
                                    //load R1, 10
                                    // push (R1);
  printf("i1: %d\n",i);                 
  {
    int i =84;                      // push [abbastanza memoria per un
                                    //        intero]
                                    // pop(R1);
                                    // load R1, 84
                                    // push (R1);


    printf("i2: %d\n",i);
  }                                 // free [memoria per un intero]
  printf("i3: %d\n",i);
  

  /*
    while (<espressione booleana>)
      istruzione;
   */


  /*
    semplice ciclo che stampa i valori da 0 a 9
   */
  int contatore=0;
  while(contatore<10){
    printf("%d\n", contatore);
    contatore++;
  }


  /*
    semplice ciclo che stampa 10 righe con i valori da 0 a 9
    (esempio di cicli annidati)
   */
  contatore=0;
  while(contatore<10){
    int contatore_2=0;
    while (contatore_2<10) {
      printf("%d ", contatore_2);
      contatore_2++;
    }
    printf("\n");
    contatore++;
  }

}


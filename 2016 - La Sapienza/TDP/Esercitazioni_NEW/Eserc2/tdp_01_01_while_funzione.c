/****************************************************
tdp_01_00_while_funzione.c

  programma illustrativo sviluppato in classe durante 
  le lezioni
  argomenti: 
  esempio di ciclo annidato per stampare i valori di una funzine
  z=sin(x)*cos(y), nell'intervallo [0..3]x[0..3], a passi di 0.1

*/

#include <stdio.h>
#include <math.h>

int main(int argc, char**argv) {
  float x=0;
  float intervallo=3;
  float passo=0.1;
  while (x<intervallo){
    float y=0;
    while (y<intervallo){
      float z=sin(x)*cos(y);
      printf("%f ",z);
      y+=passo;
    }
    x+=passo;
    printf("\n");
  }


  

}


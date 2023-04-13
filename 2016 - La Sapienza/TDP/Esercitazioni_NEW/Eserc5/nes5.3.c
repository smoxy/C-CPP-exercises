#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    void *a = (void*)malloc((sizeof(float)*3)+sizeof(char));
    
    printf("K = kelvin\nC = Celsius\nF = Fehrenheit\nInserisci l'iniziale della unità di misura: ");
    scanf("%c", (char*)(a+12));
    if (*(char*)(a+12)=='c' || *(char*)(a+12) =='C') {
        printf("Inserisci i gradi Celsius: ");
        scanf("%f", (float*)(a+4));
        *(float*)a = *(float*)(a+4) + 273.15;
        *(float*)(a+8) = *(float*)(a+4)*9/5 + 32;
    }
    else if (*(char*)(a+12)=='k' || *(char*)(a+12) =='K') {
        printf("Inserisci i gradi kelvin: ");
        scanf("%f", (float*)a);
        *(float*)(a+4) = *(float*)a - 273.15;
        *(float*)(a+8) = *(float*)(a+4)*9/5 + 32;
    }    
    else if (*(char*)(a+12)=='f' || *(char*)(a+12) =='F') {
        printf("Inserisci i gradi Fehrenheit: ");
        scanf("%f", (float*)(a+8));
        *(float*)(a+4) = ((*(float*)(a+8)) - 32)*5/9 ;
        *(float*)a = *(float*)(a+4) + 273.15;
    }
    else {
        printf("Carattere non valido");
        return -1;
    }
    printf("\nK = %.2f\nC = %.2f\nF = %.2f", *(float*)a, *(float*)(a+4), *(float*)(a+8));
    free(a);
    return 0;
}

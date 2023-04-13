#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    float *k = (float*)malloc(sizeof(float));
    float *c = (float*)malloc(sizeof(float));
    float *f = (float*)malloc(sizeof(float));
    char *l = (char*)malloc(sizeof(char));
    
    printf("K = kelvin\nC = Celsius\nF = Fehrenheit\nInserisci l'iniziale della unità di misura: ");
    scanf("%c", l);
    if (*l=='c' || *l =='C') {
        printf("Inserisci i gradi Celsius: ");
        scanf("%f", c);
        *k = *c + 273.15;
        *f = *c*9/5 + 32;
    }
    else if (*l=='k' || *l =='K') {
        printf("Inserisci i gradi kelvin: ");
        scanf("%f", k);
        *c = *k - 273.15;
        *f = *c*9/5 + 32;
    }    
    else if (*l=='f' || *l =='F') {
        printf("Inserisci i gradi Fehrenheit: ");
        scanf("%f", f);
        *c = (*f - 32)*5/9 ;
        *k = *c + 273.15;
    }
    else {
        printf("Carattere non valido");
        return -1;
    }
    printf("\nK = %.2f\nC = %.2f\nF = %.2f", *k, *c, *f);
    free(k); free(c); free(f); free(l);
    return 0;
}

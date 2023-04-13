#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    int *a = (int*)calloc(2, sizeof(int));
    printf("0 per terminare\nInserisci un numero: ");
    scanf("%d", &a[0]);
    a[1] = a[0];
    
    while (a[0] != 0) {
        printf("Inserisci un numero: ");
        scanf("%d", &a[0]);
        if (a[1] > a[0] && a[0]!= 0) {
            a[1] = a[0];
         }
    }
    printf("Il minimo numero è %d", a[1]);
    free(a);
    return 0;
}

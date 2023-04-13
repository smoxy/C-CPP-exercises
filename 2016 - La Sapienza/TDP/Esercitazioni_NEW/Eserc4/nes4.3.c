#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    int *n = (int*)malloc(sizeof(int));
    int *min = (int*)malloc(sizeof(int));
    
    printf("Inserisci un numero: ");
    scanf("%d", n);
    *min=*n;
    while(*n != 0) {
        printf("Inserisci un numero: ");
        scanf("%d", n);
        if (*n<*min && *n!=0) *min=*n;
    }
    printf("Il numero più piccolo è %d", *min);
    free(n); free(min);
    return 0;
}

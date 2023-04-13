#include<stdio.h>
#include<stdlib.h> // definizione di malloc e free

int main() {

    int *pa1, *pa2;

    // allocazione dinamica di memoria per pa1 e pa2
    pa1 = (int *)malloc(1*sizeof(int));
    pa2 = (int *)malloc(1*sizeof(int));
    
    *pa1=1; *pa2=2;

    // stampa gli indirizzi e i contenuti di pa1 e pa2
    printf("pa1=%p pa2=%p\n",pa1,pa2);
    printf("*pa1=%d *pa2=%d\n",*pa1,*pa2);
    
    // calcola la differenza degli indirizzi di memoria di pa1 e pa2
    int dptr = pa2 - pa1;
    printf("dptr=%d\n",dptr);
    // verifica se gli indirizzi sono adiacenti
    if (dptr==1)
        printf("memoria adiacente\n");
    else
        printf("memoria non adiacente\n");
            
    // rilascia la memoria allocata dinamicamente
    free(pa1); free(pa2);
    return 0;
}

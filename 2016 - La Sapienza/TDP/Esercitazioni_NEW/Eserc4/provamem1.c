#include<stdio.h>

int main() {

    // sizeof(int*) restituisce il numero di byte utilizzati per memorizzare
    // variabili di tipo puntatore a int (int *)
    int arch_bit = sizeof(int*)*8;
    printf("Architettura a %d bit\n",arch_bit);


    int a1=0, a2=0, a3=0, a4=0;
    
    printf("a1=%d a2=%d a3=%d a4=%d\n",a1,a2,a3,a4);
    
    *(&a1+1)=1;  // cosa fa questa istruzione?
                 // l'effetto di questa istruzione dipende dalle istruzioni seguenti
                 // perché?

    printf("a1=%d a2=%d a3=%d a4=%d\n",a1,a2,a3,a4);
    

    // cosa stampa se la condizione if è false?
    // cosa stampa se si commenta l'istruzione printf?
    if (1) {
        // stampa l'indirizzo di memoria di a3
        printf("indirizzo di a3 = %p\n",&a3);
    }
    
    // cosa stampa se la condizione if del blocco è false?
    // cosa stampa se si commenta questo blocco?
    if (1) {
        // stampa gli indirizzi di memoria di a1 e a4
        printf("&a1=%p &a4=%p\n",&a1,&a4);
        // calcola la differenza degli indirizzi di memoria di pa1 e pa2
        int dptr = &a4 - &a1;
        printf("dptr=%d\n",dptr);
        // verifica se gli indirizzi sono adiacenti
        if (dptr==1)
            printf("memoria adiacente\n");
        else
            printf("memoria non adiacente\n");
    }


    return 0;
}

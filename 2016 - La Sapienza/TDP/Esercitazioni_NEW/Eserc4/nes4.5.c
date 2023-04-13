#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    int a=1, b=1;
    int dptr = &a - &b;
    printf("la distanza fra questi 2 puntatori è %d oppure %ld\n\n", dptr, &b-&a);
    
    *(&b + dptr) = 34;
    printf("%d == 34", a);
    
    return 0;
}

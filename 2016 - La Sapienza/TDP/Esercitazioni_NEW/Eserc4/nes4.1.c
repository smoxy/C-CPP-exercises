#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    char c;
    short int hd;
    int d;
    long int ld;
    float f;
    double lf;
    printf("Tipo\t\tDimensione\tIndirizzo\nfloat\t\t%ld\t\t%p\n", sizeof(f), &f);
    printf("double\t\t%ld\t\t%p\n", sizeof(lf), &lf);
    printf("long int\t%ld\t\t%p\n", sizeof(ld), &ld);
    printf("int\t\t%ld\t\t%p\n", sizeof(d), &d);
    printf("short int\t%ld\t\t%p\n", sizeof(hd), &hd);
    printf("char\t\t%ld\t\t%p\n", sizeof(c), &c);
    return 0;
}

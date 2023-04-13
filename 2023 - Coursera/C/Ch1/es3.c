#include <stdio.h>

int main(void){
    float n;
    printf("The division of two mtegers results in an integer value, and any remainder is discarded.\n");

    n = 3/2;
    printf("3/2\t= %.2f\n", n);

    n = 3.0/2;
    printf("3.0/2\t= %.2f\n", n);
}
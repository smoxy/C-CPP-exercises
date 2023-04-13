#include <stdio.h>
#include <stdlib.h>

//Equazione di primo grado (retta)

int main (int argc, char **argv) {
	float a, b, x;
	printf("ax + b = 0\nInserisci i coefficienti 'a' e 'b'\n");
	scanf("%f %f", &a, &b);
	x = -(b/a);
	printf("x=%.2f\n", x);
	return 0;
}

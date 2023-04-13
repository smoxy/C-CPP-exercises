#include <stdio.h>
#include <stdlib.h>
//nes3.1.c

float newton(float n, float den);

int main (int argc, char **argv) {
	float n, x, den=1;
	printf("Di quale numero vuoi che trovi la radice quadrata? ");
	scanf("%f", &n);
	if (n<0) {
		printf("il numero non deve essere negativo!");
		return -1;
	}
	x = newton(n, den);
	printf("La radice del numero %.2f è %.2f", n, x);
	return 0;
}

float newton(float n, float den) {
	float den1;
	den1 = ((n/den)+den)/2;
	if (den==den1){
		return den1;
	}
	else return newton(n, den1);
}

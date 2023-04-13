#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int cont=1;
	float sum = 0.0;
	float a = 0.0;
	printf("Inserisci il %d° numero: ", cont);
	scanf("%f", &a);
	sum += a;
	cont++;
	while (a != 0) {
		printf("Inserisci il %d° numero: ", cont);
		scanf("%f", &a);
		sum += a;
		cont++;
	}
	printf("\nI numeri validi inseriti sono %d\nLa media aritmetica è %.2f", cont-2, sum/(cont-2));
	return 0;
}

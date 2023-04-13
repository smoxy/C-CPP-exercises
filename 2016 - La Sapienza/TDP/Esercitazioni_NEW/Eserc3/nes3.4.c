#include <stdio.h>
#include <stdlib.h>
//nes3.4.c
int main (int argc, char **argv) {
	float x, min;
	printf("Inserisci 0 per terminare\nInserisci un numero: ");
	scanf("%f", &x);
	min = x;
	
	while (x!=0) {
		printf("Inserisci un numero: ");
		scanf("%f", &x);
		if (x<min && x != 0) min=x;
	}
	
	printf("Il numero minimo è %f", min);
	
	return 0;
}

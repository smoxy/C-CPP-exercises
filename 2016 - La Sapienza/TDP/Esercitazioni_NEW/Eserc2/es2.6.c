#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Programma che converte un numero binario in un numero decimale,
 * la quantità delle cifre del numero binario è inserito da tastiera */

int main (int argc, char **argv) {
	unsigned int n, b, d;
	unsigned int c = 0;
	
	printf("Inserisci la quantità delle cifre del numero binario: ");
	scanf("%u", &n);
	while (c < n) {
		unsigned int tmp;
		printf("Inserisci bit del numero binario: ");
		scanf("%u", &b);
		tmp = d;
		d = b * pow(2,c);
		c++;
		d += tmp;
	}
	printf("Il numero decimale è %u", d);
	return 0;
}

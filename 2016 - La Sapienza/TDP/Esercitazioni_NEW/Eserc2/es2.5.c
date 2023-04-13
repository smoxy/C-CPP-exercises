#include <stdio.h>
#include <stdlib.h>

/* programma per calcolare il minimo comune multiplo di due numeri
 * interi positivi */

int main (int argc, char **argv) {
	unsigned int n1, n2;
	unsigned int m = 2;
	int end = 0;
	printf("Inserisci 2 numeri: ");
	scanf("%u %u", &n1, &n2);
	while (!end) {
		if (n1%m == 0) {
			end = (n2%m) == 0;
		}else {
			m++;
		}
	}
	printf("Il minimo comune multiplo di %u %u è %u", n1, n2, m);
	return 0;
}

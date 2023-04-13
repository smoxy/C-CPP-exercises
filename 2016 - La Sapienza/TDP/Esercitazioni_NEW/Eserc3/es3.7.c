#include <stdio.h>
#include <stdlib.h>

/* Stampa l'intera sequenza dei caratteri ASCII, con la scrittura
 * CARATTERE ; CODICE CARATTERE */

int main (int argc, char **argv) {
	int carattere = 0;
	while (carattere < 128) {
		printf("%c\t; %d\n", carattere, carattere);
		carattere++;
	}
	return 0;
}

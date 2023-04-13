#include <stdio.h>
#include <stdlib.h>

// Triangolo di Floyd

int main () {
	int r;		//Numero delle righe del triangolo di Floyd
	int n = 0;	//Numero viusalizzato nelle celle del triangolo
	int e = 1;	//Numero degli elementi per riga
	int c = 0;	//Contatore, il programma termina quando c>=r
	printf("Inserisci un numero maggiore di 0: ");
	scanf("%d", &r);
	while (r < 0) {
		printf("Inserisci un numero maggiore di 0: ");
		scanf("%d", &r);
	}
	while (c < r) {
		for (int i=0; i<e; i++) {
			++n;
			printf("%d ", n);
		}printf("\n"); c++; ++e;
	}
	return 0;
}

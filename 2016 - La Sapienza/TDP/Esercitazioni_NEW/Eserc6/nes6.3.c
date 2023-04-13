#include <stdio.h>
#include <stdlib.h>

void stampaAsterischi(int n);

int main (int argc, char **argv) {
	int n = 0;
	
	do {
		printf("inserisci un numero: "); scanf("%d", &n);
		stampaAsterischi(n);		
	} while (n!=0);
	return 0;
}

void stampaAsterischi(int n) {
	for (int i=0; i<n; i++) {
		printf("*");
	}
	printf("\n");
}

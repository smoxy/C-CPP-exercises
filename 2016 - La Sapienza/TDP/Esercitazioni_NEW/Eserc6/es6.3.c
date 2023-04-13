#include <stdio.h>
#include <stdlib.h>

void stampaAsterischi (int n);

int main () {
	int n = 0;
	printf("Inserisci un numero intero: ");
	scanf("%d", &n);
	while (n > 0) {
		stampaAsterischi(n);
		printf("Inserisci un numero intero: ");
		scanf("%d", &n);
	}
	return 0;
}

void stampaAsterischi (int n) {
	 for (int i=0; i<n; i++) printf("*");
	 printf("\n");
}

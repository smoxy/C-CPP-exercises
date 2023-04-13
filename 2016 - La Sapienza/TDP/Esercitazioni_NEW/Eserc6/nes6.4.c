#include <stdio.h>
#include <stdlib.h>

void stampaRigaAsterischi(int n, int fill);

int main (int argc, char **argv) {
	int n = 0, b;
	
	do {
		printf("inserisci un numero: "); scanf("%d %d", &n, &b);
		stampaRigaAsterischi(n, b);		
	} while (n!=0);
	return 0;
}

void stampaRigaAsterischi(int n, int fill) {
	if (fill) {
		for (int i=0; i<n; i++) {
			printf("*");
		}
		printf("\n");
	}
	else {
		for (int i=0; i<n; i++) {
			if (i==0 || i == n-1) printf("*");
			else printf(" ");
		}
		printf("\n");
		
	}
}

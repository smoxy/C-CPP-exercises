#include <stdio.h>
#include <stdlib.h>

void stampaRigaAsterischi(int n, int fill);
void stampaQuadrato(int n, int fill);

int main (int argc, char **argv) {
	int fill = 1;
	int n;
	printf("Inserisci lato del quadrato: ");
	scanf("%d", &n);
	printf("Inserisci 0 se vuoi solo la cornice: ");
	scanf("%d", &fill);
	stampaQuadrato(n, fill);
	return 0;
}

void stampaQuadrato(int n, int fill) {
	int mem = fill;
	int c = 0;
	if (fill == 0 && c==0) fill = 1;
	for (int i=0; i<n; i++) {		
		stampaRigaAsterischi(n, fill);
		fill = mem;
		c++;
		if (fill == 0 && c == (n-1)) fill = n;
	}
}

void stampaRigaAsterischi(int n, int fill) {
	if (fill != 0) {
		for (int j=0; j<n; j++) {
			printf("*");
		}printf("\n");
	}else {
		printf("*");
		if (n > 2) {
			for (int i=0; i<(n-2); i++) {
				printf(" ");
			}
		}printf("*\n");
	}
}

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int n = 0;
	printf("Inserisci la dimensione del lato del quadrato: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
		printf("*");	
		}printf("\n");
	}

	return 0;
}

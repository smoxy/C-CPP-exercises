#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int n = 0;
	printf("Inserisci la dimensione del lato del quadrato: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++) {			// riga(i)
		if (i==0 || i==(n-1)) {
			for (int j=0; j<n; j++) {
			printf("*");	
			}printf("\n");
		}			
		else {
			for (int j=0; j<n; j++) {	//colonna(j)
				if (j==0) {				//stampa "*" se è la prima colonna
					printf("*");
				}else if (j==(n-1)) {	//stampa "*" e vai a capo se è l'ultima colonna
					printf("*\n");
				}else {					//altrimenti stampa " "
					printf(" ");
				}
			}
		}
	}
	return 0;
}

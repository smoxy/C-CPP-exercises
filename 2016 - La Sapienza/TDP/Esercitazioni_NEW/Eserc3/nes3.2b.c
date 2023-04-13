#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int n=0, m=0;
	printf("Inserisci due numeri interi positivi\n");
	while (m<=0) {
		printf("1° numero: ");
		scanf("%d", &m);
	}
	printf("\nIl secondo numero deve essere un multiplo di %d\n", m);
	while (n<=0 || n%m!=0) {
		printf("2° numero: ");
		scanf("%d", &n);
	}
	for (int r=0; r<n*m; r++) {
		for (int c=0; c<n; c++) {
			if((c%2==0 && r%2==0) || (c%2!=0 && r%2!=0)) {
				for (int i=0; i<m; i++) printf("*");
				}
			else {
				for (int i=0; i<m; i++) printf("_");
				}
			if (c==n-1) printf("\n");
		}	
	}
	return 0;
}

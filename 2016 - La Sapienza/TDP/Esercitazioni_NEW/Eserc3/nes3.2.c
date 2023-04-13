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
	for (int r=0; r<n; r++) {
		if(r%2==0) { //se il blocco è pari
			for (int rc=0; rc<m; rc++) {
				for (int c=0; c<n; c++) {
					if(c%2==0) {
						for (int i=0; i<m; i++) printf("*");
					}
					else {
						for (int i=0; i<m; i++) printf("_");
					}
					if(c==n-1) printf("\n");
				}
			}
		}
		else {	//Se il blocco è dispari
			for (int rc=0; rc<m; rc++) {
				for (int c=0; c<n; c++) {
					if(c%2==0) {
						for (int i=0; i<m; i++) printf("_");
					}
					else {
						for (int i=0; i<m; i++) printf("*");
					}
					if(c==n-1) printf("\n");
				}
			}
		}
	}
return 0;
}

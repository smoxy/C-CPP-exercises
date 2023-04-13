#include <stdio.h>
#include <stdlib.h>

void stampa(short int *v, short int dim);

int main (int argc, char **argv) {
	short int n = 0;
	printf("Serie di Fibonacci\nInserisci la quantità dei primi numeri che vuoi stampare: ");
	scanf("%hd", &n);
	short int *A = (short int*)calloc(n,sizeof(short int));
	A[0]=1; A[1]=1;
	for (int i=2; i<n; i++){
		A[i] = A[i-2] + A[i-1];
	}
	stampa(A,n);
	free(A);
	return 0;
}

void stampa(short int *v, short int dim) {
	for (int i=0; i<dim; i++) {
		printf("%hd ", v[i]);
	}
}

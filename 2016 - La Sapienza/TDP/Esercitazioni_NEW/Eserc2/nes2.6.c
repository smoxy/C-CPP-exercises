#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {
	short unsigned int n, b, tot=0;
	printf("DA BINARIO A DECIMALE\nInserisci il numero di bit: ");
	scanf("%hd", &n);
	short unsigned int *A = (short unsigned int*)calloc(n,sizeof(short int));
	
	for (int i=0; i<n; i++){
		printf("Bit 2^%d = ", i);
		scanf("%hd", &b);
		while  (b>1 || b<0){
			printf("Bit 2^%d = ", i);
			scanf("%hd", &b);
		}
		A[i]=b;
		tot = tot + (b*pow(2, i));
	}
	
	
	for (int i=n-1; i>=0; i--){
		printf("%hd", A[i]);
	}
	printf(" = %hd", tot);
	
	free(A);
	return 0;
}

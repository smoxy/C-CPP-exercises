#include <stdio.h>
#include <stdlib.h>

void scambia(int *a, int *b);

int main () {
	int *a = (int*)malloc(sizeof(int));
	int *b = (int*)malloc(sizeof(int));
	printf("inserisci l'intero a e poi quello b: ");
	scanf("%d %d", a, b);
	printf("a = %d\tb = %d\n", *a, *b);
	scambia(a, b);
	printf("a = %d\tb = %d\n", *a, *b);
	free(a); free(b);
	return 0;
}

void scambia(int *a, int *b) {
	int *tmp = (int*)malloc(sizeof(int));
	*tmp = *a;
	*a = *b;
	*b = *tmp;
	printf("Ho scambiato!\n");
	free(tmp);
}

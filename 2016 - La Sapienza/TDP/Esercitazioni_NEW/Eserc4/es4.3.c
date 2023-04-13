#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int *ptr_n = (int*)malloc(sizeof(int));
	int *ptr_min= (int*)malloc(sizeof(int));
	printf("Inserisci un numero: ");
	scanf("%d", ptr_n);
	*ptr_min = *ptr_n;
	while (*ptr_n != 0){
		printf("Inserisci un numero: ");
		scanf("%d", ptr_n);
		if (*ptr_n < *ptr_min && *ptr_n != 0) *ptr_min = *ptr_n;
	}
	printf("Il valore minimo è: %d", *ptr_min);	
	free(ptr_n); free(ptr_min);	
	return 0;
}

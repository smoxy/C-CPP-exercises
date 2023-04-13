#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int* db= (int*)malloc(sizeof(int)*2);
	printf("Inserisci un numero: ");
	scanf("%d", db);
	*(db+4) = *db;
	while (*db != 0){
		printf("Inserisci un numero: ");
		scanf("%d", db);
		if (*db < *(db+4) && *db != 0) *(db+4) = *db;
	}
	printf("Il valore minimo è: %d", *(db+4));	
	free(db);
	return 0;
}

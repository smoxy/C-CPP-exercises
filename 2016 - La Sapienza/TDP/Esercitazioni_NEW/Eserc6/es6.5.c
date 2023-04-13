#include <stdio.h>
#include <stdlib.h>

int* allocaEdInizializza(int n, int valore);

int main () {
	int n, valore;
	printf("Inserisci numero di interi che la memoria deve contenere: ");
	scanf("%d", &n);
	printf("Inserisci il valore con il quale inizializzare la memoria allocata: ");
	scanf("%d", &valore);
	
	int *database = allocaEdInizializza(n, valore);
	
	for (int i=0; i<n; i++){
		printf("%d ", database[i]);
	}printf("\n");
	
	free(database);
	
	return 0;
}

int* allocaEdInizializza(int n, int valore) {
	int *lista = (int*)malloc(sizeof(int)*n);
	for (int i=0; i<n; i++){
		lista[i] = valore;
	}
	return lista;
}

#include <stdio.h>
#include <stdlib.h>

/********************************CONSEGNA*********************************
 * Scrivere una funzione [ int* allocaEdInizializza(int n, int valore) ] *
 * che dati in ingresso due interi n e valore, allochi una zona di		 *
 * memoria adatta a contenere n interi e la inizializzi con il contenuto *
 * del parametro valore. La funzione deve restituire il puntatore alla	 *
 * zona di memoria allocata. Inoltre, scrivere una unzione main che		 *
 * legga in input da tastiera i dati 'n' e 'valore', invochi la funzione *
 * allocaEdInizializza, verifichi la corretta allocazione e				 *
 * inizializzazione stampando i valori della memoria allocata (si usi	 *
 * l'aritmetica dei puntatori) e infine rilasci la memoria allocata.	 *
 *************************************************************************/

int* allocaEdInizializza(int n, int valore) {
	int *data = (int *)malloc(sizeof(int) * n);
	for (int i=0; i<n; i++)
		data[i] = valore;
	return data;
}

int main(int argc, char **argv) {
	int n, valore;
	printf("Inserisci n interi che la zona di memoria deve contenere:\t\t");
	scanf("%d", &n);
	printf("Inserisci il valore con il quale inizializzare la zona di memoria:\t");
	scanf("%d", &valore);
	int *data = allocaEdInizializza(n, valore);
	
	for (int i=0; i<n; i++)	{
		printf("%d ", data[i]);
	}
	printf("\n");
	
	free(data);
	return 0;
}

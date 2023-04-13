#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	void *db = (void*)malloc((sizeof(float)*2)+sizeof(int));
	
	printf("0 per terminare\nInserisci il 1° numero: ");
	scanf("%f", (float*)db);	//Numero corrente
	
	*(int*)(db+8) = 0;			// Contatore
	*(float*)(db+4) = 0;		// Totale
	
	while (*(float*)db != 0.0) {
		(*(int*)(db+8))++;
		*((float*)(db+4)) += (*(float*)db);
		printf("Inserisci il %d° numero: ", *(int*)(db+8)+1);
		scanf("%f", (float*)db);
	}
	
	*(float*)db = (*(float*)(db+4))/(*(int*)(db+8));
	printf("La media è %f", (*(float*)db));
	free(db);
	return 0;
}

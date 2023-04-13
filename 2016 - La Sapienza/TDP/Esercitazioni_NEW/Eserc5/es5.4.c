#include <stdio.h>
#include <stdlib.h>

int main () {
	void* db = (void*)malloc(sizeof(int)+(sizeof(float)*2));
	*((int*)db) = 1;
	*((float*)db+4) = 0.0;
	*((float*)db+8) = 0.0;
	printf("Inserisci il %d° numero: ", *((int*)db));
	scanf("%f", ((float*)db+8));
	*((float*)db+4) += *((float*)db+8);
	(*((int*)db))++;
	while (*((float*)db+8) != 0) {
		printf("Inserisci il %d° numero: ", *((int*)db));
		scanf("%f", ((float*)db+8));
		*((float*)db+4) += *((float*)db+8);
		(*((int*)db))++;
	}
	printf("\nI numeri validi inseriti sono %d\nLa media aritmetica è %.2f", *((int*)db)-2, *((float*)db+4)/ (*((int*)db)-2));
	free(db);
	return 0;
}

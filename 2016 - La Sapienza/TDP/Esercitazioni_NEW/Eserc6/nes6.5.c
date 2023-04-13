#include <stdio.h>
#include <stdlib.h>

int* allocaEdInizializza(int n, int valore);

int main (int argc, char **argv) {
	int dim, num;
	int *p;
	printf("Quanti interi vuoi memorizzare: ");	scanf("%d", &dim);
	printf("Con quale numero li riempio: ");	scanf("%d", &num);
	p = allocaEdInizializza(dim, num);
	
	for (int i=0; i<dim; i++) {
		printf("%d\t", p[i]);
	}
	return 0;
}

int* allocaEdInizializza(int n, int valore) {
	int *db = (int*)calloc(n, sizeof(int));
	for (int i=0; i<n; i++) {
		db[i] = valore;
	}
	return db;
}

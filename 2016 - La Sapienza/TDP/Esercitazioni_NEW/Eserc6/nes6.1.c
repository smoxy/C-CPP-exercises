#include <stdio.h>
#include <stdlib.h>

void scambia (int *a, int *b);

int main (int argc, char **argv) {
	int a = 100;
	int b = 27;
	printf("a = %d\tb = %d\nOra scambio\n", a, b);
	scambia(&a, &b);
	printf("a = %d\tb = %d\n", a, b);
	return 0;
}

void scambia (int *a, int *b) {
	void *p = (void*)malloc(sizeof(void));
	*(int*)p = *a;
	*a = *b;
	*b = *(int*)p;
	free(p);
}

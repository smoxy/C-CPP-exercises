#include <stdio.h>
#include <stdlib.h>

void scambia (int *a, int *b) {
	int *tmp = (int *)malloc(sizeof(int));
	*tmp = *a;
	*a = *b;
	*b = *tmp;
	free(tmp);
}

int main () {
	int *a = (int *)malloc(sizeof(int));
	int *b = (int *)malloc(sizeof(int));
	*a = 3; *b = 1;
	printf("PRIMA\ta = %d | b = %d\n", *a, *b);
	scambia (a, b);
	printf("DOPO\ta = %d | b = %d\n", *a, *b);
	return;
}

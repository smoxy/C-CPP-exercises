#include <stdio.h>
#include <stdlib.h>

/* */

int main (int argc, char **argv) {
	int i = 10;
	int j = 20;
	printf("%d == %d\n", i, j);
	char *p, *q;
	p = (char*)&i;
	q = (char*)&j;
	for (unsigned int k = 0; k < sizeof(q); k++) {
		*(q + k) = *(p + k);
	}
	printf("%d == %d\n", i, j);
	return 0;
}

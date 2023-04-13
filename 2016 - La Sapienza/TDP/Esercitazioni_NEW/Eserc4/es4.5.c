#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int a=0, b=0;
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	
	printf("Distanza tra la memoria a e la memoria b: %ld\n", (&a-&b));
	int dptr = &a - &b;
	
	*(&b + dptr) = 1;
	printf("a = %d\n", a);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	char* c = (char*)malloc(sizeof(char));
	short hd = 2;
	int d = 15;
	long ld = 1024;
	float f = 0.5;
	double lf = 1024.000125;
	printf("Indirizzo\tbyte\n%p\t%lu\tchar\n", c, sizeof(c));
	printf("%p\t%lu\tshort int\n", &hd, sizeof(hd));
	printf("%p\t%lu\tint\n", &d, sizeof(d));
	printf("%p\t%lu\tlong int\n", &ld, sizeof(ld));
	printf("%p\t%lu\tfloat\n", &f, sizeof(f));
	printf("%p\t%lu\tlong float\n", &lf, sizeof(lf));
	free(c);
	return 0;
}

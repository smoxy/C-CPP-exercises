#define GIORNI 30
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	char a[] = "Hello";
	printf("Char:\t%s\t\tIndirizzo memoria: %p\tBytes: %lu\n", a, &a, sizeof(a));
	
	short b = 1;
	printf("Short:\t%hd\t\tIndirizzo memoria: %p\tBytes: %lu\n", b, &b, sizeof(b));
	
	long c = 512;
	printf("Long:\t%ld\t\tIndirizzo memoria: %p\tBytes: %lu\n", c, &c, sizeof(c));	
	
	int d = 12;
	printf("Int:\t%d\t\tIndirizzo memoria: %p\tBytes: %lu\n", d, &d, sizeof(d));
	
	float e = 0.5;
	printf("Char:\t%f\tIndirizzo memoria: %p\tBytes: %lu\n", e, &e, sizeof(e));
	
	double f = 1024.512;	
	printf("Float:\t%lf\tIndirizzo memoria: %p\tBytes: %lu\tMantissa ed esponente: %e\n", f, &f, sizeof(f), f);
	return 0;
}

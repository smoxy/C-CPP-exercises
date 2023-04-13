#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int a=0; //False
	int b=1; //True
	if (a==false) printf("%d is False\n", a);
	if (b) printf("%d is True\n", b); printf("\n");
	// Tabella AND
	for (int i=0; i<2; i++) {
		a = 0;
		b = i%2;
		printf("%d and %d\t\t%d\n", a, b, a && b);
	}for (int i=0; i<2; i++) {
		a = 1;
		b = i%2;
		printf("%d and %d\t\t%d\n", a, b, a && b);
	}printf("\n");
	// Tabella OR
	for (int i=0; i<2; i++) {
		a = 0;
		b = i%2;
		printf("%d or %d\t\t%d\n", a, b, a || b);
	}for (int i=0; i<2; i++) {
		a = 1;
		b = i%2;
		printf("%d or %d\t\t%d\n", a, b, a || b);
	}printf("\n");
	// Tabella XOR
	for (int i=0; i<2; i++) {
		a = 0;
		b = i%2;
		printf("%d xor %d\t\t%d\n", a, b, a ^ b);
	}for (int i=0; i<2; i++) {
		a = 1;
		b = i%2;
		printf("%d xor %d\t\t%d\n", a, b, a ^ b);
	}
	exit(0);
}

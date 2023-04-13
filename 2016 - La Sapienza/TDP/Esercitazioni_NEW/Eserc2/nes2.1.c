#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	short int a=0, x=0, b=0;
	printf("ax + b = 0\nInserisci il valore della varibile a: ");
	scanf("%hd", &a);
	printf("Inserisci il valore della varibile b: ");
	scanf("%hd", &b);
	x = -(b/a);
	printf("%hdx + %hd = 0\n |\n\\|/\n V\nx = %hd", a, b, x);
	return 0;
}

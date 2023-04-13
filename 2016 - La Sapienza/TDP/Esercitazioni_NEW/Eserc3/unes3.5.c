#include <stdio.h>
#include <stdlib.h>
//nes3.5.c
int main (int argc, char **argv) {
	int x;
	printf("0 per terminare\nInserisci un numero: ");
	scanf("%d", &x);
	
	while (x!=0) {
		for (int i=0; i<x; i++) printf("*");
		printf("\nInserisci un numero: ");
		scanf("%d", &x);
	}
	return 0;
}

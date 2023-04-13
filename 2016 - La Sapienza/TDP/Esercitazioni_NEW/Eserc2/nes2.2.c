#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	short int c=1, n;
	float tot=0;
	printf("+++MEDIA ARITMETICA INTERI+++\nInserisci il %hd° numero: ", c);
	scanf("%hd", &n);
	while (n != 0){
		c++;
		tot = tot + n;
		printf("Inserisci il %hd° numero: ", c);
		scanf("%hd", &n);
	}
	tot = tot/(c-1);
	printf("La media aritmetica è %.1f", tot);
	return 0;
}

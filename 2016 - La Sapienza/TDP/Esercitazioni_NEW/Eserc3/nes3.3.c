#include <stdio.h>
#include <stdlib.h>
#include mat
//nes3.3.c
int main (int argc, char **argv) {
	int r, row, column, star, line;
	printf("Inserisci un numero: ");
	scanf("%d", &r);
	row=column = r*2+1;
	
	for (int a=0; a<row; a++) {
		if (a==0 || a==r*2) {			//Prima riga
			for (int c=0; c<column; c++) {
				if (c==r) printf("*");
				else printf("_");
			}
			printf("\n");
		}
		else if (a==r) {	//Riga in mezzo
			for (int c=0; c<column; c++) {
				printf("*");
			}
			printf("\n");
		}
		else {
			line = ((row)-a)/2;
			if (line%2 != 0) line++;
			star = column-line;
			for (int c=0; c<column; c++) {
				if (c<line/2 || c>=(line/2)+star) printf("_");
				else printf("*");
			}
			printf("\n");
		}
	}
	
	return 0;
}

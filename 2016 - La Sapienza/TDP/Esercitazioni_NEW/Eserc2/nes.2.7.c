#include <stdio.h>
#include <stdlib.h>
//nes2.7.c
int main (int argc, char **argv) {
	int elemento=0, r, x=1, actualArrow=1;
	printf("Inserisci il numero delle righe del triangolo di Floyd: ");
	scanf("%d", &r);
	while (actualArrow < r+1){
		printf("%d ", x);
		x++;
		elemento++;
		if (elemento>=actualArrow){
			printf("\n");
			actualArrow++;
			elemento=0;
		}
	}
	return 0;
}

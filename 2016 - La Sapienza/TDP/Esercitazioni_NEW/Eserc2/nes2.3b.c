#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	short int n = 0;
	printf("Inserisci il lato del quadrato: ");
	scanf("%hd", &n);
	for (int i = 0; i<n; i++){
		if (i==0 || i==(n-1)){
			for (int j=0; j<n; j++){
				printf("*");
			}
			printf("\n");
		}
		else{
			printf("*");
			for (int h=0; h<(n-2); h++)
				printf(" ");
			printf("*\n");
		}
	}
	return 0;
}

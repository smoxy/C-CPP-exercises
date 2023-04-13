#include <stdio.h>
#include <stdlib.h>

void stampaAsterischi(int n) {
	for (int i = 0; i < n; i++) {
			printf("*");
		}
		printf("\n");	
}

int main (int argc, char **argv) {
	int n;
	scanf("%d", &n);
	while (n != 0) {
		stampaAsterischi(n);
		scanf("%d", &n);
	}
}

#include <stdio.h>

int main (int argc, char **argv) {
	int n;
	scanf("%d", &n);
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			printf("*");
		}
		printf("\n");
		scanf("%d", &n);		
	}		
	return 0;
}

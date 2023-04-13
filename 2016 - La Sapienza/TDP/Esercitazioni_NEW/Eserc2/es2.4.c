#include <stdio.h>
#include <stdlib.h>

/* stampa i primi n numeri della serie di fibonacci, con n inserito
 * da tastiera */

int main (int argc, char **argv) {
	int n = 0;
	int tmp = 0;
	int s = 1;
	int c = 0;
	printf("Quanti numeri della serie di fibonacci vuoi visualizzare? ");
	scanf("%d", &n);
	if (n>0) printf("1 ");
	for (int i=1; i<n; i++) {
		tmp = s;
		s += c;
		c = tmp;
		printf("%d ", s);
	}
	return 0;
}

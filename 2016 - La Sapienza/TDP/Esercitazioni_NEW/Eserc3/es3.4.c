#include <stdio.h>
#include <stdlib.h>

/* restituisce il minimo degli N valori inseriti. La sequenza termina
 * quando viene inserito 0 */

int main () {
	float n, min;
	int end = 0;
	printf("Inserisci un numero: ");
	scanf("%f", &n);
	min = n;
	while (!end) {
		printf("Inserisci un numero: ");
		scanf("%f", &n);
		if (n < min && n != 0) min = n;
		end = n == 0;
	}
	printf("Il numero minore è %f", min);
	return 0;
}

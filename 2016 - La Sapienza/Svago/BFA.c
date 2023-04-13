/* CONSEGNA
	Scrivere programma che trova una password inserità da tastiera.
	la password è solo numerica
*/

#include <stdio.h>

int main() {
	long a=0;
	long b=0;
	//int count=0; //contatore dei cicli necessari per trovare la pass
	printf("Enter your password (Only numerical): ");
	scanf("%lu", &a);
	while (b!=a) {
		b++;
		//printf("%lu\n", b);
	}
	printf("The password is: %lu\n", b);
}

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	printf("INSERISCI IL TESTO DA STAMPARE LETTERA PER LETTERA\n");
	char c[12];
	scanf("%s", c);
	printf("%s\n", c);
	char *letter = (char *)malloc(sizeof(char));
	int lenght = (sizeof(c)-1);
	for (int i = 0; i < lenght; i++) {
		*letter = c[i];
		printf("%c\n", *letter);
	}
	return 0;
}

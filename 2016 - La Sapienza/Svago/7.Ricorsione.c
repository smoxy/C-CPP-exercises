#include <stdio.h>
#include <stdlib.h>

/** ESEMPI RICORSIONE **/

int fattoriale (int n);		// 7.1
int somma(int x, int y);	// 7.1.1
int prodotto(int x, int y);	// 7.1.2
int potenza(int x, int y);	// 7.1.3

int contaCaratteri (FILE *i);					// 7.3.1
int contaOccorrenzeCarattere (FILE *i, char x);	// 7.3.2
int sommaValori (FILE *i);						// 7.3.3


int main (int argc, char **argv) {
	int a, b;
	char* c = (char*)malloc(sizeof(char));
	
	FILE *f1 = fopen("/home/simone/Desktop/C/TDP/Esercitazioni NEW/Eserc9/files-esercitazione9/mat_2 (copy).txt", "r");
	if (f1 == NULL) {
		printf("Errore nell'apertura del file\n");
	}
	
	printf("Inserisci due numeri interi naturali: ");
	scanf("%d %d", &a, &b);
	
	printf("\n\nVuoi fare il fattoriale di %d? y/n: ", a);
	scanf("%s", c);
	if (*c == 'y' || *c == 'Y') {
		printf("fattoriale di %d = %d\n", a, fattoriale(a));
	}
	
	printf("\n\nVuoi fare la somme di %d e %d? y/n: ", a, b);
	scanf("%s", c);
	if (*c == 'y' || *c == 'Y') {
		printf("%d + %d = %d\n", a, b, somma(a, b));
	}
	
	printf("\n\nVuoi fare il prodotto di %d e %d? y/n: ", a, b);
	scanf("%s", c);
	if (*c == 'y' || *c == 'Y') {
		printf("%d * %d = %d\n", a, b, prodotto(a, b));
	}
	
	printf("\n\nVuoi calcolare %d^%d? y/n: ", a, b);
	scanf("%s", c);
	if (*c == 'y' || *c == 'Y') {
		printf("%d^%d = %d\n", a, b, potenza(a, b));
	}
	
	printf("In tutto ci sono %d caratteri\n", contaCaratteri(f1));
	f1 = fopen("/home/simone/Desktop/C/TDP/Esercitazioni NEW/Eserc9/files-esercitazione9/mat_2 (copy).txt", "r");
	printf("il carattere '3' compare %d volte\n", contaOccorrenzeCarattere(f1, '3'));
	f1 = fopen("/home/simone/Desktop/C/TDP/Esercitazioni NEW/Eserc9/files-esercitazione9/mat_2 (copy).txt", "r");
	printf("il carattere '5' compare %d volte\n", contaOccorrenzeCarattere(f1, '5'));
	f1 = fopen("/home/simone/Desktop/C/TDP/Esercitazioni NEW/Eserc9/files-esercitazione9/mat_2 (copy).txt", "r");
	printf("La somma di tutti i valori nel file è: %d", sommaValori(f1));
	
	int ok = fclose(f1);
	if (ok !=0) {
		printf("Errore nella chiusura del file\n");
	}
	
	return 0;
}

// Inizio esempi capitolo 7.1 FUNZIONI RICORSIVE
int fattoriale (int n) {
	if (n==0) {
		return 1;
	}
	else return n * fattoriale(n-1);
}

int somma(int x, int y) {
	if (y==0) {
		return x;
	}
	else return 1 + somma(x, y-1);
}

int prodotto(int x, int y) {
	if (y==0) {
		return 0;
	}
	else return x + prodotto(x, y-1);
}

int potenza(int x, int y) {
	if (y==0) {
		return 1;
	}
	else return x * potenza(x, y-1);
}
// Fine esempi capitolo 7.1

/* Inizio esempi capitolo 7.3 SCHEMI DI RICORSIONE
 * Lunghezza di una sequenza di caratteri */
int contaCaratteri (FILE *i) {
	char c;
	c = fgetc(i);
	if (c == EOF) {
		return 0;
	}
	else return 1 + contaCaratteri(i);
}

int contaOccorrenzeCarattere (FILE *i, char x) {
	char c;
	c = fgetc(i);
	if (c == EOF) {
		return 0;
	}
	else if (c == x) {
		return 1 + contaOccorrenzeCarattere(i, x);
	}
	else return contaOccorrenzeCarattere(i, x);
}

int sommaValori (FILE *i) {
	int v;
	int end;
	end = fscanf(i, "%d", &v);
	if (end == EOF)
		return 0;
	else return v + sommaValori(i);
	
}

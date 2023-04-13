#include <stdio.h>
#include <stdlib.h>

void muovi (int n, char sorg, char dest, char aux);

void muoviUnDisco (char sorg, char dest);

int main () {
    printf("Quanti dischi vuoi muovere?\n");
    int n;
    scanf("%d", &n);
    printf("Per muovere %d dischi da A a B con C come appoggio:\n\n", n);
    muovi(n, 'A', 'B', 'C');
}

void muoviUnDisco (char sorg, char dest) {
    printf("muovi un disco da %c a %c\n", sorg, dest);
}

void muovi(int n, char sorg, char dest, char aux) {
    if (n==1)
	muoviUnDisco(sorg, dest);
    else  {
	//printf("Ricorsivo: \n");
	muovi (n-1, sorg, aux, dest);
	muoviUnDisco (sorg, dest);
	//printf("Ritorno:  ");
	muovi (n-1, aux, dest, sorg);
    }
}

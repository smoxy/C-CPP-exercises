#include <stdio.h>
#include <stdlib.h>

int* leggi(int *vettore);
void stampa(int *v, int dim);
int media(int *v, int dim);		//DEFINIZIONE MODIFICATA

int main (int argc, char **argv) {
	int *A = (int*)calloc(10,sizeof(int));
	int *B = (int*)calloc(10,sizeof(int));
	int media_A, media_B;
	leggi(A);
	//stampa(A, 10);
	media_A = media(A, 10);
	leggi(B);
	//stampa(B, 10);
	media_B = media(B, 10);
	if (media_A > media_B)
		stampa(A, 10);
	else stampa(B, 10);
	
	free(A); free(B);
	return 0;
}

int* leggi(int* vettore){
	int n, x = 0;
	printf("Inserisci il %d° numero\t: ", x+1);
	scanf("%d", &n);
	while (n != 0){
		vettore[x] = n;
		x++;
		printf("Inserisci il %d° numero\t: ", x+1);
		scanf("%d", &n);
	}
	return vettore;
}

void stampa(int *v, int dim) {
	for (int i=0; i<dim; i++) {
		printf("%d ", v[i]);
	}
}

int media(int *v, int dim) {
	int v_media, somma = 0, c = 0;
	for (int i = 0; i<dim; i++){
		if (v[i] != 0){
			somma += v[i];
			c = i+1;
		}
	}
	v_media = somma/c;
	printf("Media = %d/%d = %d\n", somma, c, v_media); //Forse questo il prof non lo vuole, quindi commentalo
	return v_media;			//RIGA AGGIUNTA
}

#include <stdio.h>
#include <stdlib.h>

void vec_write(short *v, int dim);
void vec_print(short *v, int dim);
void vec_clean(short *v, int dim);
void bin_sum(short *v1, short *v2, short *vR, short *vResult, int dim);
void bin_sub(short *v1, short *v2, short *vR, short *vResult, int dim);
void bin_mult(short *v1, short *v2, short *vR, short *vResult, int dim);
short one_count(short *v, int dim);
short first_bin(short *v, int dim);
void complement(short *v, short* vR, int dim);

int main () {
	//Inizio allocazione dinamica
	short *vA = (short*)calloc(32,sizeof(short));	//1st numero binario
	short *vB = (short*)calloc(32,sizeof(short));	//2nd numero binario
	short *vR = (short*)calloc(32,sizeof(short));	//Resto delle operazioni
	short *vResult = (short*)calloc(32,sizeof(short)); //Risultato
	char *ok = (char*)malloc(sizeof(char));			//Parametro di controllo
	//Fine allocazione dinamica
	
	vec_write(vA, 32);
	vec_print(vA, 32);
	printf("\n\n");
	vec_write(vB, 32);
	vec_print(vB, 32);
	
	printf("\n\nVuoi fare la somma? y/n: ");
	scanf("%s", ok);
	if (*ok == 'y' || *ok == 'Y') {
		printf("Eseguo la somma:\n");
		vec_clean(vR, 32); vec_clean(vResult, 32);	//Pulisco vettore del resto e del risultato
		bin_sum(vA, vB, vR, vResult, 32);		//Eseguo la somma
		vec_print(vResult, 32);					//Stampo il risultato
	}
	
	printf("\n\nVuoi fare la sottrazione? y/n: ");
	scanf("%s", ok);
	if (*ok == 'y' || *ok == 'Y') {
		printf("Eseguo la sottrazione:\n");
		vec_clean(vR, 32); vec_clean(vResult, 32);	//Pulisco vettore del resto e del risultato
		bin_sub(vA, vB, vR, vResult, 32);		//Eseguo la sottrazione
		vec_print(vResult, 32);					//Stampo il risultato
	}
	
	printf("\n\nVuoi fare la moltiplicazione? y/n: ");
	scanf("%s", ok);
	if (*ok == 'y' || *ok == 'Y') {
		printf("Eseguo la moltiplicazione:\n");
		vec_clean(vR, 32); vec_clean(vResult, 32);	//Pulisco vettore del resto e del risultato
		//bin_mult(vA, vB, vR, vResult, 32);		//Eseguo la sottrazione
		vec_print(vResult, 32);					//Stampo il risultato
	}
	free(vA); free(vB); free(vR); free(vResult); free(ok);	//Libero la memoria allocata dinamicamente
	return 0;
}

void vec_write(short *v, int dim){
	int a, mask;
	printf("Inserisci il numero decimale\t");
	scanf("%d", &a);
	
	for (int i=(dim-1); i>=0; i--) {
		mask = 1<<i;
		if ((mask&a) == 0) v[i] = 0;
		else v[i] = 1;
	}
}

void vec_print(short *v, int dim) {
	for (int i=(dim-1); i>=0; i--) {
		printf("%hd", v[i]);
	}
}

void vec_clean(short *v, int dim) {
	for (int i=0; i<dim; i++) {
		v[i] = 0;
	}
}

void bin_sum(short *v1, short *v2, short *vR, short *vResult, int dim) {
	for (int i=0; i<dim; i++) {
		if (vR[i] == 0) {
			//printf("Resto 0  ");
			if (v1[i] == v2[i] && v1[i] == 0) {
				//printf("%d == %d, next resto 0\n", v1[i], v2[i]);
				vR[i+1] = 0;
				vResult[i] = 0;
			}else if (v1[i] != v2[i]) {
				//printf("%d != %d, next resto 0\n", v1[i], v2[i]);
				vR[i+1] = 0;
				vResult[i] = 1;
			}else if (v1[i] == v2[i] && v1[i] != 0) {
				//printf("%d == %d, next resto 1\n", v1[i], v2[i]);
				vR[i+1] = 1;
				vResult[i] = 0;
			}
		}else {
			//printf("Resto 1  ");
			if (v1[i] == v2[i] && v1[i] == 0) {
				//printf("%d == %d, next resto 0\n", v1[i], v2[i]);
				vR[i+1] = 0;
				vResult[i] = 1;
			}else if (v1[i] != v2[i]) {
				//printf("%d != %d, next resto 1\n", v1[i], v2[i]);
				vR[i+1] = 1;
				vResult[i] = 0;
			}else if (v1[i] == v2[i] && v1[i] != 0) {
				//printf("%d == %d, next resto 1\n", v1[i], v2[i]);
				vR[i+1] = 1;
				vResult[i] = 1;
			}
		}
	}
}

void complement(short *v, short* vR, int dim) {
	for (int i=0; i<dim; i++) {
		if (v[i] == 0) v[i]=1;
		else v[i] = 0;
	}
	short *one = (short*)calloc(32, sizeof(short));
	vec_clean(one, 32);
	one[0] = 1;
	bin_sum(v, one, vR, v, 32);
	vec_clean(vR, 32); free(one);
}

void bin_sub(short *v1, short *v2, short *vR, short *vResult, int dim) {
	complement(v2, vR, 32);
	bin_sum(v1, v2, vR, vResult, 32);
	complement(v2, vR, 32);
}

short one_count(short *v, int dim) {
	int counter = 0;
	for (int i=0; i<dim; i++) {
		if (v[i] != 0) {
			counter++;
		}
	}
	return counter;
}

short first_bin(short *v, int dim) {
	int i = (dim-1);
	while (v[i] == 0) {
		i--;
	}
	printf("%hd %hd\n\n", v[i], v[i-1]);
	return (i-1);
}
/** WORK IN PROGRESS
void bin_mult(short *v1, short *v2, short *vR, short *vResult, int dim) {
	short *p1 = (short*)calloc(32,sizeof(short));
	short *p2 = (short*)calloc(33,sizeof(short));
	vec_clean(p1,32); vec_clean(p2,33);	//Pulisco vettore parziale 1 e 2
	if (one_count(v1, 32) == one_count(v2, 32)) {
		
	}else if (one_count(v1, 32) < one_count(v2, 32) {
		
	}else
	for (int i=0; i<dim; i++) {
		for (int j=0; j<dim; j++) {
			if (v1[i] == v2[i] && v1[i] == 0) {
				p1[i] = 0;
			}else if (v1[i] != v2[i]) {
				p1[i] = 1;
			}else if (v1[i] == v2[i] && v1[i] != 0) {
				p1[i] = 0;
			}
		}
	}
	
	free(p1); free(p2);
}
*/

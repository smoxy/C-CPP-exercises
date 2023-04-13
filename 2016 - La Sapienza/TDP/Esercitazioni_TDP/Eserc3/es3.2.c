/*	CONSEGNA
Scrivere un programma che dati in input due numeri interi positivi
N ed M (M sottomultiplo di N), disegni una scacchiera
N*MxN*M con blocchi di asterischi M*M. 
 */

#include <stdio.h>

int main () {
	int m = -1; // height
	int n = -1; // width
	int c = 0;	//
	int count1=0;
    int count2=0;
    int count3=0;
    int count=0;
	int booleana = 0; //0 is false; 1 is true
	while ( !(m>0 && n>0 && booleana && m!=1)) {
		printf("Enter 2 positive number: ");
		scanf("%d%d", &n, &m);
		if (n%m==0) {
			booleana = 1;
		}
	}
	c = (m*n)/(2*m);
	count3=0;
	while (count3!=c) {			//Ripete la prima e la seconda serie per c volte
		count=0;
		while (count!=m) {		//Completa la prima serie che inizia con *
			count1=0;
			while (count1!=c) {	//Formato riga che inizia con *
				count2=0;
				while (count2!=m) {
					printf("*");
					count2++;
				}
				count2=0;
				while (count2!=m) {
					printf("-");
					count2++;
				}
				count1++;
			}
			count++;
			printf("\n");
		}
		count=0;
		while (count!=m) {		//Completa la prima serie che inizia con -
			count1=0;
			while (count1!=c) {	//Formato riga che inizia con -
				count2=0;
				while (count2!=m) {
					printf("-");
					count2++;
				}
				count2=0;
				while (count2!=m) {
					printf("*");
					count2++;
				}
				count1++;
			}
			count++;
			printf("\n");
		}
		count3++;
	}
	return 0;
}

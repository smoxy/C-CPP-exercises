#include <stdio.h>
#include <stdlib.h>

int main () {
	double a=0;
	double b=0;
	int count =2;
	char* go=(char*)malloc(256);
	double average=0;
	printf ("Somma Di Numeri\nInserisci 0 per terminare!\nEnter first number: ");
	scanf("%lf", &a);
	b+=a;
	while (a!=0) {
		printf ("Enter %d° number: ", count);
		scanf("%lf", &a);
		if (a!=0) {
			count++;
		}
		b+=a;
	}
	printf ("TOT. :%lf\nDo You Want the Average? (Y/N): ", b);
	scanf("%s", go);
	if (go=="Y") {
		average = b/(count-1);
		printf("Average :%lf", average);
	}
}

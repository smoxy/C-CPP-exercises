#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**********************************************************************
 *			TIPO			SPECIFICA DI FORMATO					  *
 *																	  *
 * 			INT				d										  *
 * UNSIGNED INT				u										  *
 * 	  SHORT INT				hd										  *
 * 	   LONG INT				ld										  *
 * 		  FLOAT				f										  *
 * 		 DOUBLE				lf										  *
 * 		   CHAR				c										  *
 **********************************************************************/

int main (int argc, char **argv) {
	unsigned char b = 'a';
	short s;
	printf("short int:\t");
	scanf("%hd", &s);
	int i;
	printf("int:\t");
	scanf("%d", &i);
	long l;
	printf("long int:\t");
	scanf("%ld", &l);
	float f;
	printf("float:\t");
	scanf("%f", &f);
	double d;
	printf("double:");
	scanf("%lf", &d);
	char c='j';
	
	printf("1) %ld\n", b + 10 * l);
	printf("2) %ld\n", (b + i) * l);
	printf("3) %f\n", (b + i) * l + f);
	printf("4) %lf\n", s / f + sin(d));
	printf("5) %d\n", c == 'b');
	printf("6) %f\n", l + 1.5f);
	printf("7) %d\n", i < 10);
	return 0;
}

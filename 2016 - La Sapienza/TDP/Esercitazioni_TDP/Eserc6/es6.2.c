#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int risolviEquazione(float *x1, float *x2, float a, float b, float c) {
	if (b == 0 && c == 0) {	//MONOMIA
		*x1 = 0;
		*x2 = *x1;
		return 1;
	}
	else if (c == 0) {		//SPURIA
		*x1 = 0;
		*x2 = -(b/a);
		return 1;
	}
	else if (b == 0) {		//PURA
		*x1 = + (sqrt(-c/a));
		*x2 = - (sqrt(-c/a));
		return 0;
	}
	else {					//COMPLETA
		float *delta = (float *)malloc(sizeof(float));
		*delta = (pow(b,2))-(4*a*c);
		if (*delta == 0.000000) {		//2 SOLUZIONI COINCIDENTI);
			*x1 = -b/(2*a);
			*x2 = *x1;
			return 0;
		}
		else if (*delta > 0) {	//2 SOLUZIONI REALI E DISTINTE
			*delta = sqrt(*delta);
			*x1 = (-b + *delta)/(2*a);
			*x2 = (-b - *delta)/(2*a);
			return 1;
		}
		else {					//NON HA SOLUZIONI REALI, SOLUZIONI COMPLESSE E CONIUGATE
			return -1;
		}
	}
}

int main (int argc, char **argv) {
	int result;
	float *x1 = (float *)malloc(sizeof(float));
	float *x2 = (float *)malloc(sizeof(float));
	float a = 0; float b = 0; float c =0;
	printf("Enter ax^2 + bx + c = 0\nFirst a Coefficient,\nSecond b Coefficient,\nThird c Coefficient:\n");
	scanf("%f %f %f", &a, &b, &c);
	result = risolviEquazione(x1, x2, a, b, c);
	printf("x1 = %.2f | x2 = %.2f\nreturn is %d", *x1, *x2, result);
}

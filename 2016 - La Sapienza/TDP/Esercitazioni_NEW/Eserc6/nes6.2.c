#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int risolviEquazione(float *x1, float *x2, float a, float b, float c);

int main (int argc, char **argv) {
	float *x1 = (float*)malloc(sizeof(float));
	float *x2 = (float*)malloc(sizeof(float));
	float a, b, c;
	printf("y=ax^2+bx+c\nInserisci a, b e c separati da uno spazio: ");
	scanf("%f %f %f", &a, &b, &c);
	risolviEquazione(x1, x2, a, b, c);
	printf("X1 = %f\tX2 = %f", *x1, *x2);
	
	free(x1); free(x2);
}

int risolviEquazione(float *x1, float *x2, float a, float b, float c) {
	float delta = powf(b,2) -(4*a*c);
	
	if (delta == 0) {
		*x1 = *x2 = -b/2*a;
		return 0;
	}
	else if (delta > 0) {
		*x1 = (-b + sqrtf(delta))/2;
		*x2 = (-b - sqrtf(delta))/2;
		return 1;
	}
	else {
		return -1;
	}
}

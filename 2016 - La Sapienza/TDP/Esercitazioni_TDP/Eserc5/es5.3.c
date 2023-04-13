#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
 * 									Legenda							   *
 *	*data					= Puntatore temperatura					   *
 * 	*(data + sizeof(float)	= Puntatore gradi						   *
 **********************************************************************/

int main () {
	void *data = (void*)malloc(sizeof(double) + sizeof(char));
	
	double k = 0;
	double f = 0;
	double c = 0;
	printf("\nEnter temperature and then a letter:\nC for Celsius,\nK for Kelvin and\nF for Fahrenheit\n");
	scanf("%lf %c", (double*)data, (char*)data + sizeof(double));
	
	if ( *((char*)data + sizeof(double)) == 'c' || *((char*)data + sizeof(double)) == 'C') {
		c = *((double*)data);
		k = c + 273.15;
		f = c * 9/5 + 32;
		printf("%.2lf°C = %.2lf°K and = %.2lf°F\n", c, k, f);
	}
	else if ( *((char*)data + sizeof(double)) == 'k' || *((char*)data + sizeof(double)) == 'K') {
		k = *((double*)data);
		c = k - 273.15;
		f = c * 9/5 + 32;
		printf("%.2lf°K = %.2lf°C and = %.2lf°F\n", k, c, f);		
	}
	else if ( *((char*)data + sizeof(double)) == 'f' || *((char*)data + sizeof(double)) == 'F') {
		f = *((double*)data);
		c = (f - 32)/1.8;
		k = c + 273.15;
		printf("%.2lf°F = %.2lf°C and = %.2lf°K\n", f, c, k);
	}
		
	free(data);
	return 0;
}

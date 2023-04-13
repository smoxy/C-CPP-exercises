#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	void *data = (void *)malloc(sizeof(double) + sizeof(char));
	double temp = *((double *)data);
	char grad = *((char *)data);
	double k = 0;
	double f = 0;
	double c = 0;
	printf("Enter temperature and then a letter:\nC for Celsius,\nK for Kelvin and\nF for Fahrenheit\n");
	scanf("%lf %c", &temp, &grad);
	if (grad == 'c' || grad == 'C') {
		c = temp;
		k = c + 273.15;
		f = c * 9/5 + 32;
		printf("%.2lf°C = %.2lf°K and = %.2lf°F\n", temp, k, f);
	}
	else if (grad == 'k' || grad == 'K') {
		k = temp;
		c = k - 273.15;
		f = c * 9/5 + 32;
		printf("%.2lf°K = %.2lf°C and = %.2lf°F\n", temp, c, f);		
	}
	else if (grad == 'f' || grad == 'F') {
		f = temp;
		c = (f - 32)/1.8;
		k = c + 273.15;
		printf("%.2lf°F = %.2lf°C and = %.2lf°K\n", temp, c, k);
	}	
	free(data);
	return 0;
}

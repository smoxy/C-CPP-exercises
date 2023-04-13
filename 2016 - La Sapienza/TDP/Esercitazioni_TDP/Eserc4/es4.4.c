#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	double *ptr_temp = (double *)malloc(1*sizeof(double));
	char *ptr_grad = (char *)malloc(1*sizeof(char));
	double k = 0;
	double f = 0;
	double c = 0;
	printf("\nEnter temperature and then a letter:\nC for Celsius,\nK for Kelvin and\nF for Fahrenheit\n");
	scanf("%lf %c", ptr_temp, ptr_grad);
	if (*ptr_grad == 'c' || *ptr_grad == 'C') {
		c = *ptr_temp;
		k = c + 273.15;
		f = c * 9/5 + 32;
		printf("%.2lf°C = %.2lf°K and = %.2lf°F\n", *ptr_temp, k, f);
	}
	else if (*ptr_grad == 'k' || *ptr_grad == 'K') {
		k = *ptr_temp;
		c = k - 273.15;
		f = c * 9/5 + 32;
		printf("%.2lf°K = %.2lf°C and = %.2lf°F\n", *ptr_temp, c, f);		
	}
	else if (*ptr_grad == 'f' || *ptr_grad == 'F') {
		f = *ptr_temp;
		c = (f - 32)/1.8;
		k = c + 273.15;
		printf("%.2lf°F = %.2lf°C and = %.2lf°K\n", *ptr_temp, c, k);
	}	
	free(ptr_temp); free(ptr_grad);	
	return 0;
}

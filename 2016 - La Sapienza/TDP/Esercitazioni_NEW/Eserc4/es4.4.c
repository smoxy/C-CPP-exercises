#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	float* c = (float*)malloc(sizeof(float));
	float* k = (float*)malloc(sizeof(float));
	float* f = (float*)malloc(sizeof(float));
	float* temp = (float*)malloc(sizeof(float));
	char* type = (char*)malloc(sizeof(char));
	printf("Inserisci il valore e la scala di temperatura:\nC per Celsius, K per Kelvin e F per Fahrenheit.\n");
	scanf("%f %c", temp, type);
	if (*type == 'C' || *type == 'c') {
		*c = *temp;
		*k = *c + 273.15;
		*f = (*c * 9/5) + 32;
	}else if (*type == 'K' || *type == 'k') {
		*k = *temp;
		*c = *k - 273.15;
		*f = (*c * 9/5) + 32;
	}else if (*type == 'F' || *type == 'f') {
		*f = *temp;
		*c = (*f - 32)/1.8;
		*k = *c + 273.15;		
	}else {
		printf("Errore! Non hai inserito una scala di temperatura corretta!\a\n");
	}printf("%.3f Kelvin  =  %.3f Celsius  =  %.3f Fahrenheit",*k, *c, *f);
	free(c); free(k); free(f); free(temp); free(type);
	return 0;
}

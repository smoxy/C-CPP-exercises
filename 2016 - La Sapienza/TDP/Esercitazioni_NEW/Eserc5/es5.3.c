#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	void* db = (void*)malloc((sizeof(float)*4)+sizeof(char));
	printf("Inserisci il valore e la scala di temperatura:\nC per Celsius, K per Kelvin e F per Fahrenheit.\n");
	scanf("%f %c", ((float*)db+12), ((char*)db+16));
	if ( *(((char*)db)+16) == 'C' || *(((char*)db)+16) == 'c') {
		*((float*)db) = *((float*)db+12);
		*((float*)db+4) = *((float*)db) + 273.15;
		*((float*)db+8) = (*((float*)db) * 9/5) + 32;
	}else if (*(((char*)db)+16) == 'K' || *(((char*)db)+16) == 'k') {
		*((float*)db+4) = *((float*)db+12);
		*((float*)db) = *((float*)db+4) - 273.15;
		*((float*)db+8) = (*((float*)db) * 9/5) + 32;
	}else if (*(((char*)db)+16) == 'F' || *(((char*)db)+16) == 'f') {
		*((float*)db+8) = *((float*)db+12);
		*((float*)db) = (*((float*)db+8) - 32)/1.8;
		*((float*)db+4) = *((float*)db) + 273.15;		
	}else {
		printf("Errore! Non hai inserito una scala di temperatura corretta!\a\n");
	}printf("%.3f Kelvin  =  %.3f Celsius  =  %.3f Fahrenheit\n",*((float*)db+4), *((float*)db), *((float*)db+8));
	free(db);
	return 0;
}

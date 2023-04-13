#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**Scrivere un programma in linguaggio C che prenda in input un reale ed un carattere
 * rappresentanti rispettivamente un valore numerico e il tipo di valore:
 * esadecimale, decimale, ottale e binario. se è binario chiedere se è un complemento
 * a due */
 
/*
int hexadToBin (int *n = (int *)malloc(sizeof(int))) {

	return 0;
}

int binToHexad (int *n = (int *)malloc(sizeof(int))) {

	return 0;
}
*/

int binToDecimal (char c[] = "101101") {
	int decimal = 0;
	int lenght = (sizeof(c)-1);
	char *one =(char *)malloc(sizeof(char));
	int number;
	for (int i = 0; i < lenght; i++) {
		*one = c[i];
		number = (int) (*one - '0');
		printf("%d\n", number);
		decimal+= (number * pow(2, lenght - (i + 1)));
		
	}
	
	return decimal;
}

/*
int binToOctal (int *n = (int *)malloc(sizeof(int))) {

	return 0;
}

int decimalToBin (int *n) {
	
	return 0;
}

int octalToBin (int *n = (int *)malloc(sizeof(int))) {

	return 0;
}
*/

int main (int argc, char **argv) {
	char *n = (char *)malloc(sizeof(char));
	char *c = (char *)malloc(sizeof(char));
	char *bin = (char *)malloc(sizeof(char));
	int hexad = 0; int decimal = 0; int octal = 0;
	printf("\nEnter temperature and then put:\n16* for hexadecimal,\n10* for decimal,\n8* for octal and\n2* for binary\n");
	scanf("%s %s", &n, &c);
	printf("as %c = %c as", *n, *c);
	/*if (*ptr_c == "16*")		//Da esadecimale
		hexad = *ptr_n;
		bin = hexadToBin(*ptr_n);
	else if (*ptr_c == "10*");	//Da decimale
		decimal = *ptr_n;
		bin = decimalToBin(*ptr_n);
	else if (*ptr_c == "8*");	//Da ottale
		octal = *ptr_n;
		bin = octalToBin(*ptr_n);
	*/
	if (c == "2*");	//Da binario
		*bin = *n;
		printf("OKAY\n");
	
	//hexad = binToHexad(bin);
	decimal = binToDecimal(bin);
	//octal = binToOctal(bin);
	
	printf("hexadecimal %d =\ndecimal = %d\noctal = %d\nbinary = %C\n", hexad, decimal, octal, *bin);
		
	return 0;
}

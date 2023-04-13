#include <stdio.h>
#include <stdlib.h>

/*programma che Crea un file txt con le possibili password WPA
 * numeri ascii interessanti:
 * 33, 44-45, 48-57 (NUMERI), 65-90 (lettere maiusc), 95, 97-122 (lettere minusc)
 * 
 * wpa è composta da 8 fino a 63 caratteri.
 */

int main () {
	FILE *fp;	 
	fp = fopen("/home/simone/Desktop/test.txt", "w+");
	
	for (int c = 33; c <= 122; c++) 		//da 1 lettera
		fprintf(fp, "%c\n", c);
	
	for (int i = 33; i <= 122; i++) {		//da 2 lettere
		for (int c = 33; c <= 122; c++)
			fprintf(fp, "%c%c\n", i, c);
	}
	
	for (int a = 33; a <= 122; a++) {		//da 3 lettere
		for (int b = 33; b <= 122; b++)
			for (int c = 33; c <= 122; c++)
				fprintf(fp, "%c%c%c\n", a, b, c);
	}
	
	fclose(fp);
	return 0;
}

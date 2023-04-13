#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	long int i = 32767;
	long int j = 20;
	char *p, *q;
	printf("%ld == %ld\n", i, j);
	/************************************************************************
	 * 								Vocabolario								*
	 * &i -->Indirizzo-di													*
	 * *i -->Deferenziamento|Permette di accedere al valore di un indirizzo	*
	 * 					Inserire codice qui senza (senza j = ...)			*
	 ***********************************************************************/
	p = (char*)&i;
	q = (char*)&j;
	printf("size of i: %lu\n", sizeof(i));
	printf("size of j: %lu\n", sizeof(j));
	
	for (int k=0; k < sizeof(i); ++k) { //somma ogni byte!
		*(q + k) =  *(p + k);
		//printf("%d°\n", k);	//Per vedere quanti byte sta sommando
	}
	printf("%ld == %ld\n", i, j);
	return 0;
}

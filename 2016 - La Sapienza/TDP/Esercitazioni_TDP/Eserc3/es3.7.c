#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ESEGUIMI PER COMPRENDERMI

int main (int argc, char **argv) {
	for (int i = -128; i < 128; i++) {
		printf("%d\t%c\n", i, i);
	}
	int x = 1;
	char c = 'A';
	printf("\nchar c = 'A';\nprintf(c = %%c\tc+1 = %%c);\n       c = %c\tc+1 = %c\n", c, (c+1));
	printf("\nint x = 1;\nprintf(x++ = %%d\t++x = %%d);\n     //x++ = %d\t++x = %d\n", (x++), (++x));
	x = 1;
	printf("x = 1;\nprintf(x-- = %%d\t--x = %%d);\n     //x-- = %d\t--x = %d", (x--), (--x));
	return 0;
}

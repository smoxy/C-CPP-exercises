#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int a = 0;
	int b;
	printf("&a= %p | &b= %p\n", &b, &a);
	int range = &a- &b;
	printf("range= %d\n", range);
	*(range + &b) = 1;
	if (a==1)
		printf("a è stato correttamente modificato\n");	
	return 0;
}

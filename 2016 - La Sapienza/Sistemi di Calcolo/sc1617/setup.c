#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	
	char* prog_name = strdup(argv[0]);
	printf("binary name: %s\n", prog_name);
	free(prog_name);
	
	return 0;
}

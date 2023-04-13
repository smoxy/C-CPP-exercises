#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	//int n = 0;
	//int minimum;
	int *ptr_n, *ptr_minimum;
	ptr_minimum = (int *)malloc(1*sizeof(int));
	ptr_n = (int *)malloc(1*sizeof(int));
	
	printf("Enter a int number:\t");
	scanf("%d", ptr_n);
	*ptr_minimum = *ptr_n;
	while (*ptr_n!=0) {
		printf("Enter a int number:\t");
		scanf("%d", ptr_n);
		if (*ptr_n < *ptr_minimum && *ptr_n!=0) {
			*ptr_minimum = *ptr_n;
		}
	}
	printf("The minimum is %d\n", *ptr_minimum);
	
	free(ptr_n); free(ptr_minimum);
	return 0;
}

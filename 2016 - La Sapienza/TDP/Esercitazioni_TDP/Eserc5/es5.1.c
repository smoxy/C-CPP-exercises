#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	int *data = (int *)malloc(2*sizeof(int));
	
	printf("Enter a int number:\t");
	scanf("%d", data);
	*(data+1) = *data;
	while (*data!=0) {
		printf("Enter a int number:\t");
		scanf("%d", data);
		if (*data < *(data+1) && *data!=0) {
			*(data+1) = *data;
		}
	}
	printf("The minimum is %d\n", *(data+1));
	
	free(data);
	return 0;
}

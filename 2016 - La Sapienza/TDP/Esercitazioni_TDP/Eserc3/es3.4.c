#include <stdio.h>

int main () {
	int n = 0;
	int minimum;
	printf("Enter a int number:\t");
	scanf("%d", &n);
	minimum = n;
	while (n!=0) {
		printf("Enter a int number:\t");
		scanf("%d", &n);
		if (n < minimum && n!=0) {
			minimum = n;
		}
	}
	printf("The minimum is %d\n", minimum);
	return 0;
}

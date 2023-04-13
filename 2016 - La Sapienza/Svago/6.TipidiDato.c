#include <stdio.h>
#include <stdlib.h>

long massimoArray(long v[], int n);

int main (int argc, char **argv) {
	const int n=5;
	long x[n] = {12,5,3,6,4};
	printf("Max = %ld\n", massimoArray(x,n));
	long c[n] = {1,5,3,6,4};
	printf("Max = %ld\n", massimoArray(c,n));
	return 0;
}

long massimoArray(long v[], int n) {
	long max = v[0];
	for (int i=0; i<n; i++) {
		if (v[i] > max) max = v[i];
	}
	return max;
}

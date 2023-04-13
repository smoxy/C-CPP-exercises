#include <stdio.h>
#include <stdlib.h>

int main () {
	int b = 0;
	char a;
	scanf("%c", &a);
	printf("%c\n", a);
	b = a=="y";
	printf("%d\n", b);
}

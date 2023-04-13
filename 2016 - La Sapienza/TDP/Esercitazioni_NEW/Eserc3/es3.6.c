#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	char c;
	printf("char c = ");
	scanf("%c", &c);
	unsigned char b;
	printf("unsigned char b = ");
	scanf("%hhu", &b);
	printf("CHAR c = %d\t\tunsigned char b = %hhu\n", c, b);
	short s;
	printf("short s = ");
	scanf("%hd", &s);
	int i;
	printf("int i = ");
	scanf("%d", &i);
	long l;
	printf("long l = ");
	scanf("%ld", &l);
	float f;
	printf("float f = ");
	scanf("%f", &f);
	double d;
	printf("double d = ");
	scanf("%lf", &d);
	
	printf("%hhu+10(%ld) = %ld\n", b, l, (b+10l)); 
	printf("(%hhu+%d)*%ld = %ld\n", b, i, l, ((b+i)*l));
	printf("(%hhu+%d)*%ld+%f = %f\n", b, i, l, f, ((b+i)*l+f));
	printf("%hd/%f + sin(%f) = %f\n", s, f, f, (s/f + sin(f)));
	printf("%c == '%hhu' = %d\n", c, b, (c == 'b'));
	printf("%ld + 1.5(%f) = %f\n", l, f, (l+1.5f));  
	printf("%d < 10 = %d\n", i, i<10);
	
	return 0;
}

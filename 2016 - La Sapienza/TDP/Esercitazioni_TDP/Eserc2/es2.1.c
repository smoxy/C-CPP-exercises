#include <stdio.h> /* definizione di funzioni di I/O */
#include <math.h> /* definizione di funzioni matematiche */

int main () {
  double a,b,x;
  printf("Enter the coefficients 'a' and 'b':");
  scanf("%lf %lf", &a, &b);
  x = -(b/a);
    printf("X = %.2f\n", x);
  return 0;
}

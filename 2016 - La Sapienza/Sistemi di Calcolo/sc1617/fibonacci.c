#include <stdio.h>
#include <stdlib.h>

// https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Fibonacci_Number_Program#Recursive_version
unsigned int fib(unsigned int n) {
    if (n < 2) return n;
    else return fib(n - 1) + fib(n - 2);
}

// https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Fibonacci_Number_Program#Iterative_version
unsigned int fib_iter(unsigned int n) {
    unsigned int i = 0, j = 1, k, t;
    for (k = 1; k <= n; ++k) {
        t = i + j;
        i = j;
        j = t;
    }
    return j;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
    printf("Syntax: %s <n>\n", argv[0]);
        return 1;
    }

    unsigned int n = atoi(argv[1]);
    printf("[%u] ric: %u iter: %u\n", n, fib(n), fib_iter(n));

    return 0;
}

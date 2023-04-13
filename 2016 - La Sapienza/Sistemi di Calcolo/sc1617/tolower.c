#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* to_lower (const char *str) {
    char* l = strdup(str);
    char* c;

    for (c = l; *c; c++) {
        if (isupper(*c))
            *c = tolower(*c);
    }
    free(c);
    return l;
}

int main (int argc, char* argv[])
{
    if (argc != 2) return 1;

    char* lower = to_lower (argv[1]);
    while (*lower)
        printf("%c", (*(lower++)));
    printf("\n");
    
    return 0;
}

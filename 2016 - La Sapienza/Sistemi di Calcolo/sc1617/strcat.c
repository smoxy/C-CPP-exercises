#include <string.h>
#include <stdio.h>

#define BUFLEN 16

int main() {
    char s1[BUFLEN], s2[BUFLEN];

    strncpy(s1,  "This is source", 8);
    snprintf(s2, 8, "%s", "This is destination");

    strncat(s2, s1, 8);

    printf("Final string: |%s|", s2);
    return 0;
}

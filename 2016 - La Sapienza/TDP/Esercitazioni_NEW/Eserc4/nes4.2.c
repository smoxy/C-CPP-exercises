#include <stdlib.h>
#include <stdio.h>

int main (int argc, char **argv) {
    int i = 10;
    int j = 20;
    char *p, *q;
    
    // Inserire codice qui senza (senza j = ...)
    p = (char*)&i;
    q = (char*)&j;
    for (int k=0; k<sizeof(q); k++) {
        q[k] = p[k];
    }
    
    printf("%d == %d\n", i, j);
    return 0;
}

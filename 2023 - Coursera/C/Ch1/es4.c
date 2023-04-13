/*Lines that begin '\vith a # are called pre-processing directives.     */
#include <stdio.h>

// These are symbolic constants, normally placed at the beginning of the file
#define LIMIT 100
#define PI 3.14159
#define C 299792.458 // speed of light in km/sec
                    /* the preprocessor first changes all occurrences
                        of the identifier LIMIT to 100 and all
                        occurrences of the identifier PI to 3.14159     */

int main(void){
    printf("LIMIT = %d\n", LIMIT);
    printf("PI = %f\n", PI);
    printf("C = %.3f\n", C);

    printf("\nCharacter constant\n");       // character constant
    printf("%c,%c,%c\n", 'a', 'b', 'c');
    printf("%2c,%2c,%2c\n", 'a', 'b', 'c'); // field width
    return 0;
}
/* write a program that find minmum, maximum, sum and average.
    The program exit when nothing is entered                */

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    double x, min, max, sum, avg;

    if (scanf("%lf", &x) != 1){
        printf("No data found - bye!\n");
        exit(1);
    }

    min = max = sum = avg = x;
    printf("%5s%9s%9s%9s%12s%12s\n%5s%9s%9s%9s%12s%12s\n\n",
        "Count", "Item", "Min", "Max", "Sum", "Average",
        "_____", "____", "___", "___", "___", "_______");
    printf("%5d%9.lf%9.lf%9.1f%12.3f%12.3f\n",
        1, x, min, max, sum, avg);

    for (i=2; scanf("%lf", &x)==1; i++){
        if (x<min) min = x;
        else if (x>max) max = x;
        sum += x;
        avg = sum/i;
        printf("%5d%9.lf%9.lf%9.1f%12.3f%12.3f\n",
            i, x, min, max, sum, avg);
    }
    return 0;
}

/* To execute this program with a data file in input execute:
 >$ printf "2 -3 5 -7 11 -13 17 -19 23 -29 31 -37 41 -43 47 -53 59 -61 67 -71 73 -79 83 -89 97" > data
 >$ ./es5 < ./data
                                                            */
/*
    write a program to convert a distance in miles and yards to kilometers. 
    To convert miles to kilometers, we multiply by the conversion factor 1.609, a real number.
*/

#include <stdio.h>

int main(void){
    float miles, yards, kilometers;

    printf("Enter the yards: ");
    scanf("%f", &yards);        // Read the expression &yards as "the address of yards" 
    printf("\nEnter the miles: ");
    scanf("%f", &miles);

    miles = miles + (yards/1760);
    kilometers = miles*1.609;

    printf("%.3f miles are %.3f kilometers\n", miles, kilometers);
    return 0;
}
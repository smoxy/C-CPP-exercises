#include <stdio.h>
#include <math.h>

/*
  <segnatura> := <tipo> <nome_funzione> ( <lista_parametri> )

  // serve a dire che esiste una funzione, NON cosa fa.
  <dichiarazione> := <segnatura> ;

  // serve a dire che esiste una funzione, NON cosa fa.
  <definizione> := <segnatura> { blocco }

  <lista_parametri>:= niente | <lista_parametri>, tipo nome 

*/


/* */
  
int fattoriale  (int i) {
  int f = 1;
  for (int j=1; j<=i; j++)
    f*=j;
  return f;
}

double floatingPointFunction(double x){
  //return cos(x);
  //return exp(-x)*cos(10*x)+x*x;

  x=0;
  return x;
  
}

double numericalDerivativeOfSomething(double x, double epsilon){
  return
    ( floatingPointFunction(x+epsilon) - 
      floatingPointFunction(x-epsilon) ) / (2*epsilon);
}


void printFirstNValuesAndTheirDerivative(double start, 
					 double step,
					 double num_values){
  double epsilon=1e-4;
  for (int i=0; i<num_values; i++){
    double x=start+i*step;
    double f_x=floatingPointFunction(x);
    double f_prime_x=numericalDerivativeOfSomething(x, epsilon);

    printf("%d %lf %lf %lf\n", i, x, f_x, f_prime_x); 
  }
}


void modifyValue(int x_local){
  x_local=0;
}


int main(int argc, char** argv) {
  // printf("fatt 5: %d\n", fattoriale(5));
  
  // printFirstNValuesAndTheirDerivative(0, 3.14/180, 180); 

  int x=10;
  modifyValue(x+10);
  printf("%d\n", x);
  

}

/* vediamola dopo

void addTwoArrays(float* dest, float* v1, float* v2, int size){
}

*/

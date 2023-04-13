#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"
#include "esercizio_1.h"

int main(int argc, char** argv) {
  const int total_test_number=10;
  int successes=0;
  int passed;
  int rows, cols;
  Mat* input_matrix;

  for(int i=0; i<total_test_number; ++i){
  
    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);

    rows = i+1;
    cols = i+2;

    input_matrix=matrixGenerate(rows,cols);

    Mat* dest_row = matrixAlloc(rows,cols);
    Mat* dest_col = matrixAlloc(rows,cols);
    
    //compute student result
    matrixGradient(dest_row, dest_col, input_matrix);

    passed=checkIfGood(input_matrix, dest_row, dest_col);
    if (passed){
      printf("SUCCESS\n");
      fflush(stdout);
      successes++;
    }
    else{
      printf("FAILURE\n");
    }


    printf("Current success rate: %0.02f%%\n", (float)(successes) * 100.0f/ (float)(total_test_number));
    fflush(stdout);
    printf("\n*************************************************\n\n");
    fflush(stdout);
    
  }

  printf("FINAL SUCCESS RATE: %0.02f%%\n", (float)(successes) * 100.0f / (float)(total_test_number));
  fflush(stdout);

  Mat_free(input_matrix);
  
  return 0;

  
}

#include <stdio.h>
#include "esercizio_2.h"
#include "correttore_esercizio_2.h"
#include <stdlib.h>

int main(int argc, char** argv) {
  const int total_test_number=10;
  int successes=0;
  int size=0;

  for(int i=0; i<total_test_number; ++i){

    printf("Test number %d out of %d\n", i + 1, total_test_number);
    fflush(stdout);
    size = i+1;

    ListElement* l = generateListElem(size);
    int array_size = 0;
    int* result_array = unzip(l, &array_size);
    
    if (checkIfGood(l, result_array, array_size)){
      printf("\n\nSUCCESS\n");
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
 
  return 0;
}

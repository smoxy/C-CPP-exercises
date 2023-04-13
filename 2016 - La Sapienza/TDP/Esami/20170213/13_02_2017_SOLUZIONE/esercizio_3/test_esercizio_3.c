#include <stdio.h>
#include <stdlib.h>
#include "esercizio_3.h"
#include "correttore_esercizio_3.h"

int main(int argc, char** argv) {
  const int total_test_number=10;
  int successes=0;
  int size=0;
  
  for(int test=0; test<total_test_number; ++test){

    printf("Test number %d out of %d\n", test + 1, total_test_number);
    fflush(stdout);
    size=test+1;

    ListElement* l1 = generateRandomOrderedList(size);
    ListElement* l2 = generateRandomOrderedList(size+1);

    ListElement* result = recursiveMerge(l1, l2);
    
    if (checkIfGood(l1,l2,result)){
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
 
  return 0;
}

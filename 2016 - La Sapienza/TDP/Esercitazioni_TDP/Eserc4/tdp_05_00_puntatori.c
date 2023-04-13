#include <stdio.h>
#include <stdlib.h>


// mio_parametro non viene alterato nel chiamante
void foo_not_changing(int mio_parametro) {
  mio_parametro=7;
}

// mio_parametro non viene alterato nel chiamante
// il valore nella LOCAZIONE a cui punta SI
void foo_changing(int* mio_parametro) {
  (*mio_parametro)=7;
  mio_parametro=0; // non fa nulla (per ora)
}


int main(int argc, char** argv) {
  int dimension;
  printf("enter dimension \n");
  scanf("%d",&dimension);

  /*
  foo_not_changing(dimension);
  printf("foo_not_changing dimension: %d\n", dimension);

  foo_changing(&dimension);
  printf("foo_changing dimension: %d\n", dimension);
  */

  // puntatore senza tipo
  void* v1_void = malloc(dimension*sizeof(float));
  // faccio il cast
  float* v1=(float*) v1_void;

  // faccio tutto in linea
  float* v2=(float*) malloc(dimension*sizeof(float));

  // dichiaro il target

  float* v_result=(float*) malloc(dimension*sizeof(float));

  for (int i=0; i<dimension; i++){
    *(v1+i)=i+1;
  }


  printf ("v1:\n");
  for (int i=0; i<dimension; i++){
    printf("%f\n",*(v1+i));
  }

  // variante con soli indirizzi, che incrementa di due
  float* v_end=v2+dimension;
  for (float* v_aux=v2; v_aux<v_end; v_aux++){
    *(v_aux)=((v_aux-v2)+1)*2;
  }

  printf ("v2:\n");
  for (int i=0; i<dimension; i++){
    printf("%f\n",*(v2+i));
  }

  for (int i=0; i<dimension; i++){
    *(v_result+i)=*(v1+i)+*(v2+i);
  }

  printf ("v_result:\n");
  for (int i=0; i<dimension; i++){
    printf("%f\n",*(v_result+i));
  }

  free (v1);
  free(v2);
  free(v_result);
  

  printf ("v_result:\n");
  for (int i=0; i<dimension; i++){
    printf("%f\n",*(v_result+i));
  }
  
  
}

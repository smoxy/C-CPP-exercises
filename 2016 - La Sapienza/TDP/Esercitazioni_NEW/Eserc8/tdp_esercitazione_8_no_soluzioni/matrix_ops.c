#include "matrix_ops.h"
#include "vec_ops.h"
#include <math.h>
#include <stdlib.h>

float  vec_dot(float *src1, float *src2, int dim);

/* esegue l'allocazione di un blocco conttiguo di memoria su cui genera
   un array di puntatori alle righe
*/

float** Matrix_allocContiguous(int num_rows, int num_cols){
  float* data= (float*) malloc(sizeof(float)*num_rows*num_cols);
  float** row_ptrs=(float**)malloc(sizeof(float*)*num_rows);
  
  for (int r=0; r<num_rows; r++){
    row_ptrs[r]=data+num_cols*r;
  }
  return row_ptrs;
}


/* esegue la deallocazione di un blocco contiguo a partire dai puntatori alle righe.
   1. cerca la lriga piu bassa, che si rigerisce al blocco contiguo
   2. elimina le righe
*/
void Matrix_freeContiguous(float**m, int num_rows){
  float* m_data=m[0];
  // find start row, as the smaller pointer in m
  for (int r=1; r<num_rows; r++)
    if (m[r]<m_data)
      m_data=m[r];
  // free the pointer array
  free(m);
  // free the data
  free(m_data);
}



int Matrix_zeroColumn(float**m, int num_rows, int num_cols, int col){
  int pivot_idx=Matrix_findMaxIdxInCol(m, num_rows, col);
  if (m[pivot_idx][col]==0)
    return 0;
  Matrix_exchangeRows(m, 0, pivot_idx);
  float pivot_value=m[0][col];
  for (int r=1; r<num_rows; r++){
    float element=m[r][col];
    float scale=-element/pivot_value;
    Matrix_sumAndScaleRows(m, r, 0,  num_cols,  scale);
  }
  return 1;
}


void Matrix_triangularize(float**m, int num_rows, int num_cols) {
  int r=0;
  for (int c=0; c<num_cols && r<num_rows; c++){
    int increment_row=Matrix_zeroColumn(m+r, num_rows-r, num_cols, c);
    r+=increment_row;
  }
}

float** Matrix_allocArrayOfArray(int num_rows, int num_cols){
  float** m = (float**)calloc(num_rows, sizeof(float*));
  for (int r=0; r<num_rows; r++) {
    m[r] = (float*)calloc(num_cols, sizeof(double));
    for (int c=0; c<num_cols; c++) {
      m[r][c] = 0;
    }
  }
  return m;
}

void Matrix_freeArrayOfArray(float** m, int num_rows){
  for (int r=0; r<num_rows; r++) {
    free(m[r]);
  }
}


float**  Matrix_alloc(int num_rows, int num_cols){
  // return Matrix_allocContiguous(num_rows, num_cols);
  return Matrix_allocArrayOfArray(num_rows, num_cols); //<<< dopo aver scritto Matrix_allocArrayOfArray(...) usare questa chiamata
}

void Matrix_free(float** m, int num_rows){
  // Matrix_freeContiguous(m, num_rows);
  Matrix_freeArrayOfArray(m, num_rows); //<<< dopo aver scritto Matrix_freeArrayOfArray(...) usare questa chiamata
}


void Matrix_write(FILE* f, float** m, int num_rows, int num_cols){
  fprintf(f,"%d %d\n", num_rows, num_cols);
  for (int r=0; r<num_rows; r++){
    for (int c=0; c<num_cols; c++)
      fprintf(f,"%.3f ",m[r][c]);
    fprintf(f, "\n");
  }
}

float** Matrix_read(FILE* f, int* num_rows, int* num_cols){
  int num_tokens=fscanf(f, "%d %d",num_rows, num_cols);
  if (num_tokens<2)
    return 0;
  float** m=0;
  m=Matrix_alloc(*num_rows, *num_cols);
  for (int r=0; r<*num_rows; r++)
    for (int c=0; c<*num_cols; c++) {
      if (feof(f)){
	Matrix_free(m, *num_rows);
	return 0;
      }
      fscanf(f,"%f",&m[r][c]);
    }
  return m;
}

void Matrix_writeOnPath(const char* filename, float** m, int num_rows, int num_cols) {
  FILE* f = fopen(filename, "w");
  if (!f)
    return;
  Matrix_write(f,m,num_rows,num_cols);
  fclose(f);
}

float** Matrix_readFromPath(const char* filename, int* num_rows, int* num_cols){
  FILE* f = fopen(filename, "r");
  if (!f)
    return NULL;
  float** m=Matrix_read(f,num_rows,num_cols);
  fclose(f);
  return m;
}


float** Matrix_clone(float** src, int num_rows, int num_cols){
  float** mclone = (float**)calloc(num_rows, sizeof(float*));
  for (int r=0; r< num_rows; r++) {
    mclone[r] = (float*)calloc(num_cols, sizeof(float));
    for (int c=0; c<num_cols; c++) {
      mclone[r][c] = src[r][c];
    }
  }
  return mclone;
}

float** Matrix_copyTransposed(float** src, int num_rows, int num_cols){
  float** mt = (float**)calloc(num_cols, sizeof(float*));
  for (int c=0; c<num_cols; c++) {
    mt[c] = (float*)calloc(num_rows, sizeof(float));
    for (int r=0; r<num_rows; r++) {
      mt[c][r] = src[r][c];
    }
  }
  return mt;
}

int  Matrix_extractBlock(float** dest, float** src, 
		   int num_rows, int num_cols, 
		   int block_start_row, int block_start_col,
		   int block_num_rows, int block_num_cols){
  printf("\tStart extractBlock\n");
  int cont=0, r1=0, c1=0;
  if (block_start_row < 0 || block_start_col < 0 || block_num_rows >= num_rows || block_num_cols >= num_cols) return -1;
  for (int r=block_start_row; r<=block_num_rows; r++) {
    for (int c=block_start_row; c<=block_num_cols; c++) {
      dest[r1][c1] = src[r][c];
      c1++;
    }
    c1=0;
    r1++;
  }
  printf("\tEnd extractBlock\n");
  return cont;
}


void Matrix_vectorProduct(float* dest, float** m, int num_rows, int num_cols, float* v) {
  for (int r=0; r<num_rows; r++) {
    dest[r] = vec_dot(m[r], v, num_cols);
  }
}

/*
scambia la riga r1 ed r2 nella matrice m
*/
void Matrix_exchangeRows(float**m , int r1, int r2){
  float* temp = m[r1];
  m[r1] = m[r2];
  m[r2] = temp;
}
 
/*
  somma alla riga r1+=r2*scale
*/
void Matrix_sumAndScaleRows(float** m, int r1, int  r2, int num_cols, float scale){
  for (int c=0; c<num_cols; c++) {
    m[r1][c] += m[r2][c]*scale;
  }
  
}


/*
  trova l'indice di riga che contiene il massimo valore (in modulo),
  considerando solo la colonna col
*/
int  Matrix_findMaxIdxInCol(float**m, int num_rows, int col) {
  int idx = 0;
  float max = 0.0;
  for (int r=0; r<num_rows; r++) {
    if(m[r][col] > max) {
      max = m[r][col];
      idx = r;
    }
  }
  return 0;
}

float  vec_dot(float *src1, float *src2, int dim) {
  float sum[dim], scl=0;
  for (int i=0; i<dim; i++) {
    sum[i] = src1[i] * src2[i];
  }
  for (int i=0; i<dim; i++) {
    scl += sum[i];
  }
  return scl;
}


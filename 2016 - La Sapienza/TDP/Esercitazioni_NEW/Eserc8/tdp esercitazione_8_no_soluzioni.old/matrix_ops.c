#include "matrix_ops.h"
#include "vec_ops.h"
#include <math.h>
#include <stdlib.h>


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
	printf("\n\tStart alloc\n");
	float **m = (float**)calloc(num_rows, sizeof(float*));
	for (int i = 0; i < num_rows; i++) {
		m[i] = (float*)calloc(num_cols, sizeof(float));
		for (int j = 0; j < num_cols; j++) { 
			m[i][j] = 0;	
		}
	}
	printf("\tEnd alloc\n\n");
	return m;
}

void Matrix_freeArrayOfArray(float** m, int num_rows){
	printf("\n\tStart free\n");
	for (int i=0; i<num_rows; i++) {
		free(m[i]);
	}
	free(m);
	printf("\tEnd free\n\n");
}


float**  Matrix_alloc(int num_rows, int num_cols){
  //return Matrix_allocContiguous(num_rows, num_cols);
  return Matrix_allocArrayOfArray(num_rows, num_cols); //<<< dopo aver scritto Matrix_allocArrayOfArray(...) usare questa chiamata
}

void Matrix_free(float** m, int num_rows){
  //Matrix_freeContiguous(m, num_rows);
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
	printf("\tStart clone\n");
	float **m = (float**)calloc(num_rows, sizeof(float*));
	for (int i=0; i<num_rows; i++) {
		m[i] = (float*)calloc(num_cols, sizeof(float));
		for (int j=0; j < num_cols; j++)
			m[i][j] = src[i][j];
	}	
	printf("\tEnd clone\n\n");
	return m;
}

float** Matrix_copyTransposed(float** src, int num_rows, int num_cols){
	printf("\tStart copyTransposed\n");
	float** m = (float**)calloc(num_cols, sizeof(float*));
	for (int i=0; i < num_cols; i++) {
		m[i] = (float*)calloc(num_rows, sizeof(float));
		for (int j=0; j < num_rows; j++)
			m[i][j] = src[j][i];
	}
	printf("\tEnd copyTransposed\n\n");
	return m;
}

int  Matrix_extractBlock(float** dest, float** src, 
		   int num_rows, int num_cols, 
		   int block_start_row, int block_start_col,
		   int block_num_rows, int block_num_cols){
	printf("\n\tStart Matrix_extractBlock\n");
	int c = 0;
	if (block_start_row < 0 || block_start_col < 0 || block_num_rows >= num_rows || block_num_cols >= num_cols) {
		printf("\tEnd Matrix_extractBlock with -1\n\n");
		return (-1);
	}
	for (int i=block_start_row; i <= block_num_rows; i++) {
		for (int j=block_start_col; j <= block_num_cols; j++) {
			dest[i-block_start_row][j-block_start_col] = src[i][j];
			c++;
		}
	}
	printf("\tElementi copiati = %d\n\tEnd Matrix_extractBlock\n\n", c);
	return c;
}


void Matrix_vectorProduct(float* dest, float** m, int num_rows, int num_cols, float* v) {
	printf("\tStart vectorProduct\n");
	int c=0;
	for (int i=0; i < num_rows; i++) {
		dest[i] = 0;
		for (int j=0; j < num_cols; j++) {
			printf("\tv[%d] = %.1f * %.1f\t= %.1f + %.1f\t", j, v[j], m[i][j], m[i][j] * v[j], dest[i]);
			dest[i] += m[i][j] * v[j];
			printf("= %.2f\n", dest[i]);
			c++;
		}
	}
	printf("\tEnd vectorProduct\n\n");
}

/*
scambia la riga r1 ed r2 nella matrice m
*/
void Matrix_exchangeRows(float**m , int r1, int r2){
	printf("\tStart exchangeRows\n");
	float *tmp = m[r1];
	m[r1] = m[r2];
	m[r2] = tmp;
	printf("\tEnd exchangeRows\n\n");
}
 
/*
  somma alla riga r1+=r2*scale
*/
void Matrix_sumAndScaleRows(float** m, int r1, int  r2, int num_cols, float scale){
	printf("\tStart sumAndScaleRows %f\n", scale);
	for (int c=0; c < num_cols; c++) {
		m[r1][c] = m[r1][c] + (m[r2][c] * scale);
	}
	printf("\tEnd sumAndScaleRows\n\n");
}


/*
  trova l'indice di riga che contiene il massimo valore (in modulo),
  considerando solo la colonna col
*/
int  Matrix_findMaxIdxInCol(float**m, int num_rows, int col) {
	printf("\tStart findMaxIdxInCol\n");
	int row;
	float max = 0;
	for (int r=0; r < num_rows; r++) {
		if (fabs(m[r][col]) > max) {
			max = fabs(m[r][col]);
			row = r;
		}		
	}
	printf("\tEnd findMaxIdxInCol\n\n");	
	return row;
}



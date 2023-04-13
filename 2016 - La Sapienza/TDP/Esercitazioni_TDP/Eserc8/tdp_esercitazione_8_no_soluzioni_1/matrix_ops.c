#include "matrix_ops.h"
#include "vec_ops.h"
#include <math.h>
#include <stdlib.h>

void printM(float **m);

/* esegue l'allocazione di un blocco conttiguo di memoria su cui genera
   un array di puntatori alle righr
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
  for (int i = 0; i < num_rows; i++) {
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
	printf("\n\tStart Matrix_clone\n");
	float **m = (float**)calloc(num_rows, sizeof(float*));
  for (int i = 0; i < num_rows; i++) {
		m[i] = (float*)calloc(num_cols, sizeof(float));
		for (int j = 0; j < num_cols; j++)
			m[i][j] = src[i][j];
	 }
	 printf("\tEnd Matrix_clone\n\n");
	 printM(m);
	return m;
}

float** Matrix_copyTransposed(float** src, int num_rows, int num_cols){
	printf("\n\tStart Matrix_copyTransposed\n");
	float **m = (float**)calloc(num_rows, sizeof(float*));
  for (int i = 0; i < num_cols; i++) {
		m[i] = (float*)calloc(num_cols, sizeof(float));
		for (int j = 0; j < num_rows; j++)
			m[i][j] = src[j][i];
	 }
	printf("\tEnd Matrix_copyTransposed\n\n");
	return m;

}

int  Matrix_extractBlock(float** dest, float** src, 
		   int num_rows, int num_cols, 
		   int block_start_row, int block_start_col,
		   int block_num_rows, int block_num_cols){
  /*esercizio*/
  printM(src);
  printM(dest);
  printf("\n\tStart Matrix_extractBlock\n");
	int dim_src = num_rows * num_cols;
	int dim_block = (block_num_rows + 1) * (block_num_cols + 1);
	if (dim_block > dim_src) {
		printf("\tEnd Matrix_extractBlock with -1\n\n");
		return -1;
	}
	int elem = 0;
	int i1 = 0;
	for (int i = block_start_row; i < block_num_rows; i++) {
		i1++;
		int j1 = 0;
		for (int j = block_start_col; j < block_num_cols; j++) {
			j1++;
			elem++;
			dest[i1][j1] = src[i][j];
			printf("%f ", dest[i1][j1]);
		}
		printf("\n");
	}
	printf("\tElementi copiati = %d\n\tEnd Matrix_extractBlock\n\n", elem);
  return elem;
}


void Matrix_vectorProduct(float* dest, float** m, int num_rows, int num_cols, float* v) {
  /*esercizio*/
  printf("\n\tStart Matrix_vectorProduct\n");
  int k = 0;
  for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_cols; j++) {
			dest[k] = m[i][j] * v[k];
			k++;
		}
	}
  printf("\tEnd Matrix_vectorProduct\n\n");
}

/*
scambia la riga r1 ed r2 nella matrice m
*/
void Matrix_exchangeRows(float**m , int r1, int r2){
	printf("\n\tStart Matrix_exchangeRows\n");
	float tmp = 0;
	int num_rows,	num_cols, num_elem;
	num_elem = sizeof(m) / sizeof(float);
	num_cols = sizeof(m[0]) / sizeof(float);
	for (int i = 0; i < num_cols; i++) {
		tmp = m[r1][i];
		m[r1][i] = m[r2][i];
		m[r2][i] = tmp;
	}
	//printf("r1 = %d e r2 = %d\n%d elementi, %d collonne e %d righe\n", r1, r2, num_elem, num_cols, num_rows);
	
  printf("\tEnd Matrix_exchangeRows\n\n");
}
 
/*
  somma alla riga r1+=r2*scale
*/
void Matrix_sumAndScaleRows(float** m, int r1, int  r2, int num_cols, float scale){
  /*esercizio*/
  printf("\n\tStart Matrix_sumAndScaleRows\n");
  for (int i = 0; i < num_cols; i++) {
		m[r1][i]+= m[r2][i] * scale;
	}
	printf("\tEnd Matrix_sumAndScaleRows\n\n");
}


/*
  trova l'indice di riga che contiene il massimo valore (in modulo/valore assoluto),
  considerando solo la colonna col
*/
int  Matrix_findMaxIdxInCol(float**m, int num_rows, int col) {
  /*esercizio*/
  printf("\n\tStart Matrix_findMaxIdxInCol\n");
  float max = 0;
  int riga;
  for (int i = 0; i < num_rows; i++) {		
		if (fabsf(m[i][col]) > max) {
			max = fabsf(m[i][col]);
			riga = i;
		}
	}
	printf("\tEnd Matrix_findMaxIdxInCol\n\n");
  return riga;
}

void printM(float **m) {
	int num_rows,	num_cols;
	num_cols = sizeof(m[0]) / sizeof(float);
	num_rows = (sizeof(m) / sizeof(float)) / num_cols;
	printf("MATRICE...\t...\t...\t...\n[");
	for (unsigned int r = 0; r < num_rows; r++) {
		for (unsigned int c = 0; c < num_cols; c++) {
			printf("%f ", m[r][c]);
		}
		printf("\b]\n");
	}
	printf("\n");
}





int **m= (int)malloc(sizeof(int*)*5);

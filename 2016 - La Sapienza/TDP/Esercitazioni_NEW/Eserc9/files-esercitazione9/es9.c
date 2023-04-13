#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int rows; 
  int cols;
  float **row_ptrs;
} Mat;

Mat* Mat_alloc(int rows, int cols);
Mat* Mat_read(char *filename);
void Mat_print(Mat *m);
void Mat_write(char *filename, Mat *m);
int  Mat_is_symmetric(Mat *m);
void Mat_normalize_rows(Mat *m);
Mat* Mat_clone(Mat *m);
void Mat_free(Mat *m);

int main(int argc, char **argv) {
  /********************************************************
   *             TEST Mat_alloc/Mat_read                  *
   ********************************************************/
  printf("Leggo m1 dal file mat_1.txt...");
  Mat *m1 = Mat_read("mat_1.txt");
  printf(" fatto.\n\n");

  /********************************************************
   *                    TEST Mat_print                    *
   ********************************************************/
  printf("m1:\n");
  Mat_print(m1);
  printf("\n");

  /********************************************************
   *                    TEST Mat_write                    *
   ********************************************************/
  printf("Scrivo una copia di m1 in copia_mat_1.txt...");
  Mat_write("copia_mat_1.txt", m1);
  printf(" fatto.\n\n");

  /********************************************************
   *                TEST Mat_is_symmetric                 *
   ********************************************************/
  printf("Leggo m2 dal file mat_2.txt...");
  Mat *m2 = Mat_read("mat_2.txt");
  printf(" fatto.\n");
  printf("m2:\n");
  Mat_print(m2);  
  printf("La matrice m2 e' simmetrica?\n");
  int is_symmmetric = Mat_is_symmetric(m2);
  if(is_symmmetric) {
    printf("Si e' simmetrica.\n");
  }
  else {
    printf("No non e' simmetrica.\n");
  }
  printf("\n");

  /********************************************************
   *               TEST Mat_normalize_rows                *
   ********************************************************/
  printf("Leggo m3 dal file mat_3.txt...");
  Mat *m3 = Mat_read("mat_3.txt");
  printf(" fatto.\n");
  printf("m3:\n");
  Mat_print(m3);  
  printf("Normalizzo le righe della matrice m3...");
  Mat_normalize_rows(m3);
  printf(" fatto.\n");
  printf("La matrice m3 con righe normalizzate e':\n");
  Mat_print(m3);
  printf("\n");

  /********************************************************
   *                    TEST Mat_clone                    *
   ********************************************************/
  printf("Clono m2...");
  Mat *copy_m2 = Mat_clone(m2);
  printf(" fatto.\n");
  printf("Copia m2:\n");
  Mat_print(copy_m2);  

  /********************************************************
   *                    TEST Mat_free                     *
   ********************************************************/
  Mat_free(copy_m2);
  Mat_free(m3);
  Mat_free(m2);
  Mat_free(m1);

  return 0;
}

Mat* Mat_alloc(int rows, int cols) {
  Mat* m = (Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (float**)calloc(rows, sizeof(float*));
  for (int c=0; c < m->cols; c++) {
    m->row_ptrs[c] = (float*)calloc(m->cols, sizeof(float));
  }
  return m;
}

Mat* Mat_read(char *filename) {
  FILE* fin = fopen(filename, "r");
  if (fin==NULL) {
    printf("Errore nell'apertura del file!");
    exit(-1);
  }
  int rows, cols, i=0;
  char buffer[1024];
  if (fscanf(fin, "%d", &rows) != 1) {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di righe... esco!\n", filename);
    exit(-1);
  }
  if (fscanf(fin, "%d", &cols) != 1) {
    printf("Errore durante la lettura del file %s, non riesco a leggere il numero di colonne... esco!\n", filename);
    exit(-1);
  }
  if(cols == 0 || rows == 0) {
    return NULL;
  }
  Mat *m = Mat_alloc(rows, cols);
  while (i < (m->rows * m->cols) && fscanf(fin, "%s", buffer) == 1) {
    int row = i / (m->cols);
    int col = i % (m->cols);
    m->row_ptrs[row][col] = atof(buffer);
    i++;
  }
  int ok = fclose(fin);
  if(ok!=0) {
    printf("Errore nella chiusura del file!\n");
    exit(-1);
  }
  return m;
}

void Mat_print(Mat *m) {
  for (int r=0; r<m->rows; r++) {
    
    for (int c=0; c<m->cols; c++) {
      printf("%.2f ", m->row_ptrs[r][c]);
    }
    printf("\n");
  }
}

void Mat_write(char *filename, Mat *m) {
  FILE* fout=fopen(filename, "w");
  if (fout==NULL) {
    printf("Errore nell'apertura del file!\n");
    exit(-1);
  }
  fprintf(fout, "%d ", m->rows);
  fprintf(fout, "%d\n", m->cols);
  for (int r=0; r<m->rows; r++) {    
    for (int c=0; c<m->cols; c++) {
      if (c==(m->cols - 1) && r==(m->rows-1)) fprintf(fout, "%.1f", m->row_ptrs[r][c]);
      else if(c==(m->cols - 1)) fprintf(fout, "%.1f\n", m->row_ptrs[r][c]);
      else fprintf(fout, "%.1f ", m->row_ptrs[r][c]);      
    }
  }
}

int  Mat_is_symmetric(Mat *m) {
  for (int r=0; r<m->rows; r++) {
    for (int c=0; c<m->cols; c++) {
       if (m->row_ptrs[c][r]!=m->row_ptrs[r][c]) return 0;
    }
  }
  return 1;
}

void Mat_normalize_rows(Mat *m) {
  for (int r=0; r<m->rows; r++) {
    float squaredSum = 0.0;
    for (int c=0; c<m->cols; c++) {
      squaredSum += m->row_ptrs[r][c] * m->row_ptrs[r][c];
    }
    for (int c=0; c<m->cols; c++) {
      m->row_ptrs[r][c] /= sqrtf(abs(squaredSum));
    }
  }
}

Mat* Mat_clone(Mat *m) {
  Mat* copy = Mat_alloc(m->rows, m->cols);
  for (int r=0; r<m->rows; r++) {
    for (int c=0; c<m->cols; c++) {
      copy->row_ptrs[r][c] = m->row_ptrs[r][c];
    }
  }
  return copy;
}

void Mat_free(Mat *m) {
  for (int r=0; r<m->rows; r++) {
    free(m->row_ptrs[r]);
  }
  free(m->row_ptrs);
  free(m);
}

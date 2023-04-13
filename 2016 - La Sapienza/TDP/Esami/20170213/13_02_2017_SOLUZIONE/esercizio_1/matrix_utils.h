#pragma once

typedef struct Mat {
  int rows; // numero di righe
  int cols; // numero di colonne
  int** row_ptrs; // puntatori alle righe
} Mat;

void matrixPrint(Mat* src);
Mat* matrixGenerate(int rows, int cols);
Mat* matrixAlloc(int row, int cols);
void Mat_free(Mat* mat);


int checkIfGood(Mat* src, Mat* dest_row_gradients, Mat* dest_col_gradients);

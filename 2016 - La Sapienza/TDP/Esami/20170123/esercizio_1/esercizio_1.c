#include "esercizio_1.h"
#include <stdlib.h>

Mat* Mat_alloc(int rows, int cols) {
  Mat* m = (Mat*)malloc(sizeof(Mat));
  m->rows = rows;
  m->cols = cols;
  m->row_ptrs = (int**)calloc(rows, sizeof(int*));
  for (int c=0; c < m->rows; c++) {
    m->row_ptrs[c] = (int*)calloc(cols, sizeof(int));
  }
  return m;
}

Mat* matrixRepeat(Mat* src, int num_row_blocks, int num_col_blocks) {
  Mat* nm = Mat_alloc(src->rows*num_row_blocks, src->cols*num_col_blocks);
  for (int r=0; r<nm->rows; r++) {
    for (int c=0; c<nm->cols; c++) {
      nm->row_ptrs[r][c] = src->row_ptrs[r%src->rows][c%src->cols];
    }
  }
  return nm;
}


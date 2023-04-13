#include "esercizio_1.h"
#include <stdlib.h>

void matrixGradient(Mat* row_gradient, Mat* col_gradient, Mat* src)
{
  int cols = src->cols;
  int rows = src->rows;

  for(int r=0; r<rows; ++r)
      for(int c=0; c<cols; ++c)
	{
	  if(r > 0)
	    row_gradient->row_ptrs[r][c] = src->row_ptrs[r][c] - src->row_ptrs[r-1][c];
	  if(c > 0)
	    col_gradient->row_ptrs[r][c] = src->row_ptrs[r][c] - src->row_ptrs[r][c-1];	  
	}
}


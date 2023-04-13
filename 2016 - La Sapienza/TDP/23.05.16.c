#include <stdio.h>
#include <stdlib.h>
//Spiegazione esercitazione 14

int main (int argc, char **argv) {

	return 0;
}

struct Image {
	int rows, cols;
	char * pixels;;
	char ** row_ptrs; //row -> riga
}
/**1) Azzero tutti i pixel di destinazione
 * 2) Per ogni pixel di destinazione: drc = isEdge(src, r, c, threshold)
 */
int isEdge(Image * src; int r; int c; char E) {
	char pixel_value = srx->row_ptrs[r][c];
	for (int r0 = r-1; r0 <= r+1; r0++)
		for (int c0 = c-1; c0 <= c+1; c0++) {
			if (r0 >= 0 && r0 < src->rows && c0 >= 0 && c0 < src->cols) {
				char target = src->row_ptrs[r0][c0];
				if (target_value - pixel_value > t)
					return 1;
				if (pixel_value - target_value > t)
					return 1;
			}
		}
}

void Image_extractEdges(Image* dest, Image* src, char threshold) {
  for (int r=0; r<src->rows; r++)  
    for (int c=0; c<src->cols; c++) {
      dest->row_ptrs[r][c]=isEdge(src, r, c, threshold);
    }
}

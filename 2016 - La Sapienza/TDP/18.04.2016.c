#include <stdio.h>
#include <stdlib.h>
// %d %f %c %s TIPI PRIMITIVI

/*******************************************
 * Il Prof da ora farà lezioni solo su C++ *
 *******************************************/


struct Image_s {
	int width;
	int height;
	char ** row_ptrs;
	int encoding; 
	typedef struct Image_s Image; //Per il C, in C++ non si usa. Il prof consiglia di usare solo C++
};
/*	Dichiarazione di immagini
 *	struct <nome tipo> {
 *  	<tipo 1> <nome 1>;
 *  	<tipo 2> <nome 2>;
 * 			.		.	 ;
 * 			.		.	 ;
 *  	<tipo n> <nome n>;
 * };
 */
 
/*
 *	Image img1;
 *	.
 *	. <cose che manipolano img1>	
 *	.
 *	img1.width = 640 //Per accedere a una variabile di tipo struct basta scrivere il suo nome.nome campo
 *	<Nome var>.<Nome campo>;
 *	Image img2;
 * 	img2 = img1; //Assegna il valore di img1 ad img2. Però entrambi vengo linkati alla stessa memoria, quindi modificandone uno modifico anche l'altro
 *  			//Allora per creare un'altra copia devi scriverti una funzione copiaStruct che clonerà in un'altra area di memoria.
 */
 
void draw (Image img) {
	int w = (* img).width; // = a scrivere: img - > width 
}


Image load (FILE *f) {

}

int main (int argc, char **argv) {
	FILE *f = fopen("cose.jpg", "r");
	Image loaded_img = load (f);	
	return;
}

struct Matrix3x3 {
	float values[3][3];
}

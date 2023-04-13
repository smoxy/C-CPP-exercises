/*
TAB = 4
Array:		Sequenza di valori aventi stesse dimensioni
			Richiamo di un valore dall'array: <Nome Array>[<posizione>]
											V[2]

Puntatore:	Può essere convertito a intero senza problemi, 
*/

																						//	|	STACK
int main(){																				//	|
	int i=5;																			//	|92		5		i
	int j=3;																			//	|100	3		j
	int * address_of_i=&i;																//	|108	92		address_of_i
 	  //↑			   ↑ l'operatore Ampersen ritorna l'indirizzo della variabile			|116	108		address_of_address_of_i
	//  ↑ l'operatore Star richiama la cella dell'array all'indirizzo della variabile		| ↑		 ↑		↑
	//<tipo> * <nome>;																		| ↑		 ↑		Nome Variabile
	(*address_of_i)=-3;	//sostituisce il contenuto dell'array n°address_of_i				| ↑		 Contenuto
	int ** address_of_address_of_i=&address_of_i;	// Puntatore a puntarore a intero		| Indirizzo di memoria
	* address_of_address_of_i=&j;														//	|
	(* address_of_i)++;																	//	|
																						//	|
}																						//	|

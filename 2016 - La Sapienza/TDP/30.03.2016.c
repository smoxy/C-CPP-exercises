#include <stdio.h>  //MALLOC = Locazione di memoria dinamica

void printTenInt () {
  for(int i=0; i<10; i++) {
    printf("%d", i);
  }
}
void  printTenInt2() {
	int* i_ptr=(int*)malloc(sizeof(int));
	for (*i_ptr=0; *i_ptr<10; *i_ptr++) {
		printf("%d", *i_ptr);
	}
}
void printSumOfTenInt(){
	int a=0;
	for (int i=0; i<10; i++) {
		a+=i;
    printf("%d", i);
  }
}
void printSumOfTenInt2() {
	int* a_ptr=(int*)malloc(sizeof(int)*2);
	*a_ptr=0;
	for (*(a_ptr+1)=0; *(a_ptr+1)<10; *(a_ptr+1)++) {
		*a_ptr+= *(a_ptr+1);
		printf("%d", *a_ptr);
	}
}

void gimmeMemory(int** v_ptr_ptr) {
	int* v_ptr=(int*)malloc(10+sizeof(int));
	for (int i=0; i<10; i++) {
		*(v_ptr+1)=i;
	}
	*v_ptr_ptr=v_ptr;
}
int main() {
	int* a_ptr;
	gimmeMemory(&a_ptr);
}

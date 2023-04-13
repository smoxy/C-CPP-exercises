#ifndef _ESERCIZIO_2_H_
#define _ESERCIZIO_2_H_

typedef struct ListElement {
  int value;
  int count;
  struct ListElement* next;
} ListElement;


int* unzip(ListElement* l,  int* v_dim);

#endif

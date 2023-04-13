#ifndef _ESERCIZIO_3_H_
#define _ESERCIZIO_3_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct ListElement {
  int info;
  struct ListElement* next;
} ListElement;

ListElement* recursiveMerge(ListElement* l1, ListElement* l2);

#endif

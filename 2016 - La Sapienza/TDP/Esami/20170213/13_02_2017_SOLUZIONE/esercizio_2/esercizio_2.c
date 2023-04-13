#include "esercizio_2.h"
#include <stdlib.h>

int* unzip(ListElement* l,  int* v_dim)
{
  ListElement* list_elem = l;
  int size = 0;
  while(list_elem != NULL) {
    size = size + list_elem->count;
    list_elem = list_elem->next;
  }
  *v_dim = size;
  int* array = (int*)malloc(sizeof(int)*size);
  int curr_pos = 0;
  list_elem = l;
  while(list_elem != NULL) {
    for(int i = 0; i<list_elem->count; ++i)
      {
	array[curr_pos] = list_elem->value;
	curr_pos = curr_pos+1;
      }
    list_elem = list_elem->next;
  }
  return array;
}

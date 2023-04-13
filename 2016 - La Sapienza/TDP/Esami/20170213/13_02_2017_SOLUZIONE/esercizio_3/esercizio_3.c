#include "esercizio_3.h"

ListElement* recursiveMerge(ListElement* l1, ListElement* l2){
  if(l1 || l2)
    {
      ListElement* result = (ListElement*)malloc(sizeof(ListElement));
      if(!l1)
	{
	  result->info = l2->info;
	  result->next = recursiveMerge(l1, l2->next);
	  return result;
	}
      if(!l2)
	{
	  result->info = l1->info;
	  result->next = recursiveMerge(l1->next, l2);
	  return result;
	}
      if(l1->info <= l2->info)
	{
	  result->info = l1->info;
	  result->next = recursiveMerge(l1->next, l2);
	  return result;
	}
      if(l2->info <= l1->info)
	{
	  result->info = l2->info;
	  result->next = recursiveMerge(l1, l2->next);
	  return result;
	}
    }
  else
    return NULL;
}


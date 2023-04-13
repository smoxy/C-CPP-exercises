#pragma once

struct ListElem {
  int info;
  ListElem* next;
};

int List_length(ListElem* p0);

void List_print(ListElem* l);

ListElem* List_makeFancyChain();

ListElem* List_pushFront(ListElem* l, int info);

ListElem* List_pushBack(ListElem* l, int info);

ListElem* List_find(ListElem* l, int info);

ListElem* List_at(ListElem* l, int pos);

ListElem* List_popFront(ListElem* l);

ListElem* List_popBack(ListElem* l);

ListElem* List_remove(ListElem* l, ListElem* removed);


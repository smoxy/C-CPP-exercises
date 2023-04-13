#include <stdlib.h>
#include <stdio.h>
#include "list_functions.h"

ListElem* List_makeFancyChain() {
  ListElem* p0=(ListElem*)malloc(sizeof(ListElem));
  p0->info=5;
  p0->next=(ListElem*)malloc(sizeof(ListElem));
  p0->next->info=7;
  p0->next->next=(ListElem*)malloc(sizeof(ListElem));
  p0->next->next->info=9;
  p0->next->next->next=NULL;
  return p0;
}

ListElem* List_pushFront(ListElem* p0, int info){
  ListElem* new_element=(ListElem*)malloc(sizeof(ListElem));
  new_element->next=p0;
  new_element->info=info;
  return new_element;
}

ListElem* List_popFront(ListElem* p0){
  if (p0==NULL)
    return NULL;
  ListElem* destroyed = p0;
  p0=p0->next;
  free(destroyed);
  return p0;
}



int List_length(ListElem* p0){
  int count=0;
  ListElem* aux=p0;
  while(aux!=NULL) {
    count++;
    aux=aux->next;
  }
  return count;
}




ListElem* List_find(ListElem* l, int key){
  ListElem* aux=l;
  while(aux!=NULL && aux->info!=key){
    aux=aux->next;
  }
  return aux;
}

ListElem* List_at(ListElem* l, int pos){
  int count=0;
  ListElem* aux=l;
  while(aux!=NULL && count<pos){
    aux=aux->next;
    count++;
  }
  return aux;
}


ListElem* List_pushBack(ListElem* l, int info){
  ListElem* new_element=(ListElem*)malloc(sizeof(ListElem));
  new_element->next=NULL;
  new_element->info=info;
  
  if (l==NULL){
    return new_element;
  }
  ListElem* aux=l;
  while(aux->next!=NULL){
    aux=aux->next;
  }
  aux->next=new_element;
  return l;

}


ListElem* List_popBack(ListElem* l){
  if (l==NULL)
    return NULL;

  // un solo elemento
  if (l->next==NULL){
    free(l);
    return NULL;
  }

  // piu' elementi
  // trova il penultimo e rimuovi
  ListElem* aux=l;
  while(aux->next->next!=NULL){
    aux=aux->next;
  }
  free(aux->next);
  aux->next=NULL;
  return l;
}

ListElem* List_remove(ListElem* l, ListElem* removed){
  // il primo elemento e' quello da eliminare
  // rimozione in testa
  if (l==removed) {
    return List_popFront(l);
  }
  // cerca l'elemento precedente a quello da rimuovere
  ListElem* aux=l;
  while(aux->next!=removed && aux->next!=NULL){
    aux=aux->next;
  }

  if (aux->next==NULL){ // sono arrivato in fondo e non ho trovato nulla
    return l;
  }
  
  aux->next=removed->next;
  free(removed);
  return l;
}


void List_print(ListElem* l){
  ListElem* aux=l;
  int pos=0;
  while(aux!=NULL){
    printf("pos: %d, info: %d\n", pos, aux->info);
    aux=aux->next;
    pos++;
  }
}

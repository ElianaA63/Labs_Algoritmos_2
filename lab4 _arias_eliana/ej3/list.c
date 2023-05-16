#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct _list {
  list_elem e;
  list next;
};

list empty_list() {
  list l = NULL;
  return l;
}

list addl(list_elem e,list l){
  list p = malloc(sizeof(struct _list));
  p->e = e;
  p->next = l;
  l = p;
  p= NULL;
  
  return l;
}

bool is_empty_list(list l) {
  return (l == NULL) ;
}

list_elem head(list l){
  assert(!is_empty_list(l));
  return l->e;
}

list tail(list l) {
  assert(!is_empty_list(l));
  list aux = l;
  l = l->next;
  aux->next = NULL;
  free(aux);
  return l;
}

list addr(list l, list_elem e) {
  list aux2 = empty_list();
  aux2 = malloc(sizeof(struct _list));
  aux2->e = e;
  aux2->next = NULL;

  list aux = l;
    
  if(!is_empty_list(aux)){
    while(aux->next != NULL){
      aux = aux->next;
    }
      aux->next = aux2;
  }else {
    l = aux2;
  }
  aux = NULL;
  aux2 = NULL;
  return l;
}

unsigned int length(list l) {
  unsigned int res = 0;
  list p = l;
  while(p != NULL) {
    p = p->next;
    res++;
  }
  return res;
}

list concat(list l1, list l2) {
  list aux = l1;
    
  if(!is_empty_list(l1)){
    while(aux->next != NULL){
      aux = aux->next;
    }
  }
  aux->next = l2;
  return l1;
}


list_elem index(list l, unsigned int i) {
  assert(i < length(l));
  list p = l;
  unsigned int c = 0;
  while(c<i) {
    p = p->next;
    c++;
  }
  return p->e;
}

list take(list l, unsigned int n){
 if(is_empty_list(l) || length(l) < n){
    return l;
  }

  list aux = l;
  unsigned int c = 1;
    while(c < n){
      aux = aux->next;
      c++;
    }
    list aux2 = aux->next;
    aux->next = NULL;
    aux2 = list_destroy(aux2);
    aux = NULL;
  return l;
}

list drop(list l, unsigned int n) {
  assert(n<length(l));
  unsigned int c = n;
    while(c > 0u && !is_empty_list(l)){
      l = tail(l);
      c--;
    }
  return l;
}

list copy_list(list l) {
  list copy = empty_list();
  list aux = l;
    while(aux->next != NULL){
      copy = addr(copy, aux->e);
      aux = aux->next;
    }
    copy = addr(copy, aux->e);
    aux = NULL;
    return copy;
}

list list_destroy(list l) {
  while(!is_empty_list(l)){
    l = tail(l);
  }
  return l;
}

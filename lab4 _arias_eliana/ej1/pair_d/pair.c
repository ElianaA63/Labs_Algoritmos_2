#include <stdio.h>
#include <stdlib.h>

#include "pair.h"

struct s_pair_t {
    elem fst;
    elem snd;
};

typedef struct s_pair_t _list;

pair_t pair_new(elem x, elem y){

    pair_t pair = malloc(sizeof(struct s_pair_t));
    pair->fst = x;
    pair->snd = y;
    return pair;
}

elem pair_first(pair_t p){
   return p->fst;
}

elem pair_second(pair_t p){
    return p->snd;
}

pair_t pair_swapped(pair_t p){

    pair_t s = malloc(sizeof(struct s_pair_t));
    s->fst = p->snd;
    s->snd = p->fst;

  return s;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return p;
}

/*¿Qué diferencia hay entre la especificación anterior y la que se
encuentra en el pair.h de la carpeta pair_d?
    -ahora la diferencia es que ahora al tener un typedef para los tipo de datos
     se puede modificar para cualquier tipo de datos ya sea para enteros para unsigned o 
     lo que fuese por ejemplo para unsigned int simplemente hacemos typedef unsigned int elem y
     trabajamos con elem que va a tener el tipo unsigned int..
    hay que respetar la estructura typedef <tipo> elem
*/

#include <stdio.h>
#include "pair.h"

pair_t pair_new(int x, int y){

    pair_t pair = {x,y};
    return pair;
}

int pair_first(pair_t p){
   return p.fst;
}

int pair_second(pair_t p){
    return p.snd;
}

pair_t pair_swapped(pair_t p){
    pair_t swap = {p.snd, p.fst};
    return swap;
}

pair_t pair_destroy(pair_t p){
    return p;
}

/*¿La implementación logra encapsulamiento? ¿Por qué sí? ¿Por qué no?
no no logra el encapsulamiento porque la estructura se encuentra en el pair.h 
y puede ser modificada desde alli permitiendo la modificacion de la implementacion*/
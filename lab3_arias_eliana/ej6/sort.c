/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){

    bool res = (*x).rank <= (*y).rank;

    return res;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a, player_t b) {
    struct _player_t temp = *a;
    *a = *b;
    *b = temp;
}

static unsigned int partition(player_t a[], unsigned int lft, unsigned int rgt) {
    assert(rgt > lft);

    unsigned int ppiv = lft;
    unsigned int j = lft + 1u;
    unsigned int k = rgt;

    while (j <= k) {
        if (goes_before(a[j], a[ppiv])) {
            ++j;
        }
        else if (!goes_before(a[k], a[ppiv])) {
            --k;
        }
        else {
            swap(a[j], a[k]);
            ++j;
            --k;
        }

    }

    swap(a[ppiv], a[k]);
    ppiv = k;

    return(ppiv);
}

static void quick_sort_rec(player_t a[], unsigned int lft, unsigned int rgt) {
    if (rgt > lft) {
        unsigned int ppiv = partition(a, lft, rgt);
        quick_sort_rec(a, lft, (ppiv == lft) ? lft : ppiv - 1u);
        quick_sort_rec(a, (ppiv == rgt) ? rgt : ppiv + 1u, rgt);
   }
}

void quick_sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

void sort(player_t a[], unsigned int length) {
    quick_sort(a, length);
}
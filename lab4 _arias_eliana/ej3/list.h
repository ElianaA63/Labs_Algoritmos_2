#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _list * list;
typedef int list_elem;


/*constructors*/

list empty_list();
/* Returns an empty list */

list addl(list_elem e,list l);
/* Adds element to list at the first position */

/*operations*/
bool is_empty_list(list l);
/* returns true if the list is empty*/

list_elem head(list l);
/* Returns the first element of the list
 * PRE: !is_empty_list(list)
 * */

list tail(list l);
/* removes the first item from the list
 * PRE: !is_empty_list(list)
 * */

list addr(list l, list_elem e);
/* adds element to the end of the list */

unsigned int length(list l);
/* returns the number of items in the list */

list concat(list l1, list l2);
/* Returns a list with the elements of l2 at the end of l1 */

list_elem index(list l, unsigned int i);
/* returns the n-th element in the list 
PRE: n < length(l) 
 */

list take(list l, unsigned int n);
/*leaves the first n elements in the list, eliminating the rest of the elements.*/

list drop(list l, unsigned int n);
/* removes the first n elements from the list
 * */
list copy_list(list l);
/* copies all items from the original list to a new list */

/*DESTROY*/
list list_destroy(list l);
/*free memory*/

#endif

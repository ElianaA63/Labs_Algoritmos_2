#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    FILE *file;
    file = fopen(filepath, "r");

    fscanf(file, "%u", &max_size);

    for (unsigned int j =0u; j < max_size; j++)
    {
        fscanf(file, "%d", &array[j]);
    }

    fclose(file);
    return(max_size);
}

void array_dump(int a[], unsigned int length) {
    
    printf ("[");
    for (unsigned int j = 0u; j< length; j++)
    {
        printf("%d", a[j]);
        if(j+1 != length){
            printf(", ");
        }    
    }
    printf("]\n");
}

bool array_is_sorted(int a[], unsigned int length){

    bool ordered = true;

    for ( unsigned int i =0u; i< length -1; i++)
    {
        ordered = ordered && (a[i] < a[i+1]);
    }
    
        if(ordered == true)
        {
            printf("El arreglo esta ordenado\n");
        }
        else{
            printf("El arreglo no esta ordenado\n");
        }
    return ordered;
}
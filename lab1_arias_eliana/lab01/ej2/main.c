/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

unsigned int array_from_stdin(int array[],int max_size){

    printf("Ingrese el tamaño del arreglo:\n");
    fscanf(stdin,"%d",&max_size);
    int j =0;

    while(!feof(stdin))
    {   
        printf("Ingrese el elemento numero %d del arreglo: \n", j);
        fscanf(stdin,"%d", &array[j]);
        j++;
    }

    return(max_size);
}
//me devuelve el arreglo por pantalla de esta forma [1, 2, 3]
void array_dump(int a[], unsigned int length) {
    
    printf ("[");
    for (unsigned int j = 0; j< length; j++)
    {
        printf("%d", a[j]);
        if(j+1 != length){
            printf(", "); //coloco coma luego de la primera posicion
        }    
    }
    printf("]\n");
}

int main(void) {

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    unsigned int length = array_from_stdin(array,MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    return EXIT_SUCCESS;
}

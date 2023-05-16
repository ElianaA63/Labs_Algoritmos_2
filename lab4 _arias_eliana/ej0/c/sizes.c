#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", /* Completar */
           sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));//EN EL ULTIMO sizeof puede llamarse a data_t

    return EXIT_SUCCESS;
}

/*
    ¿La suma de los miembros coincide con el total?
        -No, la suma de los miembros no coincide con el total.
    
    ¿El tamaño del campo name depende del nombre que contiene?
        -No, ya que el campo name tiene reservado un maximo de 30 bytes,
        por lo que el nombre puede ocupar desde "no tener nombre" a 
        un nombre con no más de 29 letras (ya que char = 1 byte + nulo = 1 byte)
        y aún así su tamaño será de 30 bytes.
Ej:
            "eliana" ocupa 6 bytes de los 30 bytes reservados en memoria
                por el campo name pero en realidad son 7 con el caracter nulo.
            "abcdefghijklmnñopqrstuvwxyzss" ocupa 29 bytes de los
                30 bytes reservados en memoria por el campo name.
            "abcdefghijklmnñopqrstuvwxyzsss" son 30 bytes, esto 
                muestra warning al momento de compilar ya que, teniendo
                en cuenta el caracter nulo que ocupa 1 byte, excede
                el espacio reservado en memoria por
por el campo name. 
*/



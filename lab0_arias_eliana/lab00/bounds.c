#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;//limite superior
    bool is_lowerbound;//limite inferior
    bool exists;//exite en el arreglo
    unsigned int where; //posicion donde se encuentra el elem.
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    //
    // TODO: COMPLETAR
    //
    res.is_upperbound=true;
    res.is_lowerbound=true;
    res.exists=false;
    res.where = 0;

    for(unsigned int i = 0; i < length; i++){

        if(value == arr[i]){
            res.exists = true;
            res.where = i;
        }
        //acumulo los resultados
        res.is_upperbound = res.is_upperbound && value >= arr[i];
        res.is_lowerbound = res.is_lowerbound && value <= arr[i];
           
    }

    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value;
    // TODO: COMPLETAR - Pedir entrada al usuario
    //
    printf("Ingrese un valor a chequear:");
    scanf("%d",&value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d", result.is_upperbound); // Imprime 1
    printf("%d", result.is_lowerbound); // Imprime 0
    printf("%u", result.exists);        // Imprime 1
    printf("%u", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}


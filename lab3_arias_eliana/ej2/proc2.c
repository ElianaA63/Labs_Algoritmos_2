#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if(x >= 0){
        *y = x; 
    }
    else{
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    a = -10;
    absolute(a, &res);
    printf("%d\n", res);
    return EXIT_SUCCESS;
}

/*
    ¿Se muestra el valor correcto?
    Si, res devuelve el valor 10, que es el absoluto de -10.
*/

/*
Para pensar:
● El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out
    Es de tipo in/out.

¿Qué tipo de parámetros tiene disponibles C para sus funciones?
○ Parámetros in
○ Parámetros out
○ Parámetros in/out
    C no tiene parámetros explicitos "in", "out" o "in/out", pero se pueden 
    simular mediante el uso de punteros y variables.
*/


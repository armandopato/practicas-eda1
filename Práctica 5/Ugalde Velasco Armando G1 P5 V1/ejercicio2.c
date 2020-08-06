#include <stdio.h>
#include "Pila.h"

int main (void)
{
    int i, tmp;
    Pila pila = crearPila();

    for (i = 0; i < 10; i++)
    {
        printf("Inserte el valor %d para la pila: ", i + 1);
        scanf("%d", &tmp);
        push(&pila, tmp);
    }


    Pila aux1, aux2;
    aux1 = crearPila();
    aux2 = crearPila();
    push(&aux2, pop(&pila));

    while (!isEmpty(pila))
    {
        push(&aux1, pop(&pila));
        if (top(aux1) > top(aux2))
        {
            push(&aux2, pop(&aux1));
        }
    }

    printf("El mayor elemento es: %d\n", top(aux2));

    return 0;
}

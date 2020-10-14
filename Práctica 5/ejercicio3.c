#include <stdio.h>
#include "Pila.h"
#include "Cola.h"

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

    imprimirPila(pila);
    Cola cola = crearCola();

    while (!isEmpty(pila))
    {
        encolar(&cola, pop(&pila));
    }

    while (!isEmptyQueue(cola))
    {
        push(&pila, desencolar(&cola));
    }

    imprimirPila(pila);

    return 0;
}

void imprimirPila(Pila pila)
{
    int i;
    printf("\nPila:\n");
    for (i = pila.tope - 1; i >= 0; i--)
    {
        printf("%d\n", pila.lista[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "colaDoble.h"

int main(void)
{
    int tamano;
    Cola queue1 = crearCola(8);

    printf("\n*****  ESTADO 1 ******\n");
    encolarFinal(&queue1, 101);
    encolarFinal(&queue1, 102);
    encolarFinal(&queue1, 103);
    encolarFinal(&queue1, 104);
    encolarFinal(&queue1, 105);
    desencolarInicio(&queue1);
    mostrarValores(queue1);
    mostrarIndices(queue1);

    printf("\n*****  ESTADO 2 ******\n");
    desencolarInicio(&queue1);
    encolarInicio(&queue1, 99);
    encolarInicio(&queue1, 98);
    encolarInicio(&queue1, 97);
    desencolarFinal(&queue1);
    encolarFinal(&queue1, 120);
    encolarFinal(&queue1, 121);
    mostrarValores(queue1);
    mostrarIndices(queue1);

    printf("\n*****  ESTADO 3 ******\n");
    desencolarInicio(&queue1);
    desencolarInicio(&queue1);
    desencolarInicio(&queue1);
    encolarFinal(&queue1, 122);
    mostrarValores(queue1);
    mostrarIndices(queue1);

    return 0;
}

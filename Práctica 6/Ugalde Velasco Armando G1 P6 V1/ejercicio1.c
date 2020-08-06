#include <stdio.h>
#include <stdlib.h>
#include "colaDoble.h"

int main(void)
{
    int tamano;
    printf("Ingresa el tamano\n");
    scanf("%d", &tamano);
    Cola queue1 = crearCola(tamano);
    encolarFinal(&queue1, 11);
    encolarFinal(&queue1, 12);
    mostrarValores(queue1);
    mostrarIndices(queue1);
    printf("Primera ejecucion **********\n");

    desencolarInicio(&queue1);
    desencolarInicio(&queue1);
    mostrarValores(queue1);
    mostrarIndices(queue1);
    printf("Segunda ejecucion **********\n");

    encolarFinal(&queue1, 13);
    encolarFinal(&queue1, 14);
    encolarInicio(&queue1, 10);
    encolarInicio(&queue1, 9);
    desencolarFinal(&queue1);
    mostrarValores(queue1);
    mostrarIndices(queue1);
    printf("Tercera ejecucion **********\n");
    return 0;
}

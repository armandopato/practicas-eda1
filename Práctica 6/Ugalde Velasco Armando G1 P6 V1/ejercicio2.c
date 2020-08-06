#include <stdio.h>
#include <stdlib.h>
#include "colaDoble.h"

int main(void)
{
    int tamano;
    printf("Ingresa el tamano\n");
    scanf("%d", &tamano);
    Cola queue1 = crearCola(tamano);

    encolarFinal(&queue1, 15);
    encolarFinal(&queue1, 25);
    encolarFinal(&queue1, 35);
    encolarFinal(&queue1, 45);
    encolarFinal(&queue1, 55);
    encolarFinal(&queue1, 65);
    encolarFinal(&queue1, 75);

    desencolarInicio(&queue1);
    desencolarInicio(&queue1);
    desencolarInicio(&queue1);

    encolarFinal(&queue1, 85);

    desencolarInicio(&queue1);

    mostrarValores(queue1);
    mostrarIndices(queue1);

    return 0;
}

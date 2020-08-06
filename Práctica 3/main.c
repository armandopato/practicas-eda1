#include <stdio.h>
#include "estructuras.h"
#include "auxiliares.h"
#include "mostrar.h"


int main(void)
{
    // Declarar arreglo de tiendas, variable auxiliar bandera y contador de no. de tiendas.
    Tienda tiendas[TAMTIENDAS];
    int bandera = 1;
    int noTiendas = 0;

    // Loop para regresar al menu principal.
    while(bandera)
    {
        printf("  MENU PRINCIPAL\n");
        printf("1) Crear una tienda (%d restantes)\n2) Mostrar tiendas\n3) Salir\n", TAMTIENDAS - noTiendas);

        int opcion;
        scanf("%d", &opcion);
        FLUSH;

        // Asegurarse de que el usuario introduzca una opcion correcta.
        while (opcion < 1 || opcion > 3)
        {
            printf("Ingrese una opcion correcta: ");
            scanf("%d", &opcion);
            FLUSH;
        }

        switch(opcion)
        {

        // Crear nueva tienda
        case 1:
            if (noTiendas < TAMTIENDAS)
            {
                tiendas[noTiendas++] = crearTiendaDepartamental();
            }
            else
            {
                printf("Se ha agotado el numero posible de tiendas\n");
            }
            break;

        // Mostrar tiendas
        case 2:
            mostrarTiendasDep(tiendas, noTiendas);
            break;

        // Salir
        case 3:
            bandera = 0;
            break;
        }
    }

    return 0;
}

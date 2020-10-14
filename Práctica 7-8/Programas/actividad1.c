#include <stdio.h>
#include "lista.h"

int main()
{
    Lista lista = crearLista();
    int flag = menu(&lista);
    while (!flag)
    {
        flag = menu(&lista);
    }
    return 0;
}

int menu(Lista *lista)
{
    int flag = 0;
    printf("\n***** MENU PRINCIPAL *****\n");
    printf("1) Agregar al principio\n2) Agregar al final\n3) Agregar i-esimo\n4) Eliminar al inicio\n5) Eliminar al final\n6) Buscar elemento\n7) Eliminar i-esimo\n8) Eliminar mayores\n9) Salir\n");
    int opcion;
    scanf("%d", &opcion);
    fflush(stdin);

    while (opcion < 1 || opcion > 9)
    {
        printf("Por favor, ingrese una opcion correcta: ");
        scanf("%d", &opcion);
    }

    switch(opcion)
    {
        case 1:
            addPrincipioLista(lista, solicitarElemento());
            break;

        case 2:
            addFinalLista(lista, solicitarElemento());
            break;

        case 3:
            addIesimoLista(lista, solicitarElemento());
            break;

        case 4:
            borrarPrimero(lista);
            break;

        case 5:
            borrarUltimo(lista);
            break;

        case 6:
            buscarElemento(lista, solicitarElemento());
            break;

        case 7:
            eliminarEnesimo(lista);
            break;

        case 8:
            eliminarMayores(lista);
            break;

        case 9:
            flag = 1;
            break;
    }

    printf("\n");
    print_list(*lista);
    return flag;
}





int solicitarElemento()
{
    int elemento;
    printf("Introduzca el elemento: ");
    scanf("%d", &elemento);
    fflush(stdin);
    return elemento;
}

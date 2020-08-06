#include <stdio.h>
#include "listaDobleCircular.h"

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
    printf("1) Agregar al principio\n2) Agregar al final\n3) Eliminar al inicio\n4) Eliminar al final\n5) Recorrer lista\n6) Salir\n");
    int opcion;
    scanf("%d", &opcion);
    fflush(stdin);

    while (opcion < 1 || opcion > 6)
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
            borrarPrimero(lista);
            break;

        case 4:
            borrarUltimo(lista);
            break;

        case 5:
            recorrerLista(*lista);
            break;

        case 6:
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

#include <stdio.h>
#include "listacirc.h"

int menu(Lista *lista);
Automovil *crearAutomovil();
void eliminarAutomovil(Automovil *carro);
char *obtenerMarca(Automovil *carro);
void obtenerInfo(Automovil *carro);
char *solicitarMarca();


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
    printf("1) Agregar al principio\n2) Agregar al final\n3) Eliminar al inicio\n4) Eliminar al final\n5) Buscar automovil por marca\n6) Recorrer lista\n7) Salir\n");
    int opcion;
    scanf("%d", &opcion);
    fflush(stdin);

    while (opcion < 1 || opcion > 7)
    {
        printf("Por favor, ingrese una opcion correcta: ");
        scanf("%d", &opcion);
        fflush(stdin);
    }

    switch(opcion)
    {
        case 1:
            addPrincipioLista(lista, crearAutomovil());
            break;

        case 2:
            addFinalLista(lista, crearAutomovil());
            break;

        case 3:
            borrarPrimero(lista);
            break;

        case 4:
            borrarUltimo(lista);
            break;

        case 5:
            buscarElemento(lista, solicitarMarca());
            break;

        case 6:
            recorrerLista(lista);
            break;

        case 7:
            flag = 1;
            break;
    }

    printf("\n");
    print_list(*lista);
    return flag;
}

// OPERACIONES DE AUTOMOVIL

Automovil *crearAutomovil()
{
    Automovil *nuevoCarro = malloc(sizeof(Automovil));
    printf("Por favor, introduzca los datos del nuevo auto:\n");
    printf("Marca: ");
    fgets(nuevoCarro->marca, 99, stdin);
    fflush(stdin);
    printf("Modelo: ");
    fgets(nuevoCarro->modelo, 99, stdin);
    fflush(stdin);
    printf("Color: ");
    fgets(nuevoCarro->color, 99, stdin);
    fflush(stdin);
    printf("Placas: ");
    fgets(nuevoCarro->placas, 99, stdin);
    fflush(stdin);

    return nuevoCarro;
}

void eliminarAutomovil(Automovil *carro)
{
    free(carro);
}

char *obtenerMarca(Automovil *carro)
{
    return carro->marca;
}

void obtenerInfo(Automovil *carro)
{
    printf("Marca: %s", carro->marca);
    printf("Modelo: %s", carro->modelo);
    printf("Color: %s", carro->color);
    printf("Placas: %s\n", carro->placas);
}

// AUXILIARES

char *solicitarMarca()
{
    char *marca = malloc(sizeof(char)*100);
    printf("Marca del automovil: ");
    fgets(marca, 99, stdin);
    fflush(stdin);
    return marca;
}

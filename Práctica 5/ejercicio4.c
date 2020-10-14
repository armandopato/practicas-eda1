#include <stdio.h>
#include "Cola.h"

Libro crearLibro();

int main (void)
{
    int tam, i, tiempoTmp, tiempoTotal = 0;
    Libro tmp;

    printf("Cual es el tamaño de la cola? ");
    scanf("%d", &tam);
    fflush(stdin);

    ColaLibros cola = crearColaLibros(tam);
    for (i = 0; i < tam; i++)
    {
        encolarLibro(&cola, crearLibro());
    }


    while(!isEmptyQueueLibros(cola))
    {
        tmp = desencolarLibro(&cola);
        tiempoTmp = (tmp.pags * 20) / 60;
        printf("LIBRO %s\n", tmp.titulo);
        printf("Numero de paginas: %d\n", tmp.pags);
        printf("Tiempo de lectura: %d minutos\n\n", tiempoTmp);
        tiempoTotal += tiempoTmp;
    }

    printf("TIEMPO TOTAL DE LECTURA: %d minutos\n", tiempoTotal);

    eliminarColaLibros(cola);

    return 0;
}

Libro crearLibro()
{
    Libro x;

    printf("Titulo: ");
    gets(x.titulo);
    fflush(stdin);

    printf("Autor: ");
    gets(x.autor);
    fflush(stdin);

    printf("Paginas: ");
    scanf("%d", &x.pags);
    fflush(stdin);

    printf("Clave: ");
    scanf("%d", &x.clave);
    fflush(stdin);

    printf("\n");
    return x;
}


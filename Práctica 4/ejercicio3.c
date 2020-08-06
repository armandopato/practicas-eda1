#include <stdio.h>
#define FLUSH fflush(stdin)


typedef struct automovil
{
    char marca[100];
    char modelo[100];
    char color[100];
    char tipoDeAuto[100];
} Automovil;


Automovil nuevoAuto();
void imprimirArreglo(Automovil *arr, int tam);


int main(void)
{
    int tam, i;
    printf("Digite el tamano del arreglo: ");
    scanf("%d", &tam);

    while (tam <= 0)
    {
        printf("Digite un valor valido: ");
        scanf("%d", &tam);
    }

    Automovil *arr = calloc(tam, sizeof(Automovil));

    for (i = 0; i < tam; i++)
    {
        printf("\nAUTOMOVIL %d\n", i+1);
        arr[i] = nuevoAuto();
    }

    printf("\n");

    imprimirArreglo(arr, tam);
    free(arr);
    return 0;
}



Automovil nuevoAuto()
{
    Automovil nuevo;

    printf("Marca: ");
    scanf("%s", nuevo.marca);
    FLUSH;

    printf("Modelo: ");
    scanf("%s", nuevo.modelo);
    FLUSH;

    printf("Color: ");
    scanf("%s", nuevo.color);
    FLUSH;

    printf("Tipo de auto: ");
    scanf("%s", nuevo.tipoDeAuto);
    FLUSH;

    return nuevo;
}


void imprimirArreglo(Automovil *arr, int tam)
{
    int i;
    Automovil foo;

    printf("\nCARROS\n\n");

    for(i = 0; i < tam; i++)
    {
        foo = arr[i];

        printf("AUTOMOVIL %d:\n", i+1);
        printf("%s\n", foo.marca);
        printf("%s\n", foo.modelo);
        printf("%s\n", foo.color);
        printf("%s\n\n", foo.tipoDeAuto);
    }
}

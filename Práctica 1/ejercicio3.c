#include <stdio.h>

void imprimirOriginal(int arr[]);

int main (void)
{
    // Se crea el arreglo de las dimansiones especificadas y se declaran los contadores.
	int arr[4][6], i, j;

    printf("Ingresa 6 numeros: ");
    // Se almacenan los datos proporcionados en la primera fila del arreglo.
    scanf("%d%d%d%d%d%d", &arr[0][0], &arr[0][1], &arr[0][2], &arr[0][3], &arr[0][4], &arr[0][5]);

    // Se asignan los valores correspondientes a las filas restantes
    for (i = 1; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
        {
            arr[i][j] = arr[i-1][j] * 3;
        }
    }

    // Se imprime el nuevo arreglo
    printf("\nEl nuevo arreglo es:\n");
	for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%d   ", arr[i][j]);
        }
        printf("\n\n");
    }
}

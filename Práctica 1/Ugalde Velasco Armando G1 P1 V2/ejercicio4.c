#include <stdio.h>
#include <math.h>

void puro(int arr[]);
void compA2(int arr[]);

int main (void)
{
    // Se crea el arreglo de las dimensiones especificadas y se declaran los contadores.
    int arr[10], i, tmp, contador;
    contador = 0;

    while (contador < 10)
    {
        printf("Introduzca el bit %d\n", contador+1);
		scanf("%d", &tmp);
		if (tmp != 0 && tmp != 1)
        {
            printf("Introduzca un valor valido\n");
        }
        else
        {
            arr[contador] = tmp;
            contador++;
        }
    }

	int opcion;


	while(1)
    {
        printf("\nElija una opción:\n");
        printf("1) Binario puro\n2) Signo y magnitud\n3) Complemento a 2\n");
        scanf("%d", &opcion);

        if (opcion > 0 && opcion < 4)
        {
            break;
        }
        else
        {
            printf("\nDigite un valor valido\n");
        }
    }


	switch(opcion)
	{
		case 1:
		    puro(arr);
			break;

		case 2:
		    signoyMagnitud(arr);
			break;

		case 3:
		    compA2(arr);
			break;
	}
	return 0;
}

void puro(int arr[])
{
    int numero, i;
    numero = 0;

    int potencia = 9;
    for (i = 0; i < 10; i++)
    {
        if (arr[i])
        {
            numero += pow(2, potencia);
        }
        potencia--;
    }

    printf("El valor es: %d", numero);
}

void signoyMagnitud(int arr[])
{
    int magnitud, i;
    magnitud = 0;

    int potencia = 8;
    for (i = 1; i < 10; i++)
    {
        if (arr[i])
        {
            magnitud += pow(2, potencia);
        }
        potencia--;
    }

    printf("El valor es: %s%d", arr[0]? "-" : "", magnitud);
}

void compA2(int arr[])
{
    if (arr[0])
    {
        int i;
        int encontrado = 0;

        // Implementacion del algoritmo de conversion de complemento a 2
        for (i = 9; i > 0; i--)
        {
            // Si no se ha encontrado el primer 1, el arreglo no se modifica
            if (!encontrado)
            {
                // Si el elemento actual es 1, modificar la bandera
                if (arr[i])
                {
                    encontrado = 1;
                }
            }
            // Si el primer uno ya fue encontrado, modificar el bit a su opuesto.
            else
            {
                arr[i] = arr[i]? 0 : 1;
            }
        }
    }

    signoyMagnitud(arr);
}

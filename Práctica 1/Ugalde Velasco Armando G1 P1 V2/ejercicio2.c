#include <stdio.h>

void imprimirOriginal(int arr[]);
void suma(int arr[]);
void multi(int arr[]);
void suma4(int arr[]);
void mult3(int arr[]);


int main (void)
{
	int arr[15], i;
	for (i = 0; i < 15; i++)
	{
		printf("Introduzca el valor %d\n", i+1);
		scanf("%d", &arr[i]);
	}

	int opcion;

	// El usuario debe introducir un número del 1 al 4,
	// de lo contrario, se le solicitará de nuevo
	while(1)
    {
        printf("\nElija una opción:\n");
        printf("1) Suma\n2) Multiplicacion\n3) Suma de elementos divisibles entre 4\n4) Multiplicar por 3 cada elemento\n");
        scanf("%d", &opcion);

        if (opcion > 0 && opcion < 5)
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
			suma(arr);
			break;

		case 2:
			multi(arr);
			break;

		case 3:
			suma4(arr);
			break;

		case 4:
			mult3(arr);
			break;
	}
	return 0;
}

// Función que se encarga de realizar e imprimir la suma de todos los elementos (opción 1)
void suma(int arr[])
{
	int suma, i;
	suma = 0;

	imprimirOriginal(arr);

	for (i = 0; i < 15; i++)
	{
		suma += arr[i];
	}
	printf("La suma es: %d\n", suma);
}

// Función que se encarga de realizar e imprimir el resultado del producto de todos los elementos (opción 2)
void multi(int arr[])
{
	int mult = 1;
	int i;

	imprimirOriginal(arr);

	for (i = 0; i < 15; i++)
	{
		mult *= arr[i];
	}
	printf("La multiplicacion de los elementos es: %d\n", suma);
}

// Función que se encarga de realizar e imprimir la suma de los elementos divisibles entre 4 (opción 3)
void suma4(int arr[])
{
	int suma, e, i;
	suma = 0;

	imprimirOriginal(arr);

	for (i = 0; i < 15; i++)
	{
		e = arr[i];

		if (e % 4 == 0)
		{
			suma += e;
		}
	}
	printf("La suma de los elementos divisibles entre 4 es: %d\n", suma);
}

// Función que se encarga de imprimir el arreglo con los elementos multiplicados por 3
void mult3(int arr[])
{
    int i;
	imprimirOriginal(arr);
	printf("Los elementos multiplicados por 3 son: \n");
	for (i = 0; i < 15; i++)
	{
		printf("%d ", arr[i]*3);
	}
	printf("\n");
}

// Funcion que se encarga de imprimir los elementos del arreglo original (opción 1)
void imprimirOriginal(int arr[])
{
    int i;
	printf("\nEl arreglo original es:\n");
	for (i = 0; i < 15; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
}

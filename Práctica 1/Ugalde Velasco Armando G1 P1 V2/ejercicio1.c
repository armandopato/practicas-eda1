#include <stdio.h>

int main (void)
{
	int i, j, k;
	int arr[3][2][5] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60};

	// Los contadores ahora corresponden con las dimensiones del arreglo: 3, 2 y 5.
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			for (k = 0; k < 5; k++)
			{
				printf("Arreglo [%d][%d][%d]: %d \n", i, j, k, arr[i][j][k]);
			}
		}
	}
	return 0;
}

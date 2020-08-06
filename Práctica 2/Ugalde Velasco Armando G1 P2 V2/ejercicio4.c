#include <stdio.h>
#include <math.h>

void modificarArreglo(int arr[5][4]);

int main()
{
    int arr[5][4], i, j;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("Digite el elemento [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    modificarArreglo(arr);

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("Elemento [%d][%d]:  %d\n", i, j, arr[i][j]);
        }
    }


    return 0;
}


void modificarArreglo(int arr[5][4])
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i % 2 == 0)
            {
                arr[i][j] *= 2;
            }
            else
            {
                arr[i][j] *= 3;
            }
        }
    }
}

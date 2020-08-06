#include <stdio.h>
#include <math.h>

void calcular(int *x, int *y);

int main()
{
    int a, b;
    printf("Por favor, introduzca dos enteros:  ");
    scanf("%d%d", &a, &b);
    calcular(&a, &b);
    printf("Los valores son: %d y %d\n", b, a);

    return 0;
}


void calcular(int *x, int *y)
{
    *y = pow(*x, *y);
    *x = *y / *x;
}

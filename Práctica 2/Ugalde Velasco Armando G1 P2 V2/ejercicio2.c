#include <stdio.h>
int arr1[4][5][2], var,i,j,k;
int *point;
void main()
{
    int i;
    // Puntero al primer elemento del arreglo arr1
    point = arr1;
    var=1;
    // Recorrer el arreglo con ciclos anidados
    // Planos
    for (i=0; i<4; i++)
    {
        // Filas
        for(j=0; j<5; j++)
        {
            // Columnas
            for(k=0; k<2; k++)
            {
                // Asignar a cada elemento la variable var, de valor inicial 1
                arr1[i][j][k]=var;
                // Aumentar dos unidades el valor de la variable var en cada iteración.
                var+=2;
            }
        }
    }

    // Utilizar el operador de indirección en determinado elemento del arreglo.

    // Tomando en cuenta que los arreglos se almacenan de forma contigua,
    // y que "point" es la dirección del primer elemento:

    // arr[0][2][0]
    int a= *(point+4);
    printf("%d = %d\n", arr1[0][2][0], a);

    // arr[1][3][0]
    int b= *(point+16);
    printf("%d = %d\n", arr1[1][3][0], b);

    // arr[2][1][1]
    int c= *(point+23);
    printf("%d = %d\n", arr1[2][1][1], c);

    // Modificar el arreglo con las condiciones propuestas.
    int aumento = 5, acum = 5;

    // Recorrer los 40 elementos del arreglo.
    for (i = 0; i < 40; i++)
    {
        // Modificar cada elemento, con su dirección de memoria.
        *(point) = acum;
        // Aumentar la variable acumulador con su respectivo incremento.
        acum += aumento;

        // Cambiar el incremento cuando se termine de modificar cada plano.
        // El valor inicial de la variable acumulador será el mismo del incremento.
        if (i == 9)
        {
            aumento = 6;
            acum = 6;
        }
        else if (i == 19)
        {
            aumento = 7;
            acum = 7;
        }
        else if (i == 29)
        {
            aumento = 3;
            acum = 3;
        }
        printf("elemento %d: %d\n", i+1, *(point));

        // Incrementar el puntero para acceder a la siguiente localidad de memoria,
        // es decir, al siguiente elemento del arreglo.
        point++;
    }
}

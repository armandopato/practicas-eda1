#include <stdio.h>
/*El objetivo de este programa es operar con variables de manera indirecta */
void main()
{
    int w=10, x=20, y=30, z=40, r1,r2,r3;

    // Corregir el apuntador p3 (agregar el operador *)
    int *p1, *p2, *p3, *p4;

    // Inicializar los apuntadores:

    p1=&w;
    // Eliminar el operador * de los apuntadores
    // p2 y p3 para inicializarlos
    p2=&x;
    p3=&y;
    // Eliminar el operador * de p1
    p4=p1;

    // Error: se suma un puntero con un entero, pero se asigna a una variable
    // de tipo entero, lo cual probablemente no es la operación deseada.
    // Corrección: agregar el operador de indirección a la variable p1,
    // para así sumar su valor y no su dirección de memoria.
    r1= (*p1) + (*p2);

    // Error: la multiplicación entre punteros no es una operación
    // permitida.
    // Es probable que la operación deseada en realidad se
    // trate de la multipicación de dos enteros, es decir, del valor a los que apuntan
    // las variables p3 y p4.
    // Corrección: agregar el operador de indirección en las variables p3
    // y p4, para obtener su valor.
    r2= (*p3) * (*p4);

    // No es posible utilizar el operador de indirecciòn en la variable r3,
    // ya que no es un puntero.
    // Corrección: remover el operador de indirección de r3.
    r3= (*p2) + (*p3);
    printf("Los Resultados son: %d, %d y %d",r1,r2,r3);
}

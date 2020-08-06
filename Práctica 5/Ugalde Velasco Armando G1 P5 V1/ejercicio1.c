#include "Pila.h"

main(){
    printf("vamos a crear una pila \n");
    Pila miPila = crearPila();
    printf("vamos a ingresar algunos elementos \n");
	push(&miPila,10); // cambiar funcion meter por PUSH
    push(&miPila,20);
    push(&miPila,30);
	push(&miPila,40);
    push(&miPila,50);
    printf("El tope de la pila es: %d \n",miPila.tope);    //recuerda que el tope es un índice
	printf("El valor almacenado hasta arriba es: %d \n",top(miPila));   // error: miPila.top() correccion: top(miPila);
	int a = pop(&miPila); // cambiar funcion sacar por pop
  	printf("Ahora el tope de la pila es : %d \n",miPila.tope);
	int b = pop(&miPila);
  	int c = pop(&miPila);
  	printf("Ahora el valor hasta arriba es: %d \n",top(miPila));
	int d = pop(&miPila);
    printf("valor de c es: %d \n",c);

}



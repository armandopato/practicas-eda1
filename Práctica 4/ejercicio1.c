#include <stdio.h>
#include <stdlib.h>
main(){

	int cont,arreglo[]={35,40,45,50,55};
	int variable;
	int *ptr = calloc(10, sizeof(int));
	char *ptr2 = malloc(100*sizeof(char));

	//Imprimiendo direcciones de un arreglo
	for(cont=0;cont<10;cont++){
		printf("direccion arreglo[%d]=%d   valor arreglo[%d]=%d\n",cont,&arreglo[cont],cont,arreglo[cont]);
	}
	printf("\n");


	//Imprimiendo direcciones y contenido de un apuntador de memoria dinámica reservado con malloc
	for(cont=0;cont<10;cont++){
		printf("direccion=%d   *valor=%d \n",ptr+cont, *(ptr+cont));
	}
	printf("\n");

	// b) Asignar valores en las localidades de memoria reservadas con memoria dinámica (múltiplos de 5).
	int acum = 5;

	for(cont=0; cont<10; cont++){
		*(ptr + cont) = acum;
		acum += 5;
		printf("direccion=%d   *valor=%d \n",ptr+cont, *(ptr+cont));
	}
	printf("\n");

    /* No remover estos comentarios, (por lo menos no antes de acabar la actividad1) /*/
 	//strcpy(ptr2,"hola amigo como estas");  //esto si se puede hacer
	// //ptr2 = "Hola amigo como estas";    //nunca haga esto compa
  	//for(cont=0;cont<100;cont++){
 	//   printf("%c",ptr2[cont]);     //no vaya a descomentar esta linea, ni cambiar el contador del for a 1000 (
 	//}

 	// d) Redimensionar ptr
 	printf("La direccion del apuntador ptr es: %d\n", ptr);
 	int *ptr3 = realloc(ptr, 20*sizeof(int));
 	printf("La nueva direccion del apuntador ptr es: %d\n", ptr3);


	free(ptr);
	free(ptr2);

	system("PAUSE");
}


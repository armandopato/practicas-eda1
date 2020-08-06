#include "Alumno.h"
#define FLUSH fflush(stdin)

Alumno asignarAlumno();

main(){
	int j;
	printf("Tamaño de objeto Alumno = %d \n",sizeof(Alumno));
	Alumno *din1,*din2,*din3;
	din1 = malloc(5*sizeof(Alumno));
	din2 = calloc(5,sizeof(Alumno));

	printf("Primer apuntador: \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d]=%d \n",j,din1+j);
	}
	printf("\n");


	// Llenar e imprimir los datos del primer apuntador
	for(j=0;j<5;j++){
		printf("Alumno %d (din1)\n",j+1);
		*(din1+j) = asignarAlumno();
	}

	printf("ALUMNOS EN din1\n\n");

	for(j=0;j<5;j++){
		printf("Alumno %d (din1)\n",j+1);
		imprimirAlumno(*(din1+j));
	}



	printf("Segundo apuntador \n");
	for(j=0;j<5;j++){
		printf("Direccion[%d]=%d \n",j,din2+j);
	}
	printf("\n");

	// Llenar e imprimir los datos del segundo apuntador
	for(j=0;j<5;j++){
		printf("Alumno %d (din2)\n",j+1);
		*(din2+j) = asignarAlumno();
	}

	printf("ALUMNOS EN din2\n\n");

	for(j=0;j<5;j++){
		printf("Alumno %d (din2)\n",j+1);
		imprimirAlumno(*(din2+j));
	}



	printf("Con realloc: \n");
	din3 = realloc(din2,10);
	for(j=0;j<10;j++){
		printf("&din3[%d]=%d \n",j,din3+j);
	}
	printf("\n");

	// Llenar posiciones restantes en din3 e imprimir el contenido.
	for(j=5;j<10;j++){
		printf("Alumno %d (din3)\n",j+1);
		*(din3+j) = asignarAlumno();
	}

	printf("ALUMNOS EN din3\n\n");

	for(j=0;j<10;j++){
		printf("Alumno %d (din3)\n",j+1);
		imprimirAlumno(*(din3+j));
	}



	free(din1);
	// free(din2); La memoria ya se encuentra liberada
	free(din3);
	system("PAUSE");
}

Alumno asignarAlumno()
{
    char nombre[100], apellido[100];
    int noCuenta;
    float prom;

    printf("Nombre: ");
    scanf("%s", nombre);
    FLUSH;

    printf("Apellido: ");
    scanf("%s", apellido);
    FLUSH;

    printf("Numero de cuenta: ");
    scanf("%d", &noCuenta);
    FLUSH;

    printf("Promedio: ");
    scanf("%f", &prom);
    FLUSH;

    printf("\n");

    return crearAlumno(noCuenta, nombre, apellido, prom);
}



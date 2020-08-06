// Documento con funciones utilizadas para imprimir la informacion de las tiendas.

// Prototipos
void mostrarTiendasDep(Tienda tiendas[TAMTIENDAS], int numTiendas);
void mostrarSecciones(Seccion secciones[TAMSECCIONES], int numSecciones);
void mostrarProductos(Producto productos[TAMPRODUCTOS], int numProductos);
void mostrarGerente(Gerente gerente);

// Imprime la informacion de un arreglo de tiendas.
void mostrarTiendasDep(Tienda tiendas[TAMTIENDAS], int numTiendas)
{
    int i;
	for (i = 0; i < numTiendas; i++)
	{
        printf("\n\n**** TIENDA %s ****\n\n", tiendas[i].nombre);
        mostrarGerente(tiendas[i].gerente);
        printf("Codigo de la tienda: %d\n", tiendas[i].codigo);
        printf("\n*** SECCIONES ***\n");
        mostrarSecciones(tiendas[i].secciones, tiendas[i].numSecciones);
	}
}

// Funcion auxiliar que imprime la informacion de un gerente.
void mostrarGerente(Gerente gerente)
{
    printf("\nGERENTE\nNombre: %s %s\n", gerente.nombre, gerente.apellido);
    printf("Salario: %f\n", gerente.salario);
}

// Funcion auxiliar que imprime la informacion de un arreglo de secciones.
void mostrarSecciones(Seccion secciones[TAMSECCIONES], int numSecciones)
{
    int i;
    for (i = 0; i < numSecciones; i++)
	{
        printf("\n   SECCION %d   \n", i+1);
        printf("Encargado: %s %s (Rango %s)\n", secciones[i].encargado.nombre, secciones[i].encargado.apellido, secciones[i].encargado.rango);
        printf("Codigo: %d\n", secciones[i].codigo);
        printf("Categoria: %s\n", secciones[i].categoria);
        printf("\nPRODUCTOS DE LA SECCION");
        mostrarProductos(secciones[i].productos, secciones[i].numProductos);
	}
}

// Funcion auxiliar que imprime la informacion de un arreglo de productos.
void mostrarProductos(Producto productos[TAMPRODUCTOS], int numProductos)
{
    int i;
    for (i = 0; i < numProductos; i++)
	{
        printf("\n\nProducto %d\n", i+1);
        printf("Nombre: %s\n", productos[i].nombre);
        printf("Clave: %d\n", productos[i].clave);
        printf("Precio: %f\n\n", productos[i].precio);
	}
}

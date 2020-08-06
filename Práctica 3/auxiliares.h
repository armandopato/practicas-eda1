// Documento que contiene las funciones necesarias para inicializar la informacion de una tienda,
// incluyendo los datos que ésta implica.

// Prototipos
Gerente inicializarGerente();
Producto crearProducto();
Empleado inicializarEmpleado();
Seccion crearSeccionTienda();
Tienda crearTiendaDepartamental();


Gerente inicializarGerente()
{
	Gerente nuevoGerente;
	printf("NUEVO GERENTE\n\n");

	printf("Nombre: ");
	fgets(nuevoGerente.nombre, 100, stdin);
	// Eliminar el salto de linea almacenado por fgets (reemplazarlo por '\0')
	strtok(nuevoGerente.nombre, "\n");
	FLUSH;

	printf("Apellido: ");
	fgets(nuevoGerente.apellido, 100, stdin);
	strtok(nuevoGerente.apellido, "\n");
	FLUSH;

	printf("Salario: ");
	scanf("%f", &nuevoGerente.salario);
	FLUSH;

	printf("\n");
	return nuevoGerente;
}


Producto crearProducto()
{
	Producto nuevoProducto;
	printf("\nNUEVO PRODUCTO\n");

	printf("Clave: ");
	scanf("%d", &nuevoProducto.clave);
	FLUSH;

	printf("Nombre: ");
	fgets(nuevoProducto.nombre, 100, stdin);
	strtok(nuevoProducto.nombre, "\n");
	FLUSH;

	printf("Precio: ");
	scanf("%f", &nuevoProducto.precio);
	FLUSH;

	printf("\n");
	return nuevoProducto;
}

Empleado inicializarEmpleado()
{
	Empleado nuevoEmpleado;
	printf("NUEVO EMPLEADO\n\n");

	printf("Nombre: ");
	fgets(nuevoEmpleado.nombre, 100, stdin);
	strtok(nuevoEmpleado.nombre, "\n");
	FLUSH;

	printf("Apellido: ");
	fgets(nuevoEmpleado.apellido, 100, stdin);
	strtok(nuevoEmpleado.apellido, "\n");
	FLUSH;

	printf("Rango: ");
	fgets(nuevoEmpleado.rango, 100, stdin);
	strtok(nuevoEmpleado.rango, "\n");
	FLUSH;

	printf("\n");
	return nuevoEmpleado;
}

Seccion crearSeccionTienda()
{
	Seccion nuevaSeccion;
	printf("\nNUEVA SECCION\n\n");

	printf("** Encargado **\n");
	nuevaSeccion.encargado = inicializarEmpleado();

	printf("Codigo de la seccion: ");
	scanf("%d", &nuevaSeccion.codigo);
	FLUSH;

	printf("Categoria: ");
	fgets(nuevaSeccion.categoria, 100, stdin);
	strtok(nuevaSeccion.categoria, "\n");
	FLUSH;

	int numProductos = 0;

	printf("Cuantos productos desea ingresar? ");
	scanf("%d", &numProductos);
	FLUSH;

	while (numProductos < 1 || numProductos > TAMPRODUCTOS)
	{
		printf("Ingrese un numero dentro del rango (1-%d): ", TAMPRODUCTOS);
		scanf("%d", &numProductos);
		FLUSH;
	}

	nuevaSeccion.numProductos = numProductos;

	int i;
	for (i = 0; i < numProductos; i++)
	{
		nuevaSeccion.productos[i] = crearProducto();
	}

	printf("\n");
	return nuevaSeccion;
}

Tienda crearTiendaDepartamental()
{
	Tienda nuevaTienda;
	printf("\nNUEVA TIENDA\n\n");

	printf("** Gerente **\n");
	nuevaTienda.gerente = inicializarGerente();

	printf("Nombre de la tienda: ");
	fgets(nuevaTienda.nombre, 100, stdin);
	strtok(nuevaTienda.nombre, "\n");
	FLUSH;

	printf("Codigo: ");
	scanf("%d", &nuevaTienda.codigo);
	FLUSH;

	int numSecciones = 0;

	printf("Cuantas secciones desea ingresar? ");
	scanf("%d", &numSecciones);
	FLUSH;

	while (numSecciones < 1 || numSecciones > TAMSECCIONES)
	{
		printf("Ingrese un numero dentro del rango (1-%d): ", TAMSECCIONES);
		scanf("%d", &numSecciones);
		FLUSH;;
	}

	nuevaTienda.numSecciones = numSecciones;

	int i;
	for (i = 0; i < numSecciones; i++)
	{
		nuevaTienda.secciones[i] = crearSeccionTienda();
	}
	return nuevaTienda;
}

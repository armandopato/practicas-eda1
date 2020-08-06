// Documento con declaraciones de estructuras y macros.

// Macros utilizadas para evitar la repeticion.
#define FLUSH fflush(stdin)
#define TAMTIENDAS 10
#define TAMSECCIONES 5
#define TAMPRODUCTOS 10

// Estructuras
typedef struct gerente
{
	char nombre[100];
	char apellido[100];
	float salario;
} Gerente;


typedef struct producto
{
	int clave;
	char nombre[100];
	float precio;
} Producto;


typedef struct empleado
{
	char nombre[100];
	char apellido[100];
	char rango[100];
} Empleado;


typedef struct seccion
{
	Empleado encargado;
	int codigo;
	char categoria[100];
	Producto productos[TAMPRODUCTOS];
	int numProductos;
} Seccion;


typedef struct tienda
{
	Gerente gerente;
	char nombre[100];
	int codigo;
	Seccion secciones[TAMSECCIONES];
	int numSecciones;
} Tienda;



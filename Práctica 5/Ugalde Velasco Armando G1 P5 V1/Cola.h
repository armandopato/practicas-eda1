#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int primero;
    int ultimo;
    int lista[100];
}Cola;

typedef struct
{
    char titulo[100];
    char autor[100];
    int pags;
    int clave;
} Libro;

typedef struct{
    int primero;
    int ultimo;
    int tamano;
    Libro *lista;
} ColaLibros;

//declaración de funciones para trabajar con la estructura
Cola crearCola();
int isEmptyQueue(Cola);
void encolar(Cola*,int);
int desencolar(Cola*);
int first(Cola);

// Cola de libros
ColaLibros crearColaLibros(int tamano);
int isEmptyQueueLibros(ColaLibros);
void encolarLibro(ColaLibros*,Libro);
Libro desencolarLibro(ColaLibros*);
Libro firstLibro(ColaLibros);
void eliminarColaLibros(ColaLibros);

Cola crearCola(){
	Cola c;
	c.primero=0;
	c.ultimo=0;
	return c;
}
int isEmptyQueue(Cola c){
	if(c.primero==c.ultimo)
		return 1;
	return 0;
}
void encolar(Cola *c,int x){

    if (c->ultimo < 100)
    {
        c->lista[c->ultimo++] = x;
    }
    else
    {
        printf("Cola llena\n");
    }
}
int desencolar(Cola *c){
    if (!isEmptyQueue(*c))
    {
        int val = c->lista[c->primero];
        c->lista[c->primero++] = NULL;

        if (isEmptyQueue(*c))
        {
            *c = crearCola();
        }
        return val;
    }
    else
    {
        printf("Cola vacia\n");
    }
}
int first(Cola c){
    if (!isEmptyQueue(c))
    {
        return c.lista[c.primero];
    }
    else
    {
        printf("Cola vacia\n");
    }
}

// COLA LIBROS

ColaLibros crearColaLibros(int tamano)
{
    ColaLibros c;
	c.primero=0;
	c.ultimo=0;
	c.tamano = tamano;
	c.lista = malloc(sizeof(Libro) * tamano);
	return c;
}

int isEmptyQueueLibros(ColaLibros c)
{
    if(c.primero==c.ultimo)
		return 1;
	return 0;
}

void encolarLibro(ColaLibros *c, Libro x)
{
    if (c->ultimo < c->tamano)
    {
        c->lista[c->ultimo++] = x;
    }
    else
    {
        printf("Cola llena\n");
    }
}

Libro desencolarLibro(ColaLibros *c)
{
    if (!isEmptyQueueLibros(*c))
    {
        Libro val = c->lista[c->primero++];

        if (isEmptyQueueLibros(*c))
        {
            ColaLibros nueva = crearColaLibros(c->tamano);
            eliminarColaLibros(*c);
            *c = nueva;
        }
        return val;
    }
    else
    {
        printf("Cola vacia\n");
    }
}

Libro firstLibro(ColaLibros c)
{
    return c.lista[c.primero];
}


void eliminarColaLibros(ColaLibros c)
{
    free(c.lista);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tope;
    int lista[100];
}Pila;

//declaración de funciones para trabajar con la estructura
Pila crearPila();
int isEmpty(Pila);
void push(Pila*,int);
int pop(Pila*);
int top(Pila);


Pila crearPila(){
	Pila p;
	p.tope=0;
	return p;
}
int isEmpty(Pila p){
	if(p.tope==0)
		return 1;
	return 0;
}
void push(Pila *p,int x){
    int *tope = &p->tope;
    if (*tope < 100)
    {
        p->lista[(*tope)++] = x;
    }
    else
    {
        printf("Pila llena\n");
    }
}

int pop(Pila *p){
    if (!isEmpty(*p))
    {
        int tope = --p->tope;
        int val = p->lista[tope];
        p->lista[tope] = NULL;
        return val;
    }
    else
    {
        printf("Pila vacía\n");
        return NULL;
    }
}
int top(Pila p){
	if(isEmpty(p)==1){
		printf("La pila ya est%c vac%ca. \n",160,161);
		return -1;
	}
	else{
		return p.lista[p.tope-1];
	}
}


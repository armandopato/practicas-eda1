#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct
{
    char marca[100];
    char modelo[100];
    char color[100];
    char placas[100];
} Automovil;

typedef struct Nodo{
    Automovil *carro;
    struct Nodo* next;
}Nodo;

typedef struct{
	struct Nodo* head;
	int tamano;
}Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,Automovil*);
void addFinalLista(Lista*,Automovil*);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void recorrerLista(Lista*);
int buscarElemento(Lista*, char *marca);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano = 0;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	int tamano = lista.tamano;				//se define el tamaño
		printf("AUTOS:\n\n");
    	Nodo *current = lista.head;
    	int numAuto = 1;
   		while (tamano > 0 ) {					//tamaño como condicional
        	printf("AUTO %d\n", numAuto);
        	obtenerInfo(current->carro);
        	current = current->next;
            numAuto++;
        	tamano--;                           //se reduce tamaño
   	 	}
	}
}

void addFinalLista(Lista *lista, Automovil *carro) {
	int posicion=lista->tamano;
	if(lista->head==NULL){
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->carro = carro;
    	nodo->next = nodo;
    	lista->head = nodo;
	}
	else
	{
		Nodo *current = lista->head;
		while (posicion!=1) {
       		current = current->next;
       		posicion--;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	current->next = nuevoNodo;
		nuevoNodo->carro = carro;
    	nuevoNodo->next = lista->head;

	}
	lista->tamano++;
}
void addPrincipioLista(Lista *lista, Automovil *carro) {

	Nodo *node,*temp;
    node = (Nodo*)malloc(sizeof(Nodo));
    node->carro = carro;
    if(lista->head==NULL){
    	node->next=node;
	}
    else{
    	node->next = lista->head;
		temp = lista->head;
    	while(temp->next != lista->head){
    		temp=temp->next;
		}
		temp->next=node;
	}
	lista->head = node;
    lista->tamano++;
}
void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
        lista->tamano--;
    	Nodo *temp = lista->head;
    	Nodo *nuevo_head = (lista->tamano == 0) ? NULL : temp->next;
    	while(temp->next != lista->head){
    		temp=temp->next;
		}
		temp->next = nuevo_head;
		eliminarAutomovil((lista->head)->carro);
    	free(lista->head);
    	lista->head = nuevo_head;

	}
}

void borrarUltimo(Lista *lista) {
	if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
        if (lista->tamano == 1){
            borrarPrimero(lista);
            return;
        }
        lista->tamano--;
        Nodo *current = lista->head;
        Nodo *current2 = current->next;

        while (current2->next != lista->head) {
            current = current->next;
            current2 = current2->next;
        }
        current->next = lista->head;
        eliminarAutomovil(current2->carro);
        free(current2);
	}
}

int buscarElemento(Lista* lista, char *marca)
{
    if (!lista->head)
    {
        printf("No se encontro el elemento (lista vacia) \n");
        return -1;
    }

    Nodo *trav = lista->head;
    int pos = 0;
    int marcaNoEsIgual;

    while(1)
    {
        marcaNoEsIgual = strcmp((trav->carro)->marca, marca);

        if (!marcaNoEsIgual)
        {
            printf("\nElemento encontrado en la posicion %d (posicion con indices basados en cero)\n", pos);
            obtenerInfo(trav->carro);
            free(marca);
            return pos;
        }

        if (trav->next == lista->head) break;

        pos++;
        trav = trav->next;
    }

    free(marca);
    printf("No se encontro el elemento\n");
    return -1;
}


void recorrerLista(Lista *lista)
{
    if (!lista->head) {
        printf("No se puede recorrer la lista (vacia)\n");
        return;
    }

    Nodo *trav = lista->head;
    int flag = 1;
    while (flag)
    {
        flag = solicitarOpcion();
        while(flag == 1)
        {
            printf("\nINFORMACION DEL AUTO ACTUAL:\n");
            obtenerInfo(trav->carro);
            flag = solicitarOpcion();
        }

        if (flag == 2)
        {
            printf("\nAVANZANDO AL SIGUIENTE AUTO\n");
            trav = trav->next;
        }
    }
}

int solicitarOpcion()
{
    int opcion;
    printf("\nElija una opcion:\n1) Ver detalles del nodo actual\n2) Avanzar al siguiente elemento\n3) Salir\n");
    scanf("%d", &opcion);
    fflush(stdin);

    while (opcion < 1 || opcion > 3)
    {
        printf("Por favor, ingrese una opcion correcta: ");
        scanf("%d", &opcion);
        fflush(stdin);
    }

    if (opcion == 3) {
        return 0;
    }
    else
    {
        return opcion;
    }

}

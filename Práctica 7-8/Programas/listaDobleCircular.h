#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int val;
    struct Nodo* next;
    struct Nodo* prev;
}Nodo;

typedef struct{
	int tamano;
	struct Nodo* head;
}Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,int);
void addFinalLista(Lista*,int);
void primerNodo(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void recorrerLista(Lista);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano=0;
	return lista;
}

void recorrerLista(Lista lista){
	int var = 0;
	Nodo *temp = lista.head;

	if (lista.tamano == 0)
    {
        printf("No se puede recorrer la lista (vacia)\n");
        return;
    }

	do{
		printf("El elemento actual es %d \n",temp->val);
		printf("Mostrar anterior presione 0\n");
		printf("Mostrar Siguiente Presione 1 \n");
		printf("Salir Presione 2 \n");
		scanf("%d",&var);
		if (var == 0)
        {
            temp = temp->prev;
		}
		else if(var == 1)
        {
            temp = temp->next;
        }

	}while (var!=2);
}


void print_list(Lista lista) {
    int tamano = lista.tamano;
	if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano>0){
		   printf("%d\n",current->val) ;
		   current = current->next;
		   tamano--;
		}
	}
}


void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}
	else
	{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
		lista->head->prev=new_node;
		temp=lista->head;

		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;
	}
	lista->tamano++;
}
void addPrincipioLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}
	else{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
    	lista->head->prev=new_node;

		temp=lista->head;

		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;

		lista->head = new_node;
	}
	lista->tamano++;
}

void primerNodo(Lista *lista, int val){
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->val = val;
    nodo->next = nodo;
    nodo->prev = nodo;
    lista->head = nodo;
}

void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
        Nodo *temp = lista->head;

        if (lista->tamano == 1)
        {
            lista->tamano--;
            lista->head = NULL;
            free(temp);
            return;
        }


        Nodo *tail = temp->prev;
        Nodo *newHead = temp->next;

        tail->next = newHead;
        newHead->prev = tail;
        free(temp);
        lista->head = newHead;
        lista->tamano--;
	}
}

void borrarUltimo(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{

        if (lista->tamano == 1)
        {
            borrarPrimero(lista);
            return;
        }

        lista->tamano--;

        Nodo *head = lista->head;
        Nodo *tail = head->prev;
        Nodo *newTail = tail->prev;

        newTail->next = head;
        head->prev = newTail;
        free(tail);
	}

}






#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int val;
    struct Nodo* next;
}Nodo;

typedef struct{
	struct Nodo* head;
}Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,int);
void addFinalLista(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
int primerElemento(Lista);
int buscarElemento(Lista*, int);
void eliminarEnesimo(Lista*);
void eliminarMayores(Lista*);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (current != 0) {
        	printf("%d \n",current->val);
			current = current->next;
   	 	}
	}
}

void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){

		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->val = val;
    	nodo->next = NULL;
    	lista->head = nodo;
	}
	else
	{
		Nodo *current = lista->head;
		while (current->next != 0) {
       		current = current->next;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	nuevoNodo->val = val;
    	nuevoNodo->next = NULL;
 		current->next = nuevoNodo;
	}
}
void addPrincipioLista(Lista *lista, int val) {
	Nodo *new_node;
    new_node = (Nodo*)malloc(sizeof(Nodo));
    new_node->val = val;
    new_node->next = lista->head;
    lista->head = new_node;
}

void addIesimoLista(Lista *lista, int val){

    // Creacion del nodo a insertar
    Nodo *nuevoNodo;
	nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
   	nuevoNodo->val = val;

	int contador, posicion;
	printf("Ingrese la posicion: ");
	scanf("%d",&posicion);

	while (posicion < 0)
    {
        printf("Inserte una posicion valida: ");
        scanf("%d", &posicion);
    }

	// Corner case: lista vacia
    if (!lista->head) {
        printf("Se insertara al principio de la lista, ya que esta vacia.\n");
        lista->head = nuevoNodo;
        nuevoNodo->next = NULL;
        return;
    }

    Nodo *temp;   //creacion de nodo temporal para recorrer la lista
    temp=lista->head;

    // Corner case: insertar al principio (posicion 0)
    if (posicion == 0)
    {
        lista->head = nuevoNodo;
        nuevoNodo->next = temp;
        return;
    }

	for(contador=0;contador<posicion-1;contador++)   {
        // Corner case: la posicion solicitada se encuentra fuera del rango
        if(!temp->next)
        {
            printf("Se insertara al final de la lista.\n");
            temp->next = nuevoNodo;
            nuevoNodo->next = NULL;
            return;
        }
        temp=temp->next;

	}

	// Caso normal
   	nuevoNodo->next = temp->next;
	temp->next = nuevoNodo;
}

void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("No se puede eliminar (La lista esta vacia)");
    }
    else{
    	Nodo *nuevo_head = NULL;
    	Nodo *temp = lista->head;
    	nuevo_head=temp->next;
    	free(lista->head);
    	lista->head = nuevo_head;
	}
}

void borrarUltimo(Lista *lista) {
    Nodo *temp = lista->head;
	if (lista->head == NULL) {
        printf("No se puede eliminar (La lista esta vacia)");
    }
    else{
    	if(temp->next==NULL){
    		lista->head = NULL;
			free(lista->head);
    	}else{
    		Nodo *current = lista->head;
    		while (current->next->next != NULL) {
        		current = current->next;
    		}
    		current->next = NULL;
			free(current->next);

    	}
	}

}

int primerElemento(Lista lista){
	return lista.head->val;
}

int buscarElemento(Lista *lista, int elemento)
{
    if (!lista->head)
    {
        printf("No se encontro el elemento (lista vacia) \n");
        return -1;
    }

    Nodo *trav = lista->head;
    int pos = 0;

    while(trav)
    {
        if (trav->val == elemento)
        {
            printf("\nElemento encontrado en la posicion %d\n", pos);
            return pos;
        }
        pos++;
        trav = trav->next;
    }

    printf("No se encontro el elemento\n");
    return -1;
}


void eliminarEnesimo(Lista *lista)
{
    int i, posicion;
	printf("Ingrese la posicion: ");
	scanf("%d",&posicion);

	while (posicion < 0)
    {
        printf("Inserte una posicion valida: ");
        scanf("%d", &posicion);
    }

	// Corner case: lista vacia
    if (!lista->head) {
        printf("No se puede eliminar (lista vacia)\n");
        return;
    }

    Nodo *temp;   //creacion de nodo temporal para recorrer la lista
    temp=lista->head;

    // Corner case: eliminar al principio (posicion 0)
    if (posicion == 0)
    {
        borrarPrimero(lista);
        return;
    }

	for(i=0; i<posicion-1; i++)
    {
        // Corner case: la posicion solicitada se encuentra fuera del rango
        if(!temp->next)
        {
            printf("La posicion proporcionada supera el tamano de la lista. No es posible eliminar el elemento.\n");
            return;
        }
        temp=temp->next;
	}

   	Nodo* aEliminar = temp->next;
	temp->next = aEliminar->next;
	free(aEliminar);
}

void eliminarMayores(Lista *lista)
{
    // Solicitar limite
    int limite;
	printf("Eliminar numeros mayores a: ");
	scanf("%d", &limite);

    if (!lista->head)
    {
        printf("\n0 elementos eliminados (lista vacía)\n");
        return;
    }

    int eliminados = 0;
    Nodo *prev = NULL;
    Nodo *trav = lista->head;
    printf("\nValores eliminados: \n");

    while(trav)
    {
        // Eliminar nodo
        if (trav->val > limite)
        {
            printf("%d\n", trav->val);
            eliminados++;

            // Eliiminar head
            if (!prev)
            {
                prev = trav;
                trav = trav->next;
                lista->head = trav;
                free(prev);
                prev = NULL;
            }
            // Nodo a eliminar es diferente de head
            else
            {
                prev->next = trav->next;
                free(trav);
                trav = prev->next;
            }
        }
        // Avanzar un nodo
        else
        {
            prev = trav;
            trav = trav->next;
        }
    }

    printf("\n%d elemento(s) eliminados\n", eliminados);
}


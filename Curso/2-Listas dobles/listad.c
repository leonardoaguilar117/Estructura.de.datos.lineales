#include "listad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Alumno* crear_Alumno(int ID,char NAME[20], int EDAD){
    Alumno *aux=(Alumno*)malloc(sizeof(Alumno));
    aux->id=ID;
    strcpy(aux->name, NAME);
    aux->edad=EDAD;
    return(aux);
}

Nodo *crear_Nodo(Alumno *alumno){
    Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
    aux->datos=alumno;
    aux->sig=NULL;
    aux->ant=NULL;
    return(aux);
}

ListaD *crear_ListaD(){
    ListaD *aux=(ListaD*)malloc(sizeof(ListaD));
    aux->cabeza=NULL;
    aux->cola=NULL;
    return(aux);
}


int isEmpty(ListaD *lista){
    if(lista->cabeza==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insertar_cabeza(ListaD *lista, Nodo *aux){
    if(isEmpty(lista)==1){
        lista->cabeza=aux;
        lista->cola=aux;
    }
    else{
        lista->cabeza->ant=aux;
        aux->sig=lista->cabeza;
        lista->cabeza=aux;
    }
}


void insertar_cola(ListaD *lista, Nodo *aux){
    if(isEmpty(lista)==1){
        insertar_cabeza(lista,aux);
    }
    else{
        Nodo *cola;
        cola = lista->cabeza;
        while(cola->sig != NULL){
            cola=cola->sig;
        }
        cola->sig=aux;
        aux->ant=cola;
        lista->cola=aux;
        cola = NULL;
        free(cola);
    }
}

void printLista(ListaD *lista){
    Nodo *aux = lista->cabeza;
    Alumno *alu;
    if(isEmpty(lista)!=1) {
        while(aux!=NULL){
            alu = aux->datos;
            printf("Nombre %s\n", alu->name);
            printf("Edad: %d \n\n", alu->edad);
            aux=aux->sig;
        }
    }
    else{
        printf("\n LISTA SIN NADA \n");
    }
}

void insertar_enmedio(ListaD *lista,Nodo *ant, Nodo *nodo){
    if(ant==NULL){
        insertar_cola(lista,nodo);
    }
    if(ant==lista->cabeza){
        insertar_cabeza(lista,nodo);
    }
    else{
        Nodo *aux=lista->cabeza;
        while(aux->sig!=ant){
            aux=aux->sig;
        }
        aux->sig=nodo;
        nodo->sig=ant;
        ant->ant=nodo;
        nodo->ant=aux;
        
    }
}


void quitar_cabeza(ListaD *lista){
    Nodo *aux = NULL;
    if(isEmpty(lista)!=1){
           if (lista->cabeza->sig==NULL){
           aux=lista->cabeza;
            lista->cabeza=NULL;
        }
        else{
            aux=lista->cabeza;
            //aux->sig=NULL;  Importa el orden esta va despues de mover la cabeza
            lista->cabeza=lista->cabeza->sig; // cambiar la cabeza
            aux->sig=NULL;// despegar flechita de aux ->
            lista->cabeza->ant=NULL;  // quitar el flechita <-
        }
    }
    else{
        printf("\n La lista esta vacia  estoy dentro del procedimiento quitar cabeza  \n");
    }
    free(aux);
}
void quitar_cola(ListaD *lista){
    Nodo *cola;
    Nodo * anterior;
    if(isEmpty(lista)==1){
        printf("\n La pila esta vacia estoy dentro del procedimiento quitar cola \n");    
    }
    else
    {
        if(lista->cabeza == lista->cola)
        {   
            quitar_cabeza(lista);
        }
        else
        {
            Nodo *aux;
            aux=lista->cola;
            lista->cola=lista->cola->ant;
            aux->ant=NULL;
            lista->cola->sig=NULL;
            free(aux);


        }
    }
}

void quitar_enmedio(ListaD *lista, Nodo *elemento){
    Nodo *anterior;
    Nodo *borrar;
    if(isEmpty(lista)==1){
        printf("\n La pila esta vacia estoy dentro del procedimiento quitar enmedio \n");    
    }
    else{
        borrar=buscaElemento(lista,elemento);//pendiente
        if(borrar==NULL){
            printf("\n No se encuentra ese elemento\n");  
        }
        else{
            if(lista->cabeza == borrar){
                quitar_cabeza(lista);
            }
            if(borrar->sig==NULL){
                quitar_cola(lista);
            }
            else{
                anterior=lista->cabeza;
                while(anterior->sig != borrar){
                    anterior=anterior->sig;
                }
                anterior->sig=borrar->sig;
                borrar->sig->ant=anterior;
                borrar->ant=NULL;  
                borrar->sig=NULL;  
                borrar = NULL;
                free(borrar);
            }
        }
    }
}

Nodo *buscaElemento(ListaD *lista, Nodo *nodo){
    Nodo *aux;
    aux=lista->cabeza;
    if(isEmpty(lista)==0){  // Verificando si la lista esta vacia
        while(aux!=nodo){ // Si son diferentes los elementos; el inicial y el que me pide
            if(aux->sig==NULL){ /// Si el siguiente apunta a NULLO significa que es la cola
                //printf ("El elemento con ID %d, no se encuentra",nodo->datos->cont); // Por lo que no se encontro
                aux=NULL;
                free(aux);
                return aux;
                }
            else{
                aux=aux->sig; // Pasar al siguiente elemento de la lista
            }  
        }
        if(aux==nodo){ // Si sale del while significa que ya son iguales 
           // printf ("El elemento con ID %d, si esta en la lista",nodo->datos->cont); // Por lo que se encuentra el elemento
            return aux; // retorna el elemento que se encontro
        }
    }
    else{
        //printf("La lista se encuentra vacía no se puede imprimir nada \n\n"); //Esta vacia la pila ya que no entró al if
        return NULL;
    }
}    


void vaciarLista(ListaD *lista){
    Nodo *aux = lista->cabeza;
    if(isEmpty(lista)!=1){
        while(aux != NULL){
            aux=aux->sig;
            quitar_cabeza(lista);
        }
    }
    else{
        printf("\n LISTA SIN NADA PROCEDIMIENTO VACIAR LISTA \n");
    }
    free(aux);
}

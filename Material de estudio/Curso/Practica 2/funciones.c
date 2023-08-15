#include "estructuras.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Alumno *crear_Alumno(int matricula,char name[30], int edad){
    Alumno *alu = (Alumno*)malloc(sizeof(Alumno));
    alu->matricula = matricula;
    strcpy(alu->name,name);
    alu->edad = edad;
    return(alu);
}

Nodo *crear_Nodo(Alumno *alumno){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->datos = alumno;
    aux->sig =NULL;
    aux->ant=NULL;
}

ListaD *crear_ListaD(){
    ListaD *aux = (ListaD*)malloc(sizeof(ListaD));
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

void printLista(ListaD *lista){
    Nodo *aux = lista->cola;
    Alumno *alu;
    if(isEmpty(lista)!=1) {
        while(aux!=NULL){
            alu = aux->datos;
            printf("Nombre %s\n", alu->name);
            printf("Edad: %d \n", alu->edad);
            printf("Matricula: %u \n\n\n", alu->matricula);
            aux=aux->ant;
        }
    }
    else{
        printf("\n LISTA SIN NADA \n");
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


Nodo *buscaElementoA(ListaD *lista, int matricula){
    Nodo *NodoAux = lista->cabeza;
    if(isEmpty(lista)==0){
        while(NodoAux->datos -> matricula != matricula){
            if(NodoAux->sig!=NULL){
                NodoAux = NodoAux -> sig;
            }else{
                NodoAux = NULL;
                return(NodoAux);
                break;
            }
        }
        if(NodoAux ->datos->matricula == matricula){
            return(NodoAux);
        }
    }
    return(NodoAux);
}



void quitar_cabeza(ListaD *lista){
    Nodo *NodoAux;
    if(isEmpty(lista)==0){
        NodoAux = lista->cabeza;
        lista -> cabeza = lista->cabeza->sig;
        NodoAux = NULL;
        free(NodoAux);
    }else{
        printf("La lista esta vacia, estoy dentro del procedimiento quitar cabeza");
    }
}

void quitar_enmedio(ListaD *lista, int matricula){
    Nodo *anterior;
    Nodo *borrar;

    if(isEmpty(lista)==1){
        printf("La pila esta vacia, estoy dentro del procedimiento quitar en medio\n");
    }else{
        borrar = buscaElementoA(lista, matricula);

        if(borrar==NULL){
            printf("No hay nada que borrar");
        }else{

            if(lista->cabeza==borrar){
                quitar_cabeza(lista);
            }else{
                anterior = lista -> cabeza;
                while(anterior->sig=borrar){
                    anterior =anterior->sig;
                }
                anterior->sig = borrar->sig;
                borrar = NULL;
                anterior = NULL;
                free(borrar);
                free(anterior);
            }

        }
    }
}





















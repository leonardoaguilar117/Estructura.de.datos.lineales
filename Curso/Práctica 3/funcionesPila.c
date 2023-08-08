/*LEONARDO AGUILAR MARTINEZ 2203025005*/
#include <stdio.h>
#include <stdlib.h>
#include "estructurasPila.h"
/*Funciones para crear un numero, nodo e inicializar una pila */
Numero *crearNumero(int numero){
    Numero *num = (Numero*)malloc(sizeof(Numero));
    num-> numero = numero;
    return(num);
}

Nodo *crear_Nodo(Numero *numero){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->atributos = numero;
    aux->Siguiente = NULL;
}

PilaCompleta *crear_Pila(){
    PilaCompleta *aux = (PilaCompleta*)malloc(sizeof(PilaCompleta));
    aux->cabeza=NULL;
    return(aux);
}

int estaVacia(PilaCompleta pila){
    if(pila.cabeza == NULL){
        return(0);
    }else{
        return(1);
    }
}
/*Las pilas solo tienen dos operaciones para modificar los nodos:
    push(insertar a la pila)
    pop(eliminar de la pila)

    Podemos ver la pila como un apilamiento de platos de cocina
    el primero en entrar es el ultimo en salir
*/
void push(PilaCompleta *pila, Nodo *Nodo){
    if(estaVacia(*pila)==1){
        Nodo -> Siguiente = pila -> cabeza;
        pila -> cabeza = Nodo;
    }else{
        pila->cabeza = Nodo;
    }
}

/*La funcion pop retorna el nodo que se quitó de la pila, esto con el fin de 
    insertar después este nodo en otra pila.
    */
Nodo *pop(PilaCompleta *pila){
    Nodo *NodoAux;
    if(estaVacia(*pila)==1){
        NodoAux = pila->cabeza;
        pila -> cabeza = pila->cabeza->Siguiente;
    }else{
        printf("La lista esta vacia, estoy dentro del procedimiento quitar cabeza\n");
    }
    return(NodoAux);
}


void printPila(PilaCompleta *pila){
    Nodo *NodoAux = pila->cabeza;
    Numero *numAux;
    if(estaVacia(*pila)==1) {
        while(NodoAux!=NULL){
            numAux = NodoAux-> atributos;
            printf(" Numero: %d\n", numAux -> numero);
            NodoAux = NodoAux-> Siguiente;
        }
    }
    else{
        printf("\n LISTA SIN NADA \n");
    }
    numAux = NULL;
    NodoAux = NULL;
    free(NodoAux);
    free(numAux);
}

void vaciarPila(PilaCompleta *pila){
    Nodo *NodoAux = pila->cabeza;
    if(estaVacia(*pila)==1){
        while(NodoAux != NULL){
            NodoAux = NodoAux ->Siguiente;
            pop(pila);
        }
    }else{
        printf("Lista sin nada\n");
    }
    NodoAux = NULL;
    free(NodoAux);
}


Nodo *buscaElemento(PilaCompleta *pila, int num){
    Nodo *NodoAux = pila->cabeza;
    if(estaVacia(*pila)==1){
        while(NodoAux->atributos -> numero != num){
            if(NodoAux->Siguiente !=NULL){
                NodoAux = NodoAux -> Siguiente;
            }else{
                printf("El elemento con duracion: %d no se encontro\n",num);
                NodoAux = NULL;
                return(NodoAux);
                break;
            }
        }
        if(NodoAux ->atributos -> numero == num){
            printf("El elemento con duracion %d si esta en la lista\n",num);
            return(NodoAux);
        }
    }else{
        printf("La lista no tiene elementos\n");
        return(NULL);
    }
    
    return(NodoAux);

}

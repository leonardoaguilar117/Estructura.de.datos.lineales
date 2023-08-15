#include <stdlib.h>
#include <stdio.h>
#include "estructuras.h"

Numero *crear_Numero(int numero){
    Numero *numeroNuevo = (Numero*)malloc(sizeof(Numero));
    numeroNuevo -> numero = numero;
    return (numeroNuevo);
}

Nodo *crearNodo(Numero *nuevoNumero){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo -> atributos = nuevoNumero;
    nodo -> Siguiente = NULL;
    return (nodo);
}

ColaCompleta *crearCola(){
    ColaCompleta *cola = (ColaCompleta*)malloc(sizeof(ColaCompleta));
    cola-> cabeza = NULL;
    return (cola);
}

int estaVacia(ColaCompleta *cola){
    if(cola->cabeza == NULL){
        return(0);
    }else{
        return(1);
    }
}

void insertar_cabeza(ColaCompleta *lista, Nodo *Nodo){
    if(estaVacia(lista)==0){
        Nodo -> Siguiente = lista -> cabeza;
        lista -> cabeza = Nodo;
    }else{
        lista->cabeza = Nodo;
    }
}

void encolar(ColaCompleta *cola1, Nodo *NodoAux){
    Nodo *cola;
    cola = cola1 -> cabeza;
    if(estaVacia(cola1)==0){
        insertar_cabeza(cola1, NodoAux);
    }else{
        while(cola -> Siguiente != NULL){
            cola = cola -> Siguiente;
        }
        cola -> Siguiente = NodoAux;
        cola = NodoAux;
        cola = NULL;
        free(cola);
    }
}

void printCola(ColaCompleta *cola){
    Nodo *NodoAux = cola->cabeza;
    Numero *numAux;
    int x =5;
    if(estaVacia(cola)==1) {
        while(NodoAux!=NULL){
            numAux = NodoAux-> atributos;
            printf("Numero: %u \n", numAux->numero);
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


void desencolar(ColaCompleta *cola1){
    Nodo *cola;
    Nodo *anterior;
    if(estaVacia(cola1)==0){ //Sí está vacía 
        printf("La cola esta vacia \n");
    }else{

        if(cola1 ->cabeza ->Siguiente == NULL){ //Unico elemento 
            cola1 -> cabeza = NULL;
            printf("Memoria liberada\n");
        }else{  
            cola = cola1-> cabeza;
            while(cola -> Siguiente != NULL){
                anterior = cola;
                cola = cola->Siguiente;
            }
            anterior ->Siguiente=NULL;
            cola=NULL;
            anterior=NULL;
            free(cola);
            free(anterior);
        }
    }
}


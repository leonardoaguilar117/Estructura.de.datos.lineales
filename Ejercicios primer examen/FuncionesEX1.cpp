/*  Funciones examen 1 
    Autor: Leonardo Aguilar Martínez
*/

#include <iostream>
#include "listaEnlazadaSimple.h"
using namespace std;
void eliminarDuplicados(ListaEnlazadaSimple *lista);
void enviarDatos(ListaEnlazadaSimple *Lista_I, ListaEnlazadaSimple *Lista_J );


//Sirve para inciso 3 y 4   
void eliminarDuplicados(ListaEnlazadaSimple *lista){
    Nodo* aux = lista->cabeza;
    Nodo* valor = lista->cabeza;

    while(aux!=nullptr){
        while(valor!= nullptr){
            if(aux->elemento = valor->elemento){
               lista->eliminar(valor); 
            }
        valor=valor->sig;
        }
        aux=aux->sig;
    }
}

void enviarDatos(ListaEnlazadaSimple *Lista_I, ListaEnlazadaSimple *Lista_J ){
    Nodo *inicio = Lista_J->cabeza;
    while(inicio != nullptr){
        Lista_I->inserta_final(inicio->elemento);
        Lista_J->eliminar(inicio);
    }
    return Lista_I;
}



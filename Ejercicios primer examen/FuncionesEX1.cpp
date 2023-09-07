/* Funciones examen 1 
    Autor: Leonardo Aguilar Martínez
*/
#include <iostream>
#include "listaEnlazadaSimple.h"
using namespace std;

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



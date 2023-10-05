#include <iostream>
#include <string>
using namespace std;
#include "ClaseListaArreglo.h"

int main(){
    //Prueba de todos lo métodos definidos en Clase Lista:

    ListaArreglos listaPrueba;

    //Insertar 0 a 14 e impresión
    for(int i=0; i<15; i++){
        listaPrueba.insertar(i,i);
    }
    cout<<"Lista: "<<listaPrueba.toString()<<endl;
    
    //Eliminar indice 5
    listaPrueba.eliminar(5);
    cout<<"Lista modificada: "<<listaPrueba.toString()<<endl;

    //Busqueda de 4
    cout<<listaPrueba.buscar(4);

}
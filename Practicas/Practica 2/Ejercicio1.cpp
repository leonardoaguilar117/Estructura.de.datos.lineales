#include <iostream>
#include <string>
using namespace std;
#include "ClaseLista.h"

int main(){
    ListaArreglos lista1, lista2, listaAUX;    
    int j = 3;

    //Llenado primera lista con i y j 
    for(int i=0; i<10;i++){        
        lista1.insertar(i, i);
        lista2.insertar(j, i);
        j++;
    }
    cout<<"Lista 1: "<<lista1.toString()<<endl;
    cout<<"Lista 2: "<<lista2.toString()<<endl;
    
    for(int i=0; i<10; i++){
        int numBusqueda = lista1.arreglo[i];
        int buscado = lista2.buscar(numBusqueda);

        if(buscado>=0){
            listaAUX.insertar(lista1.arreglo[i], buscado);
        } 
    }

    cout<<"Interseccion: "<<listaAUX.toString();
    
}
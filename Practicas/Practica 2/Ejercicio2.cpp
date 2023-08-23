#include<iostream>
#include <string>
using namespace std;
#include "ClaseLista.h"

int main(){ 

    ListaArreglos lista1, lista2, listaAUX;
    int j=0;

    //Llenado de listas descendente
    for(int i=0;i<10;i++){
        lista1.insertar(i,i);
        lista2.insertar(j,i);
        j+=2;
    }

    //Impresión de listas
    cout<<"Lista 1: "<<lista1.toString()<<endl;
    cout<<"Lista 2: "<<lista2.toString()<<endl;

    //Llenado de listaAUX para unión
    for(int i=0;i<10;i++){
        if(listaAUX.buscar(lista1.arreglo[i]) < 0){
            listaAUX.insertar(lista1.arreglo[i],i);
        }if(listaAUX.buscar(lista2.arreglo[i]) < 0){
            listaAUX.insertar(lista2.arreglo[i],i+1);
        }
    }

    cout<<"Lista union: "<<listaAUX.toString();


    return 0;
}
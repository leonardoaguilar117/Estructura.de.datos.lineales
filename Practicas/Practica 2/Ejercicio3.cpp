#include <iostream>
#include "ClaseLista.h"
using namespace std;

int main(){
    ListaArreglos lista1, lista2, listaConc;
    listaConc.arreglo[30];
    int k=2;
    
    //Llenado de listas
    for(int i=0; i<10; i++){
        lista1.insertar(i,i);
        lista2.insertar(k,i);
        k+=3;
    }

    //Concatenación de lista 1
    for(int i = 0; i<10; i++){
         listaConc.insertar(lista1.arreglo[i],i);
    }
    //Concatenación de lista 2
    for (int i = 10; i < 17; i++) {
        listaConc.insertar(lista2.arreglo[i - 10], i);
    }

    //Impresión 
    cout<<"Lista concatenada: "<<listaConc.toString();



    return 0;
}

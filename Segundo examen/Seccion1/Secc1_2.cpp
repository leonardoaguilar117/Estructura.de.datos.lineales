#include <iostream>
#include "Secc1_2_PILA.h"
#include "Secc1_2_COLA.h"

using namespace std;

int main(){

    PilaA<int> Pila;
    Pila.CreatePilaA();

    //Insertar elementos a una pila
    for(int i = 0; i < 15; i++ ){
        Pila.push(i);
    }

    //Mostrar elementos originales
    cout<<"Pila: "<<Pila.toString()<<endl;

    //Mostrar elementos invertidos
    Pila.invierte();
    cout<<"Pila intercambiada: "<<Pila.toString()<<endl;




    //Instancia cola
    ColaArreglo<int> Cola;
    
    //Llenado de la cola
    for(int i=0; i<15; i++){
        Cola.enqueue(i);
    }

    //Cola armada
    cout<<Cola.toString();

    //Cola invertida
    Cola.invierte();
    cout<<Cola.toString();
    
    return 0;
}



















































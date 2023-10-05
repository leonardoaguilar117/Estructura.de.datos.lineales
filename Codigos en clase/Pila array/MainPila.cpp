#include "pilaArray.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    //Inicializar pila
    PilaA<int> Pila;
    Pila.CreatePilaA();

    //Insertar elementos
    for(int i = 0; i < 15; i++ ){
        Pila.push(i);
    }

    //Mostrar elementos
    cout<<"Pila: "<<Pila.toString()<<endl;

    //"Eliminar" un elemento y muestra la lista
    Pila.pop();
    cout<<"Pila con pop de 1 elemento: "<<Pila.toString()<<endl;

    //Obtener tope
    cout<<"El tope es: "<<Pila.Obtenertope()<<endl;

    //Pregunta si es vacía
    (Pila.esVacia() == true) ? cout << "Es vacía": cout<< "No esta vacia"<<endl;

    //Hace "vacia" la pila
    Pila.hacerVacia();
    (Pila.esVacia() == true) ? cout << "Es vacia": cout<< "No esta vacia"<< endl;

    

    return 0;
}
#include <iostream>
#include "Nodo.h"
using namespace std;
int posibleLlegada(Nodo *A, Nodo *B);

int main(){

    Nodo *A = new Nodo(5);
    Nodo *B = new Nodo(4);
    Nodo *C = new Nodo(3);
    Nodo *D = new Nodo(2);
    Nodo *E = new Nodo(1);
    Nodo *F = new Nodo(0);

    //Conexión de nodos 
    A ->sig = B;
    B ->sig = C;
    C ->sig = D;
    D ->sig = E;
    E ->sig = nullptr;
    
    cout<<posibleLlegada(A, F);
    return 0;
}

int posibleLlegada(Nodo *A, Nodo *B){
    Nodo* aux = A;
    int valueB = B->elemento;
    int flag;

    while(aux != nullptr){
        if(valueB == aux->elemento){
            flag = 1;
            break;
        }
        aux = aux ->sig;
    }
    return (flag == 1) ? 1 : 0;
}




















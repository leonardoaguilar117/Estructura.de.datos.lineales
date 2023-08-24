
#include <iostream>
#include "Nodo.h"
using namespace std;

int main(){
    Nodo variable;
    Nodo* apuntador;
    Nodo* nodo;
    Nodo *nodo3;
    apuntador= new Nodo(2);
    nodo= new Nodo();
    nodo3 = new Nodo(6,apuntador);
}
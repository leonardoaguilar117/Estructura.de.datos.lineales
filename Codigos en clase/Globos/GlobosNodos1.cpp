#include <iostream>
#include "Nodo.h"
using namespace std;
int main(){

    //Creando globos
    Nodo *inicial = new Nodo(5);
    Nodo *seg = new Nodo(1);
    Nodo *ter = new Nodo(4);
    Nodo *cua = new Nodo(7);
    Nodo *qui = new Nodo(8);

    //Conexión de globos
    inicial -> sig = seg;
    seg -> sig = ter;
    ter -> sig = cua;
    cua -> sig = qui;
    qui -> sig = nullptr;

    Nodo* ptr = inicial;
    while(ptr != nullptr){
        cout<<"Globo visitado: "<< ptr -> elemento<<endl;
        ptr = ptr -> sig;
    }

    delete inicial;
    delete seg;
    delete ter;
    delete cua;
    delete qui;

    return 0;
}
#include <iostream>
using namespace std;
#include "ClaseLista.h"

ListaArreglos mezclarListas(const ListaArreglos &L1, const ListaArreglos &L2);

int main(){
    
     ListaArreglos L1, L2;
    
    // Llenar las listas L1 y L2 con valores ordenados
   
    int j = 4;
    for(int i=0;i<10;i++){
        L1.insertar(i,i);
        L2.insertar(j,i);
        j+=2;
    }

    // Llamar a la función para mezclar las listas L1 y L2
    ListaArreglos L3 = mezclarListas(L1, L2);

    // Mostrar la lista resultante L3
    cout << "Lista L1: " << L1.toString() << endl;
    cout << "Lista L2: " << L2.toString() << endl;
    cout << "Lista mezclada L3: " << L3.toString() << endl;

    return 0;
}

ListaArreglos mezclarListas(const ListaArreglos &L1, const ListaArreglos &L2) {
    ListaArreglos L3;
    int i = L1.primera();
    int j = L2.primera();

    while (i != -1 && j != -1) {
        if (L1.obtener(i) < L2.obtener(j)) {
            L3.insertar(L1.obtener(i), L3.fin());
            i = L1.siguiente(i);
        } else if (L1.obtener(i) > L2.obtener(j)) {
            L3.insertar(L2.obtener(j), L3.fin());
            j = L2.siguiente(j);
        } else {
            L3.insertar(L1.obtener(i), L3.fin());
            i = L1.siguiente(i);
            j = L2.siguiente(j);
        }
    }

    while (i != -1) {
        L3.insertar(L1.obtener(i), L3.fin());
        i = L1.siguiente(i);
    }

    while (j != -1) {
        L3.insertar(L2.obtener(j), L3.fin());
        j = L2.siguiente(j);
    }

    return L3;
}
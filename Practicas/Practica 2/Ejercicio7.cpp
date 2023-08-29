#include <iostream>
#include "ClaseLista.h"
using namespace std;



int main(){
    
    ListaArreglos lista;

    int n, num, rep = 0;

    cout << "Ingresa el tamaño de la lista: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> num;
        lista.insertar(num, lista.fin());
    }

    int a;
    cout << "Ingresa el valor repetido para eliminarlo: ";
    cin >> a;

    int pos = lista.buscar(a);

    if (pos == -1){
        cout<<"No se encontro el valor en la lista."<<endl;
    }else{

    while (pos != -1) {
        lista.eliminar(pos);
        pos = lista.buscar(a);
    }
    
    cout << "Eliminación satisfactoria. Lista resultante: " << lista.toString() << endl;
    }
    
    return 0;
}
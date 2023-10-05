#include <iostream>
using namespace std;
#include "ListaEnlazadaSimple.h"


int main(){
    ListaEnlazadaSimple l1;
    for(int i=0; i<10; i++){
        l1.insertar(i,l1.fin());
    }
        cout<<l1.toString()<<endl; 
        l1.invierte();
     
        cout<<l1.toString()<<endl;
        cout<<endl;
   
}
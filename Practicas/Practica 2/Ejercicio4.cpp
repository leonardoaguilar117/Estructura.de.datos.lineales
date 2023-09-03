#include <iostream>
#include "ClaseLista.h"
using namespace std;

int main(){

    ListaArreglos lista1, SubLista;
    int i,j,dif;
    
    //Llenado de listas
    for(int i=0; i<10; i++){
        lista1.insertar(i,i);
    }

    cout<<"Digite el subindice de inicio y el de final para crear la sublista: ";
    cin>>i;
    cin>>j;

    /*Se evalua que i sea menor que j, si se cumple, se inserta a la sublista el valor de la lista1 en
      el indice i, el cual, por cada iteración cambiará, siempre y cuando i no sea mayor a j, de lo contrario,
      el llenado termina*/
    if(i<j){
        for(int k=0; k<10; k++){
            SubLista.insertar(lista1.obtener(i),k);
            i++;
            if(i > j){
                break;
            }
        }
    }else{
        cout<<"Digita un valor adecuado.";
    }
    cout<<SubLista.toString();
    return 0;
}
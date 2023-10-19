#include<iostream>
#include <string>
using namespace std; 

#define MAX 100

template < typename T>
class PilaA{

    public:
        T *arreglo;
        int tope;
    
    public:
        CreatePilaA();
        bool push(T x);
        bool pop();
        int Obtenertope();
        void hacerVacia();
        bool esVacia();
        string toString();
        void invierte();
    
};

//Constructor
template < typename T>
PilaA<T>::CreatePilaA(){
    arreglo = new T[MAX];
    tope = -1;
}

//Push
template < typename T>
bool PilaA<T>::push(T valor){
    if(tope < (MAX-1)){
       arreglo[tope] = valor;
       tope++;
       return true;
    }
    else{
        return false;
    }
}

//
template <typename T>
bool PilaA<T>::pop(){
    if(tope != -1){
        tope--;
        return true;
    }else{
        return false;
    }
}

template <typename T>
int PilaA<T>::Obtenertope(){
    return arreglo[tope];
}

template <typename T>
bool PilaA<T>::esVacia(){
    return(tope == -1);
}

template <typename T>
void PilaA<T>::hacerVacia(){
    tope = -1; 
}

template <typename T>
string PilaA<T>::toString(){
    string pila="";
    for(int i = 0 ; i < tope ; i++){
        pila+=to_string(arreglo[i])+ " ";
    }
    return pila;
}

//-------------- EJERCICIO DE INVERSION---------------//
template <typename T>
void PilaA<T>::invierte(){
    int aux, j = 0;
    int array[MAX];
    
    for(int i=tope-1; i>=0 ; i--){
        array[j] = arreglo[i];
        j++;
    }
    for(int i=0; i<tope; i++){
        arreglo[i] = array[i];    
    }
}




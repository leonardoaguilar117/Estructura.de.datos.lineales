#include "NodoDobEnlaz.h"
#include <string>
template <typename T>
class ListaDE    {
    public:
        Nodo<T> *cabeza;
        Nodo<T> *cola;
        int num_elemento;
        
    public:
       ListaDE(); //Constructor
        ~ListaDE(); //Destructor
        bool insertar (T x, Nodo<T> *p);
        bool eliminar(Nodo<T> *p);
        Nodo<T>* buscar (T x) const;
        Nodo<T>* fin() const;
        Nodo<T>* primera () const;
        Nodo<T>* siguiente(Nodo<T> *pos) const;
        Nodo<T>* anterior(Nodo<T> *pos) const;
        void hacerVacia();
        bool esVacia() const;
        string toString() const;
        T obtener(Nodo<T> *p) const;
        int getNumElementos() const;
        void invierte();
    
};

template <typename T>
void ListaDE<T>::invierte(){

}

template <typename T>
ListaDE<T>::ListaDE(){ //Constructor
}

template <typename T>
int ListaDE<T>::getNumElementos() const{
    return num_elemento;
}

//DUDA
template <typename T>
Nodo<T>* ListaDE<T>::siguiente(Nodo<T> *pos) const{
    if(pos != NULL && pos!=cola){
        return pos->getSiguiente();
    }else{
        return NULL;
    }
}

template <typename T>
Nodo<T>* ListaDE<T>::fin() const{
    return NULL;
}

template <typename T>
Nodo<T>* ListaDE<T>::primera() const {    
    return cabeza;
}

template <typename T>
bool ListaDE<T>::esVacia() const {
    return(num_elemento==0);    
}

template <typename T>
T ListaDE<T>::obtener(Nodo<T> *p) const{
    return p->getElemento();
    //return (*p).getElemento();    
}

template <typename T>
Nodo<T> *ListaDE<T>::buscar(T x) const {
    return NULL;
}



template <typename T>
Nodo<T> * ListaDE<T>::anterior(Nodo<T> *pos) const{
    Nodo<T> *aux = cabeza;
    bool encontrado = false;

    while(aux!=nullptr && !encontrado && pos!=cabeza){
        if(aux->getSiguiente() == pos){
            encontrado = true;
        }else
    }
}

template <typename T>
bool ListaDE<T>::insertar(T x, Nodo<T> *p){
     p->siguiente = p->getSiguiente()          
}


template <typename T>
bool ListaDE<T>::eliminar(Nodo<T> *p){
	bool res=false;
	return res;
}

template <typename T>
string ListaDE<T>::toString() const {
    string elem="";
    return elem;
}

template <typename T>
void ListaDE<T>::hacerVacia(){
}

template <typename T>
ListaDE<T>::~ListaDE(){

} 

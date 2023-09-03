#include "Nodo.h"

class ListaEnlazadaSimple{
    private:
        Nodo *cabeza;
        Nodo *cola;
        int num_elemento;
    public:
       ListaEnlazadaSimple(); //Constructor
        ~ListaEnlazadaSimple(); //Destructor
        bool insertar (int x, Nodo *p);
        bool eliminar(Nodo *p);
        Nodo* buscar (int x) const;
        Nodo* fin() const;
        Nodo* primera () const;
        Nodo* siguiente(Nodo *pos) const;
        Nodo* anterior(Nodo *pos) const;
        void hacerVacia();
        bool esVacia() const;
        string toString() const;
        int obtener(Nodo *p) const;
        int getNumElementos() const;
};


ListaEnlazadaSimple::ListaEnlazadaSimple(){
    cabeza=nullptr;
    cola=nullptr;
    num_elemento=0;
}

ListaEnlazadaSimple::getNumElementos() const{
    return num_elemento;
}

Nodo* ListaEnlazadaSimple::siguiente(Nodo *pos) const{
    if(pos!=nullptr){
        return pos->getSig(); //Mas pro
        //(*pos).getSig(); es equivalente
    }
    else{
        return nullptr;
    }
}

Nodo* ListaEnlazadaSimple::fin() const{
    return cola;   
}

Nodo* ListaEnlazadaSimple::primera() const {
    return cabeza;
}

bool ListaEnlazadaSimple::esVacia() const {
    return(num_elemento==0);
}

int ListaEnlazadaSimple::obtener(Nodo *p) const{
    return p->getElemento();
    //return (*p).getElemento();
}

Nodo *ListaEnlazadaSimple::buscar(int x) const {
    Nodo *pos=cabeza;
    bool encontrado=false,
    
    while(pos!=nullptr && encontrado!=true){
        if(pos->getElemento()==x){
            encontrado=true;
    
        }
            pos=pos->getSig();        
        
    }
        if (encontrado) {
            return pos;  // Devolver el puntero al nodo donde se encontró el elemento
        } else {
            return nullptr;  // Devolver nullptr si el elemento no se encontró
        }
}
 
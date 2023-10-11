#include "Nodo.h"
#include<iostream>
using namespace std; 

class ListaEnlazadaSimple{
    private:
        Nodo *cabeza;
        Nodo *cola;
        int num_elemento;
        void inserta_vacio(int x);
        void inserta_final(int x);
        void inserta_inicio(int x);
        void inserta_enmedio(int x,Nodo *p);

    public:
        ListaEnlazadaSimple(); 
        ~ListaEnlazadaSimple(); 
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
        void invierte();
    
};


void ListaEnlazadaSimple::invierte(){
    
    Nodo* anterior=nullptr;
    Nodo*actual=cabeza;
    Nodo *siguiente;
    
    while(actual !=nullptr){
        siguiente=actual->getSig();
        actual->setSig(anterior);
        anterior=actual;
        actual=siguiente;
    }
    
    Nodo *aux=cabeza;
    cabeza=cola;
    cola=aux;
  
}

ListaEnlazadaSimple::ListaEnlazadaSimple(){
    cabeza=nullptr;
    cola=nullptr;
    num_elemento=0;
}

int ListaEnlazadaSimple::getNumElementos() const{
    return num_elemento;
}

Nodo* ListaEnlazadaSimple::siguiente(Nodo *pos) const{
    if(pos!=nullptr){
        return pos->getSig(); 
    }
    else{
        return nullptr;
    }
}

Nodo* ListaEnlazadaSimple::fin() const{
    return nullptr;
}

Nodo* ListaEnlazadaSimple::primera() const { 
    return cabeza; 
}

bool ListaEnlazadaSimple::esVacia() const {
    return(num_elemento==0); 
}

int ListaEnlazadaSimple::obtener(Nodo *p) const{
    return p->getElemento();  
}

Nodo *ListaEnlazadaSimple::buscar(int x) const {
    Nodo *pos=cabeza;
    bool encontrado=false;
    
    while(pos!=nullptr && !encontrado){
        if(pos->getElemento()==x){
            encontrado=true;
        }
        else
            pos=pos->getSig();        
    }
    return pos;
}

void ListaEnlazadaSimple::inserta_vacio(int x){
    Nodo *aux= new Nodo(x);
    cabeza=cola=aux;
}

void ListaEnlazadaSimple::inserta_final(int x){
    Nodo *aux= new Nodo(x);
    cola->setSig(aux);
    cola=aux;
}

void ListaEnlazadaSimple::inserta_inicio(int x){
    Nodo *aux= new Nodo(x);
    aux->setSig(cabeza);
    cabeza=aux;
}


Nodo * ListaEnlazadaSimple::anterior(Nodo *pos) const{
    Nodo *aux=cabeza;
    bool encontrado=false;
    
    while(aux!=nullptr && !encontrado){
        if(aux->getSig()== pos){
            encontrado=true;
            
        }
        else
            aux=aux->getSig();
    }
    return aux;
    
}

void ListaEnlazadaSimple::inserta_enmedio(int x,Nodo *p){
    cout<<p->getElemento()<<endl;
    Nodo *aux=new Nodo(x,p);
    Nodo *ant= anterior(p);
    ant->setSig(aux);
}

bool ListaEnlazadaSimple::insertar(int x, Nodo *p){
    bool res = true;


    if (p == nullptr){
        if (esVacia()){
            inserta_vacio(x);
        }
        else{
             inserta_final(x);
        }
    }

    else if (p == cabeza ){
            inserta_inicio(x);  
    }
    else{
        cout<<"Inserta enmedio "<<endl;
        inserta_enmedio(x,p);
    }
        num_elemento += 1;
        return res;
}



bool ListaEnlazadaSimple::eliminar(Nodo *p){
	bool res=false;
	Nodo *temp;

	if(!esVacia() && p!=nullptr){
		if(p == cabeza){
			temp=cabeza;
			cabeza=cabeza->getSig();
			delete temp;
			res=true;
			num_elemento--;
			if(num_elemento==1){
				cola=cabeza;
			}

		}

		else{
		Nodo *q = cabeza;
		Nodo *anterior;

        while (q->getSig() != p
            && q->getSig() != nullptr)

            q = q->getSig();

        if (q->getSig() != nullptr){

        		temp=p;

             	q->setSig(p->getSig());

             	if(temp==cola){

             		cola=q;

				 }

             	delete temp;

        res=true;

        num_elemento--;

		}

		}

	}
	return res;

}

string ListaEnlazadaSimple::toString() const {
    string elem="";
    Nodo *p= cabeza;

    while(p!= nullptr){
    	elem+=std::to_string(p->getElemento())+"\n";
    	p=p->getSig();

    }
    return elem;
}

void ListaEnlazadaSimple::hacerVacia(){
	Nodo *q = cabeza;
	Nodo *temp;
    while (q!= nullptr){
    	temp=q;
		q = q->getSig();
    	delete temp;
	}
    cabeza=cola=nullptr;
    num_elemento=0;
}

ListaEnlazadaSimple::~ListaEnlazadaSimple(){

	Nodo *q = cabeza;
	Nodo *temp;

    while (q!= nullptr){
    	temp=q;
		q = q->getSig();
    	delete temp;
	}
} 


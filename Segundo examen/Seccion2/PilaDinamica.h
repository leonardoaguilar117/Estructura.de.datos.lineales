#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

template <typename E>

class PilaDinamica{
	private:
		Nodo<E> * tope;
		int numElementos;
	public:
		PilaDinamica(); //Constructor
		~PilaDinamica(); //Destructor
		void push(E x); //Ingresa elementos en el tope de la pila
		void pop();
		E getTope() const;
		bool esVacia() const;
		int getTamanio() const;
		void sustituye(int original, int nuevo);
		std::string toString() const;
		std::string toString2() const;
};

//Constructor: Inicializa por primera vez la Pila
template <typename E>
PilaDinamica<E>::PilaDinamica(){
	tope=NULL;
	numElementos=0;
	
}

template <typename E>
PilaDinamica<E>::~PilaDinamica(){

while(!esVacia()){
	pop();
}
	
}

template <typename E>
void PilaDinamica<E>::push(E elemento){
	E* elemento_ptr = new E(elemento);  // Crea un puntero al elemento
	Nodo<E> *nuevo = new Nodo<E>(elemento_ptr, tope);  // Pasa el puntero al elemento

	tope=nuevo;
	numElementos++; //numElementos=numElementos+1;
	
}

template <typename E>
void PilaDinamica<E>:: pop(){
	if(!esVacia()){
		Nodo<E> *aux=tope;
		tope=tope->getSiguiente();
		//Faltan dos cosas
		delete aux;
		numElementos--;
	}
}

template <typename E>
E PilaDinamica<E> :: getTope() const{
	
	if(!esVacia()){
		
		return tope->getElemento();
		
	}

}

template <typename E>
bool PilaDinamica<E>::esVacia() const {
 bool vacia=false;
 if(numElementos==0)
 	vacia=true;
 
 return vacia;
// return (numElementos == 0);
     
}

template <typename E>
int PilaDinamica<E>::getTamanio() const{

return numElementos;

}

template <typename E>
std::string PilaDinamica<E>::toString() const{

std:string salida ="[";
Nodo<E> *p= tope;
while(p != NULL){
	if(p->getSiguiente() ==NULL){
	salida +=std::to_string(p->getElemento());
	}
	else{
	  salida +=std::to_string(p->getElemento())+", ";
	}
	
	p=p->getSiguiente();
	
}

salida+="]";

return salida;

}

template <typename E>
std::string PilaDinamica<E>::toString2() const{

std:string salida ="[";
Nodo<E> *p= tope;
while(p != NULL){


	  salida +=std::to_string(p->getElemento())+", ";
  		p=p->getSiguiente();
	
}

//Quitamos la última coma
salida.pop_back();
salida.pop_back();
salida+="]";

return salida;

}


//---------- Función de intercambio de datos -------/
template<typename E>
void PilaDinamica<E>::sustituye(int original, int nuevo){
	Nodo<E> *p = this->getTope(); 
    while (p != nullptr) {
        if(p->getElemento() == original){
			p->setElemento(nuevo);
		}
    }
}



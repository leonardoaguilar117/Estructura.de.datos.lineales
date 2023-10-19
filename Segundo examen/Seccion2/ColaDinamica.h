#include "NodoCola.h"

template <typename E>

class QueueDinamica{
	private:
		Nodo<E> *frente; //Este es un nodo centinela
		Nodo<E> *fin;   //Este �nicamente ser� un apuntador al �ltimo nodo ingresado
		int numElementos;
		
	public:
		QueueDinamica(); //Constructor
		~QueueDinamica(); //Destructor
		void enqueue(E x);
		void dequeue();
		E getFrente() const;
		bool esVacia() const;
		int getTamanio() const;
		std::string toString() const;
		void hacerVacia();

};


template <typename E> 
QueueDinamica<E>::QueueDinamica(){
	frente = new Nodo<E> ();
	fin=frente;
	numElementos=0;
	
}

template <typename E> 
QueueDinamica<E>::~QueueDinamica(){
//Borrar todos los nodos de la lista (Incluyendo al nodo sentinela frente)
    Nodo<E> *aux = frente;
    //No he llegado al final de la Lista
    while(aux != NULL ){
        Nodo<E> *p = aux;
        aux = aux->getSiguiente();
        delete p;                
    }	
}

template <typename E> 
bool QueueDinamica<E>::esVacia() const{
    //Verifica si la lista esta vacia
    bool res = false;
    if(frente == fin){
        res = true;
    }
    else{
        res = false;
    }
    
    return res;
	
}

template <typename E> 
int QueueDinamica<E>::getTamanio() const{

	return numElementos;
}

template <typename E> 
void QueueDinamica<E>::enqueue(E x) {
    //Se crea un nuevo nodo en memoria    
    Nodo<E> *nuevo = new Nodo<E>(x,NULL);
    //Si es vacia , inserta un nuevo nodo
    if(esVacia()){        
        fin->setSiguiente(nuevo);    
        fin = nuevo;                 //Agrega un nodo al siguiente de frente
    }
    else{                            
        fin->setSiguiente(nuevo);       
        fin = fin->getSiguiente();  //Agrega un nodo al siguiente del ultimo
    }
    numElementos++;
	
}


template <typename E> 
void QueueDinamica<E>::dequeue(){
    //Solo puedo eliminar algo si la lista no est� vac�a
    if(!esVacia()){
        //Apunta al primer nodo despues de frente
        Nodo<E> *actual = frente->getSiguiente(); 
        //Apunta al siguiente del primer nodo
        Nodo<E> *despues = actual->getSiguiente();        
        frente->setSiguiente(despues);
        //Elimina el primer nodo
        delete actual;                              
        numElementos--;       
    }
	
}


template <typename E> 
void QueueDinamica<E>::hacerVacia() {
	    
    frente = fin;
	
}



template <typename E> 
E QueueDinamica<E>::getFrente() const{
    //Obtiene el elemento del primer nodo
    E elemento = frente->getSiguiente()->getElemento();
    //Regresa el elemento
	return elemento;
	
}



template <typename E> 
std::string QueueDinamica<E>::toString() const{
std::string cadena="[";

	if(!esVacia()){
		//Me salto el nodo centinela
		Nodo<E> *p= frente->getSiguiente();
		//Itero toda la cola
		while(p!=NULL){
			
			cadena+=std::to_string(p->getElemento())+",";
			p=p->getSiguiente();
		}
		cadena+="]";
		
	}
	
return cadena;
}


//----- Funcion de intercambio de datos ----// 
template<typename E>
void QueueDinamica<E>::sustituye(int original, int nuevo){
	Nodo<E> *p = this->getTope(); 
    while (p != nullptr) {
        if(p->getElemento() == original){
			p->setElemento(nuevo);
		}
        p = p->setSiguiente(); 
    }
}



template <typename T>
class Nodo {

public:

    Nodo(); //Constructor

    Nodo(T *elemento); //Constructor que recibe tipo de datos generico

    Nodo<T> *getPrevio(); //Getter al apuntador previo genérico

    Nodo<T> *getSiguiente(); //Getter al apuntador siguiente generico

    void setElemento(T* elemento);

    void setSiguiente(Nodo<T>* siguiente); //Setter al apuntador siguiente genérico

    void setPrevio(Nodo<T>* previo); // Setter al apuntador previo genérico

    T * getElemento(); //Get elemento Generico

   // void setElemento(T elem);

private:
    Nodo<T>* siguiente;
    Nodo<T>* previo;
     T *elem;
};


template <typename E>
Nodo<E>::Nodo() {
    siguiente = nullptr;
    previo = nullptr;
}


template <typename T>
Nodo<T>::Nodo(T *elemento) {
    siguiente = nullptr;
    previo = nullptr;
    elem=elemento;
}


template <typename T>
Nodo<T> *Nodo<T>::getPrevio() {
   return previo;
}


template <typename T>
Nodo<T> *Nodo<T>::getSiguiente() {
   return siguiente;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* sig){
	siguiente=sig;	
}

template <typename T>

void Nodo<T>::setPrevio(Nodo<T>* prev){

	previo=prev;
	
}


template <typename T>

T *Nodo<T>::getElemento(){
	return elem;
	
	
}

template <typename T>
void Nodo<T>::setElemento(T* elemento) {
    elem = elemento;
}

#include "ListaEnlazadaSimple.h"

class QueueList{
    private:
    ListaEnlazadaSimple l1;
    
    public:
        QueueList(); //Constructor
        ~QueueList(); //Destructor
        bool enqueue(int x); //Inserción al final de la cola
        bool dequeue(); //Elimina el valor del frente de la cola
        int frente() const; //Regresa el frente de la cola
        bool esVacia() const; //¿Está vacía la cola?
        void hacerVacia(); //Vaciar la cola
        int getNumelementos() const;
        string toString() const;
};

//Constructor
QueueList::QueueList(){
}

//Destructor
QueueList::~QueueList(){
}

bool QueueList::enqueue(int x){
    l1.insertar(x, l1.fin());
    return true;    
}


bool QueueList::dequeue(){
    if( !esVacia() )
        l1.eliminar(l1.primera());
    return true;    
}


int QueueList::frente() const{ 
    if( !esVacia())
        return l1.obtener(l1.primera());
    else
        return -1;
}

bool QueueList::esVacia() const{
    return l1.esVacia();
}

void QueueList::hacerVacia(){
    l1.hacerVacia();
}

int QueueList::getNumelementos() const{    
    return l1.getNumElementos();    
}

string QueueList::toString() const{
    return l1.toString(); 
}
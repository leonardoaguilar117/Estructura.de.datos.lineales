#include "Nodo.h"
#include <string>

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
        void invierte();
    
};


void ListaEnlazadaSimple::invierte(){
    
    Nodo* anterior=NULL;
    Nodo*actual=cabeza;
    Nodo *siguiente;
    
    while(actual !=NULL ){
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
    cabeza=NULL;
    cola=NULL;
    num_elemento=0;
    
    
}

int ListaEnlazadaSimple::getNumElementos() const{
    
    return num_elemento;
}

Nodo* ListaEnlazadaSimple::siguiente(Nodo *pos) const{
    
    if(pos!=NULL){
        
        return pos->getSig(); //Mas pro
        //(*pos).getSig(); es equivalente
    }
    else{
        return NULL;
    }
}

Nodo* ListaEnlazadaSimple::fin() const{
    return NULL;
    
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
    bool encontrado=false;
    
    while(pos!=NULL && !encontrado){
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
    
    while(aux!=NULL && !encontrado){
        if(aux->getSig()== pos){
            encontrado=true;
            
        }
        else
            aux=aux->getSig();
    }
    
    return aux;
    
}

void ListaEnlazadaSimple::inserta_enmedio(int x,Nodo *p){
    cout<<"Inserta enmedio2" <<endl;
    cout<<p->getElemento()<<endl;
    cout<<"Despues de imprimir "<<endl;
    Nodo *aux=new Nodo(x,p);
    cout<<"Despues de crear "<<endl;
    Nodo *ant= anterior(p);
    cout<<"Despues de anterior"<<endl;
    ant->setSig(aux);
    cout<<"Despues de cambiar siguiente "<<endl;
}

bool ListaEnlazadaSimple::insertar(int x, Nodo *p){


  bool res = true;
    if (p == NULL)
{

        if (esVacia())
        {
           
            inserta_vacio(x);
        }
        else{
             inserta_final(x);
      
            
        }
       
           
}
    else if (p == cabeza )
{
            inserta_inicio(x);
        
}
    else
    {
cout<<"Inserta enmedio "<<endl;
      inserta_enmedio(x,p);

    }
  num_elemento += 1;

    return res;

    
    

}



bool ListaEnlazadaSimple::eliminar(Nodo *p){

	bool res=false;

		Nodo *temp;

	if(!esVacia() && p!=NULL){

		

		//Si se tiene que quitar la cabeza

		if(p == cabeza){

			//Se guarda temporalmente la posicion actual

			temp=cabeza;

			//Se actualiza la nueva cabeza

			cabeza=cabeza->getSig();

			//Se borra el nodo cabeza antiguo

			delete temp;

			res=true;

			num_elemento--;

			if(num_elemento==1){

				//Si es el �nico elemento, se actualiza la cola

				cola=cabeza;

			}

		}

		else{ //Es cualquier otro nodo

		//Se busca su antecesor

		Nodo *q = cabeza;

		Nodo *anterior;

        while (q->getSig() != p

               && q->getSig() != NULL)

            q = q->getSig();

        if (q->getSig() != NULL){

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

//	//Si fuera el �nico nodo en la lista (cabeza == null y la lista no est� vac�a)

//	delete p;

//	cabeza =NULL;

//	cola=NULL;

//	numElementos=0;

	

	

	//TO DO

	return res;

}

string ListaEnlazadaSimple::toString() const {

string elem="";

Nodo *p= cabeza;

//No he llegado al final de la Lista

while(p!= NULL){

	elem+=std::to_string(p->getElemento())+"\n";

	p=p->getSig();

	

}

return elem;

}

void ListaEnlazadaSimple::hacerVacia(){



	 Nodo *q = cabeza;

	 Nodo *temp;

        while (  q!= NULL){

        	temp=q;

			q = q->getSig();

        	delete temp;

        	

		}

    cabeza=cola=NULL;

    num_elemento=0;

      

}
ListaEnlazadaSimple::~ListaEnlazadaSimple(){

	 Nodo *q = cabeza;

	 Nodo *temp;

        while (  q!= NULL){

        	temp=q;

			q = q->getSig();

        	delete temp;

        	

		}

	

} 



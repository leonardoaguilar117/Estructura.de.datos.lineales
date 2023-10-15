#include <iostream>
#include <string>
using namespace std;


template <typename E>
class ColaArreglo{
	private:
		static const int TAMANIO_MAX=169;//Tama�o m�ximo del arreglo
		E elementos[TAMANIO_MAX]; // Arreglo de tipo gen�ricos para almacenar los elementos
		int numElementos; //Variable que llega el registro con la cuenta de los elementos
		int frente;
		int fin; //Es el �ndice que apunta a la primera posici�n disponible
	public:
		ColaArreglo<E>(); //Constructor
		~ColaArreglo<E>(); //Destructor
		bool enqueue(E x ); //Insercion al "final"
		bool dequeue();  //Quita el elemento de el "enfrente"
		E getFrente() const; //Regresa el elemento al frente
		bool esVacia() const; //Verifica si es vac�a (necesitamos usar la variable numElementos)
		void hacerVacia(); //Indica que se pueden rellenar todos los elementos
		std::string toString() const; //Convierte a cadena
		std::string toString2() const; //Convierte a cadena
		int getTamanio () const; //Regreas la variable numElementos	
		void invierte();
};

//Constructor
template <typename E>
ColaArreglo<E>::ColaArreglo(){
	numElementos=0;
	frente=0;
	fin=0;
	
}



template <typename E>
ColaArreglo<E>:: ~ColaArreglo(){
	
}

template <typename E>
bool ColaArreglo<E>:: enqueue(E x) {
    bool res=false;
	if(numElementos <TAMANIO_MAX ){
		res=true;
		
elementos[fin]=x;
	numElementos++; 
	fin=(fin+1) %TAMANIO_MAX;
	}
	
return res;
	
}

template <typename E>
bool ColaArreglo<E>::dequeue(){
	bool res=false;
	if(numElementos != 0){
	    
	res=true;
		frente=(frente+1) % TAMANIO_MAX;
	numElementos--;
	
	}
	
return res;
	
}

template <typename E>
E ColaArreglo<E>::getFrente() const{
	E aux=NULL;
	if(numElementos !=0){
	aux=elementos[frente];
	}

return aux;
	
}

template <typename E>
bool ColaArreglo<E>::esVacia() const{
	
	
return numElementos== 0;
}

template <typename E>
void ColaArreglo<E>::hacerVacia() {
	numElementos=0;
	frente=0;
	fin=0;
}

template <typename E>
int ColaArreglo<E>:: getTamanio() const{
	return numElementos;
}

template <typename E>
std::string ColaArreglo<E>:: toString() const{

std::string salida= "[";
if(!esVacia()){
	int i=0; //Numero de elementos recorridos
	int indice_elemento=frente; //El indice del arreglo que se est� iterando
	while(i<numElementos){
		salida+=std::to_string(elementos[indice_elemento])+", ";
		indice_elemento=(indice_elemento+1)%TAMANIO_MAX;
		i++;
	}
	
salida.pop_back();
salida.pop_back();
}

salida+="]";

return salida;
}


template <typename E>
std::string ColaArreglo<E>::toString2() const{

std::string salida= "[";
if(!esVacia()){
	int i=0; //Numero de elementos recorridos
	int indice_elemento=frente; //El indice del arreglo que se est� iterando
	while(i<numElementos){
		
		if(i!=numElementos-1){
				salida+=std::to_string(elementos[indice_elemento])+", ";
		}
		else{
				salida+=std::to_string(elementos[indice_elemento]);
		}
	
		indice_elemento=(indice_elemento+1)%TAMANIO_MAX;
		i++;
	}
}

	salida+="]";

	return salida;
}


template <typename E>
void ColaArreglo<E>::invierte(){
	int arrayAux[fin+1], j=0;

    for(int i=fin-1; i>=0; --i){
		arrayAux[j] = elementos[i];
		j++;
	}

	for(int i=0; i<fin; i++){
		elementos[i] = arrayAux[i];
	}
	
}


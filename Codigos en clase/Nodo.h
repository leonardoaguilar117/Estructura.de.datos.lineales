class Nodo{

    private:
        int elemento;
        Nodo *sig;
    public:
        Nodo();  //Constructor vacío
        Nodo(int x); //Constructor que inicializa el elemnto
        Nodo(int x, Nodo *sig); //Constructor con elemento y apuntador sig
        ~Nodo(); //Destructor
        int getElemento();
        void setElemento(int x);
        Nodo *getSig();
        void setSig(Nodo *aux);

};


Nodo::Nodo(){
    elemento=0;
    sig=NULL; 
}

Nodo::Nodo(int x){
    elemento=x;
    sig=NULL; 
}

Nodo::Nodo(int x, Nodo *aux){ 
    elemento=x;
    sig=aux;   
}

Nodo::~Nodo(){    
}


int Nodo:: getElemento(){
    return elemento;
}

void Nodo:: setElemento(int valor){
    elemento=valor;
}


Nodo* Nodo::getSig(){
    return sig;
}

void Nodo::setSig(Nodo *aux){
    sig=aux;
}
#define TAM 100

class ListaArreglos{
    private:
        int arreglo[TAM];
        int n; //Describe el número de elementos "reales" en la lista
    
    public:
        ListaArreglos(); //Constructor
        ~ListaArreglos(); //Destructor
        bool insertar (int x, int p);
        bool eliminar(int p);
        int buscar (int x) const;
        int fin() const;
        int primera () const;
        int siguiente() const;
        bool hacerVacia();
        bool esVacia() const;
        string toString() const;
};

ListaArreglos::ListaArreglos(){
    n=0;
}

ListaArreglos::~ListaArreglos(){
    
    
    
}

int ListaArreglos::fin(){
    
    return n;
    
}

bool ListaArreglo::insertar(int x, int p){
    bool exito=false;
    
    if(p>= 0 && p<=n && n<TAM ){
        exito=true;
    for(int i=n; i>=p; i--)
        arreglo[i+1]=arreglo[i];
    arreglo[p]=x;
    n++;
    }
    
    return exito;
}

bool ListaArreglo::eliminar(int p){
    bool exito=false;
    if(p>=0 && p<n && n<TAM){
        
        exito=true;
        for(int i=p;i<n; i++){
            arreglo[i]=arreglo[i+1];
            
        }
        n--;
    }
    return exito;
}


bool ListaArreglo::hacerVacia(){
    
    n=0;
    
}

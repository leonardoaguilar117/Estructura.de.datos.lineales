class Nodo {
    public:
        int elemento;
        Nodo* sig;

    public:
        Nodo();  // Constructor vacío
        Nodo(int x); // Constructor que inicializa el elemento
        Nodo(int x, Nodo* sig); // Constructor con elemento y apuntador sig
        ~Nodo();
        int getElemento();
        void setElemento(int x);
        Nodo* getSig();
        void setSig(Nodo* aux);
};

    Nodo::Nodo() {
        elemento = 0;
        sig = nullptr;
    }

    Nodo::Nodo(int x) {
        elemento = x;
        sig = nullptr;
    }

    Nodo::Nodo(int x, Nodo* sig){
        elemento = x;
        sig = nullptr;
    }

    Nodo::~Nodo() {
    }

    int Nodo::getElemento() {
        return elemento;
    }

    void Nodo::setElemento(int valor) {
        elemento = valor;
    }

    Nodo* Nodo::getSig() {
        return sig;
    }

    void Nodo::setSig(Nodo* aux) {
        sig = aux;
    }



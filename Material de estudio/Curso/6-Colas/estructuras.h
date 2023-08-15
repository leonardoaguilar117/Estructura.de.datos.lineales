typedef struct Numero{
    int numero;
}Numero;

typedef struct Nodo{
    Numero *atributos;
    struct Nodo *Siguiente;
}Nodo;

typedef struct ColaCompleta{
    Nodo *cabeza;
}ColaCompleta;

 
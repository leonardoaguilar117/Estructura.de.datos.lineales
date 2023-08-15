typedef struct Numero{
    int numero;
}Numero;

typedef struct Nodo{
    Numero *atributos;
    struct Nodo *Siguiente;
}Nodo;

typedef struct PilaCompleta{
    Nodo *cabeza;
}PilaCompleta;

Numero *crearNumero(int numero);
void llenarPilas(PilaCompleta *pila,PilaCompleta *par,PilaCompleta *impar);
/*LEONARDO AGUILAR MARTINEZ 2203025005*/

/*Se define la estructura completa de Numero, nodo y Pila completa */
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


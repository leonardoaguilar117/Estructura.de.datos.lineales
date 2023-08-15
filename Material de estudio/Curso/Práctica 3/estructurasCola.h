/*LEONARDO AGUILAR MARTINEZ 2203025005*/

/*Se define la estructura de Numero, Nodo y Cola Completa para el funcionamiento general*/
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
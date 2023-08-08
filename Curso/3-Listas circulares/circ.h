//Estructuras y prototipos de funciones n   
typedef struct Alumno{
    char nombre[35];
    int matricula;
    int edad;
}Alumno;

typedef struct Nodo{
    Alumno *datos;
    struct Nodo *Siguiente;
}Nodo;

typedef struct ListaCircular{
    Nodo *cabeza;
    Nodo *cola;
}ListaCircular;

//Cabecera de funciones
ListaCircular *crear_Lista();
Alumno *crear_numero(int dato);
Nodo *crear_nodo(Alumno *alumno);
void insertar_cabeza(ListaCircular *lista,Nodo *nodo);
void insertar_cola(ListaCircular *lista,Nodo *nodo);
void insertar_enmedio(ListaCircular *lista,Nodo *ant, Nodo *nodo);
void insertar_enmedio(ListaCircular *lista,Nodo *desp, Nodo *nodo);
void quitar_cabeza(ListaCircular *lista);
void quitar_cola(ListaCircular *lista);
int buscar_elemento(ListaCircular *lista, int matricula);
Nodo *buscar_elementoP(ListaCircular *lista, Nodo *nodoAbuscar);
void quitar_enmedio(ListaCircular *lista, Nodo *elemento);
void print_lista(ListaCircular *lista);
int listaisEmpty(ListaCircular *lista);
void vaciarlista(ListaCircular *lista);
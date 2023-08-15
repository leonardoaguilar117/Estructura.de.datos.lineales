 typedef struct Alumno{
    int id;
    char nombre[35];
    int edad;
}Alumno;

typedef struct Nodo{
    Alumno *datos;
    struct Nodo *sigui;
    struct Nodo *ant;
}Nodo;

typedef struct ListaCD{
    Nodo *cabeza;
    Nodo *cola;
}ListaCD;

ListaCD *crear_Lista();
Alumno *crear_alumno(int id, char nombre[35],int edad);
Nodo *crear_nodo(Alumno *Alumno);
void insertar_cabeza(ListaCD *lista,Nodo *nodo);
void insertar_cola(ListaCD *lista,Nodo *nodo);
void insertar_enmedio(ListaCD *lista,Nodo *ant, Nodo *nodo);
void insertar_enmedio(ListaCD *lista,Nodo *desp, Nodo *nodo);
void quitar_cabeza(ListaCD *lista);
void quitar_cola(ListaCD *lista);
Nodo *buscar_elemento(ListaCD *lista, Nodo *nodo);
void quitar_enmedio(ListaCD *lista, Nodo *elemento);
void print_lista(ListaCD *lista);
int listaisEmpty(ListaCD *lista);
void vaciarlista(ListaCD *lista);
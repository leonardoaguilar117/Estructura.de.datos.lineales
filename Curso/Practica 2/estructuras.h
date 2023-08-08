typedef struct Alumno {
    int matricula;
    char name[35];
    int edad;
}Alumno;

typedef struct Nodo{
    Alumno *datos;
    struct Nodo *sig;
    struct Nodo *ant;
}Nodo;

typedef struct ListaD{
    Nodo *cabeza;
    Nodo *cola; // listas circulares
}ListaD;


Alumno* crear_Alumno(int matricula,char name[30], int edad);
Nodo *crear_Nodo(Alumno *alumno);
ListaD *crear_ListaD();
int isEmpty(ListaD *lista);
void insertar_cabeza(ListaD *lista, Nodo *aux);
void printLista(ListaD *lista);
void quitar_enmedio(ListaD *lista, int matricula);
void quitar_cabeza(ListaD *lista);
void quitar_cola(ListaD *lista);

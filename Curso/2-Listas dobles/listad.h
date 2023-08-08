typedef struct Alumno {
    int id;
    char name[30];
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


Alumno* crear_Alumno(int ID,char NAME[20], int EDAD);
Nodo *crear_Nodo(Alumno *alumno);
ListaD *crear_ListaD();
int isEmpty(ListaD *lista);
void insertar_cabeza(ListaD *lista, Nodo *aux);
void insertar_cola(ListaD *lista, Nodo *aux);
void insertar_enmedio1(ListaD *lista, Nodo *anterior,Nodo *elemento);
//void insertar_enmedio(ListaD *lista, Nodo *despues,Nodo *elemento);
void quitar_cabeza(ListaD *lista);
void quitar_cola(ListaD *lista);
void quitar_enmedio(ListaD *lista, Nodo *elemento);
Nodo* buscaElemento(ListaD *lista, Nodo *elemento);
void printLista(ListaD *lista);
void vaciarLista(ListaD*lista);
void selectsort(ListaD *lista);
void intercambio(ListaD *lista, Nodo *nodo, Nodo *men);
void QuickSort(ListaD *lista, Nodo *ini, Nodo *fin);
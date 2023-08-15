/*Estructuras y prototipos de funciones*/

typedef struct Tarea{
    int duracion;
    char NombreTarea[30];
}Tarea;

typedef struct Nodo{
    Tarea *atributos;
    struct Nodo *Siguiente;
    struct Nodo *cola;
}Nodo;

typedef struct ListaCompleta{
    Nodo *Cabeza;
}ListaCompleta;

/*Se crea una estructura para tarea, nodo y lista completa. En el caso de 
Tarea tiene dos atributos, para Nodo se crea un apuntador de tipo Tarea que 
apunta a los atributos de la tarea y una nueva structura llamada NodoSiguiente
para navegar entre estos.

Por último se define una estructura ListaCompleta la cual solo tiene un puntero
de tipo Nodo llamado cabeza*/


/*Prototipos de funciones */
Tarea *crearTarea(char nombreTarea[30],int duracion);
Nodo *crear_Nodo(Tarea *tareaEnNodo);
ListaCompleta *crearLista();

void insertar_cabeza(ListaCompleta *lista, Nodo *Nodo);
void printLista(ListaCompleta *lista);
int estaVacia(ListaCompleta Lista);
void insertar_cola(ListaCompleta *lista, Nodo *NodoAux);
void insertar_en_medio(ListaCompleta *lista, Nodo *anterior, Nodo *aInsertar);
void quitar_cabeza(ListaCompleta *lista);
void quitar_cola(ListaCompleta *lista);
void vaciarLista(ListaCompleta *lista);
Nodo *buscaElemento(ListaCompleta *lista, Nodo *elemento);
























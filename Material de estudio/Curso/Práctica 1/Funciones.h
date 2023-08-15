/*Estructuras y prototipos de funciones*/

typedef struct Alumno{
    char NombreAlumno[35];
    int edad;
    int matricula;
    char licenciatura[40];
    char division[40];
}Alumno;

typedef struct Nodo{
    Alumno *atributos;
    struct Nodo *Siguiente;
    struct Nodo *cola;
}Nodo;

typedef struct ListaCompleta{
    Nodo *Cabeza;
}ListaCompleta;

/*Se crea una estructura para alumno, nodo y lista completa. En el caso de 
alumno tiene 5 atributos, para Nodo se crea un apuntador de tipo alumno que 
apunta a los atributos del alumno y una nueva structura llamada NodoSiguiente
para navegar entre estos.

Por último se define una estructura ListaCompleta la cual solo tiene un puntero
de tipo Nodo llamado cabeza*/


/*Prototipos de funciones */
Alumno *crearAlumno(char nombreAlumno[35],int edad,int matricula,char licenciatura[40],char division[40]);
Nodo *crear_Nodo(Alumno *alumnoEnNodo);
ListaCompleta *crearLista();

void insertar_cabeza(ListaCompleta *lista, Nodo *Nodo);
void printLista(ListaCompleta *lista);
int estaVacia(ListaCompleta Lista);
void insertar_cola(ListaCompleta *lista, Nodo *NodoAux);
void insertar_en_medio(ListaCompleta *lista, Nodo *anterior, Nodo *aInsertar);
/*
void quitar_cabeza(ListaCompleta *lista);
void quitar_cola(ListaCompleta *lista);
void vaciarLista(ListaCompleta *lista);
Nodo *buscaElemento(ListaCompleta *lista, Nodo *elemento);
*/























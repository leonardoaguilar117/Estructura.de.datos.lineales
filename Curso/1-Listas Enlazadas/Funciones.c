#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include <string.h>

Tarea *crearTarea(char nombreTarea[30],int duracionTarea){
    Tarea *tareaNueva =  (Tarea*)malloc(sizeof(Tarea));
    strcpy(tareaNueva -> NombreTarea, nombreTarea);
    tareaNueva -> duracion = duracionTarea; 
    return(tareaNueva);
}
/*CREAR TAREA: Se crea el TAD con 2 parametros, se almacena de forma dinamica el espacio para la nueva tarea
  Se usa strcpy para guardar el nombre de la tarea en el parametro NombreTarea del TAD tareaNueva
  por ser un string, en el caso de duración solo se da un valor por asignación. Retorna la tareaNueva
*/

Nodo *crear_Nodo(Tarea *tareaEnNodo){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo -> atributos = tareaEnNodo;
    nodo -> Siguiente = NULL; 
    return(nodo);
}
/*CREAR NODO: Se crea el Nodo que almacenará la tarea, se almacena de forma dinamica y los del nodo serán
  igual la tarea a almacenar y el puntero que va hacia delante lo colocamos en NULL
  Retorna el nodo creado
*/

ListaCompleta *crearLista(){
    ListaCompleta *Lista = (ListaCompleta*)malloc(sizeof(ListaCompleta));
    Lista -> Cabeza = NULL;
    return(Lista);
}
/*LISTA COMPLETA: Se crea la lista completa y se almacena de forma dinamica, su atributo cabeza estará en NULL ya
  que si apenas se crea la lista no está apuntando a ningún lado
  Retorna la lista creada
*/

int estaVacia(ListaCompleta Lista){
    if(Lista.Cabeza == NULL){
        return(0);
    }else{
        return(1);
    }
}
/*ESTÁ VACÍA: Si el atributo cabeza de Lista está vacio, retorna un 0, de lo contrario 1*/

void insertar_cabeza(ListaCompleta *lista, Nodo *Nodo){
    if(estaVacia(*lista)==0){
        Nodo -> Siguiente = lista -> Cabeza;
        lista -> Cabeza = Nodo;
    }else{
        lista->Cabeza = Nodo;
    }
}

/*INSERTAR CABEZA: Se tienen dos parametros: la lista y el nodo a insertar, al comenzar se comprueba
  si la lista está vacia, si lo está, el Nodo en su campo siguiente será igual a
  la cabeza de la lista y la cabeza será igual a la dirección del Nodo, de lo 
  contrario, la cabeza en la lista será igual al Nodo 
  */

void printLista(ListaCompleta *lista){
    Nodo *NodoAux = lista->Cabeza;
    Tarea *TareaAux;
    if(estaVacia(*lista)==1) {
        while(NodoAux!=NULL){
            TareaAux = NodoAux-> atributos;
            printf(" Nombre de la tarea: %s\n", TareaAux -> NombreTarea);
            printf(" Duracion de la tarea: %d\n", TareaAux -> duracion);
            NodoAux = NodoAux-> Siguiente;
        }
    }
    else{
        printf("\n LISTA SIN NADA \n");
    }
    TareaAux = NULL;
    NodoAux = NULL;
    free(NodoAux);
    free(TareaAux);
}
/* PRINT LISTA: Para imprimir la lista es necesario un NodoAux que apunte a la cabeza y una
   tarea auxiliar
   Si la lista tiene elementos se recorrerá para mostrar los datos. NodoAux apunta
   a la cabeza, esto para comenzar desde ella, por cada iteración se recorrerá al
   siguiente campo del nodo.
   En el caso de TareaAux éste apunta hacia los atributos de NodoAux el cual 
   contiene el Nombre y duración de la tarea.
*/

void insertar_cola(ListaCompleta *lista, Nodo *NodoAux){
    Nodo *cola;
    cola = lista -> Cabeza;
    if(estaVacia(*lista)==0){
        insertar_cabeza(lista, NodoAux);
    }else{
        while(cola -> Siguiente != NULL){
            cola = cola -> Siguiente;
        }
        cola -> Siguiente = NodoAux;
        cola = NodoAux;
        cola = NULL;
        free(cola);
    }
}
/*INSERTAR COLA: Al insertar en cola se sobbre entiende que se colocarán elementos
  por detrás del ultimo elemento. Inicialmente se crea una cola con dirección
  en la cabeza de la lista, esto para iniciar el recorrido desde el inicio de 
  la lista, si la lista está vacia insertaremos cabeza, de lo 
  contrario recorreremos la lista hasta que se encuentre el final NULL, cuando
  se encuentre la cola será igual al NodoAux y se libera memoria*/

void insertar_en_medio(ListaCompleta *lista, Nodo *anterior, Nodo *aInsertar){
    if(estaVacia(*lista) == 0){
        lista->Cabeza=aInsertar;
    }else{
        aInsertar -> Siguiente = anterior->Siguiente;
        anterior-> Siguiente = aInsertar;
    }
}
/*INSERTAR EN MEDIO: Se necesita de un nodo que indique una dirección anterior y otro nodo a insertar,
  si la lista está vacía solo se inserta a la cabeza el nodo a insertar, de lo 
  contrario, se inserta el nodo entre el nodo anterior y su dirección siguiente*/

void quitar_cabeza(ListaCompleta *lista){
    Nodo *NodoAux;
    if(isEmpty(lista)==1){
        NodoAux = lista->Cabeza;
        lista -> Cabeza = lista->Cabeza->Siguiente;
        NodoAux = NULL;
        free(NodoAux);
    }else{
        printf("La lista esta vacia, estoy dentro del procedimiento quitar cabeza");
    }
}
/*QUITAR CABEZA: Para quitar cabeza se comprueba que haya elementos dentro de la lista 
  si los hay, el NodoAux almacena el valor de la cabeza, para después
  intercambiar la dirección de la cabeza por el siguiente elemento de la lista,
  ya teniendo eso, podemos liberar al NodoAux
*/


void quitar_cola(ListaCompleta *lista){
    Nodo *cola;
    Nodo *anterior;
    if(isEmpty(lista)==0){ //Sí está vacía 
        printf("La pila esta vacia estoy dentro del procedimiento quitar cola\n");
    }else{

        if(lista ->Cabeza ->Siguiente == NULL){ //Unico elemento 
            lista -> Cabeza = NULL;
            printf("Memoria liberada estoy en el procedimiento quitar cola\n");
        }else{  
            cola = lista->Cabeza;
            while(cola -> Siguiente != NULL){
                anterior = cola;
                cola = cola->Siguiente;
            }
            anterior ->Siguiente=NULL;
            cola=NULL;
            anterior=NULL;
            free(cola);
            free(anterior);
        }
    }
}

/*QUITAR COLA: Se tienen 3 subopciones, la primera es que si está vacía no se ejecutará nada,
  la segunda es que si tiene un unico elemento se borra con quitar cabeza y la tercera es que la lista 
  se recorrerá desde la cabeza mientras sea diferente de NULL (final) cuando se llegue al final, la cola
  y anterior se pondrán en nulo*/


void vaciarLista(ListaCompleta *lista){
    Nodo *NodoAux = lista->Cabeza;
    if(estaVacia(*lista)==1){
        while(NodoAux != NULL){
            NodoAux = NodoAux ->Siguiente;
            quitar_cabeza(lista);
        }
    }else{
        printf("Lista sin nada\n");
    }
    NodoAux = NULL;
    free(NodoAux);
}

/* VACIAR LISTA: Es necesario recorrer esta misma y si si tiene elementos
   utilizar la función quitar cabeza, después de esto recorrer y fijar NodoAux a siguiente
   y repetir la operación, ésto para quitar cada nodo y reutilizar quitar cabeza, de lo 
   contrario, solo se informará que está vacia la lista, al final se libera a NodoAux
*/


Nodo *buscaElemento(ListaCompleta *lista, Nodo *elemento){
    Nodo *NodoAux = lista->Cabeza;
    if(estaVacia(*lista)==1){
        while(NodoAux->atributos ->duracion != elemento->atributos->duracion){
            if(NodoAux->Siguiente !=NULL){
                NodoAux = NodoAux -> Siguiente;
            }else{
                printf("El elemento con duración: %d no se encontró\n",elemento->atributos->duracion);
                NodoAux = NULL;
                return(NodoAux);
                break;
            }
        }
        if(NodoAux ->atributos->duracion == elemento->atributos->duracion){
            printf("El elemento con duracion %d si esta en la lista\n",elemento->atributos->duracion);
            return(NodoAux);
        }
    }else{
        printf("La lista no tiene elementos\n");
        return(NULL);
    }
    
    return(NodoAux);

}
/*BUSCAR ELEMENTO: Si la lista tiene elementos, se recorre para encontrar el elemento, si al pasar por
  por cada elemento no se encuentra, se envía un mensaje, se retorna NULL y se rompe la función.
  Si se encuentra el elemento se retorna un mensaje y el nodo auxiliar que lo contiene, si ninguna
  condicion se cumple es porque la lista no tiene elementos. AL final se libera la memoria.
*/

void quitar_enmedio(ListaCompleta *lista, Nodo *elemento){
    Nodo *anterior;
    Nodo *borrar;

    if(estaVacia(*lista)==0){
        printf("La pila esta vacia, estoy dentro del procedimiento quitar en medio\n");
    }else{
        borrar = buscaElemento(lista,elemento);

        if(borrar==NULL){
            printf("No hay nada que borrar");
        }else{

            if(lista->Cabeza==borrar){
                quitar_cabeza(lista);
            }else{
                anterior = lista -> Cabeza;
                while(anterior->Siguiente!=borrar){
                    anterior =anterior->Siguiente;
                }
                anterior->Siguiente = borrar->Siguiente;
                borrar = NULL;
                anterior = NULL;
                free(borrar);
                free(anterior);
            }

        }
    }
}

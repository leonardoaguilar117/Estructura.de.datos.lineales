#include <stdlib.h>
#include <stdio.h>
#include "Funciones.h"
#include <string.h>

Alumno *crearAlumno(char nombreAlumno[35],int edad,int matricula,char licenciatura[40],char division[40]){
    Alumno *crearAlumno =  (Alumno*)malloc(sizeof(Alumno));
    strcpy(crearAlumno -> NombreAlumno, nombreAlumno);
    strcpy(crearAlumno -> licenciatura, licenciatura);
    strcpy(crearAlumno -> division, division);
    crearAlumno -> edad = edad;
    crearAlumno -> matricula = matricula;
    return(crearAlumno);
}
/*CREAR TAREA: Se crea el TAD con 5 parametros, se almacena de forma dinamica el espacio para la nueva tarea
  Se usa strcpy para guardar el nombre de la tarea en el parametro NombreTarea del TAD tareaNueva
  por ser un string, en el caso de duración solo se da un valor por asignación. Retorna la tareaNueva
*/

Nodo *crear_Nodo(Alumno *alumnoEnNodo){
    Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo -> atributos = alumnoEnNodo;
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
    if(estaVacia(*lista)==1){
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
    Alumno *alumnoAux;
    if(estaVacia(*lista)==1) {
        while(NodoAux!=NULL){
            alumnoAux = NodoAux-> atributos;
            printf(" Nombre del alumno: %s \n", alumnoAux -> NombreAlumno);
            printf(" Edad: %d\n", alumnoAux -> edad);
            printf(" Matricula: %u\n", alumnoAux -> matricula);
            printf(" Licenciatura: %s\n", alumnoAux -> licenciatura);
            printf(" Division: %s\n", alumnoAux -> division);
            printf("\n\n\n");
            NodoAux = NodoAux-> Siguiente;
        }
    }
    else{
        printf("\n LISTA SIN NADA \n");
    }
    alumnoAux = NULL;
    NodoAux = NULL;
    free(NodoAux);
    free(alumnoAux);
}

/* PRINT LISTA: Para imprimir la lista es necesario un NodoAux que apunte a la cabeza y una
   tarea auxiliar
   Si la lista tiene elementos se recorrerá para mostrar los datos. NodoAux apunta
   a la cabeza, esto para comenzar desde ella, por cada iteración se recorrerá al
   siguiente campo del nodo.
   En el caso de TareaAux éste apunta hacia los atributos de NodoAux el cual 
   contiene el Nombre y duración de la tarea
   */


Nodo *buscaElemento(ListaCompleta *lista, int matricula){
    Nodo *NodoAux = lista->Cabeza;
    if(estaVacia(*lista)==1){
        while(NodoAux->atributos -> matricula != matricula){
            if(NodoAux->Siguiente !=NULL){
                NodoAux = NodoAux -> Siguiente;
            }else{
                printf("El alumno no se encontro");
                NodoAux = NULL;
                return(NodoAux);
                break;
            }
        }
        if(NodoAux ->atributos->matricula == matricula){
            printf("ENCONTRADO CON EXITO \n");
            printf("Nombre: %s \n",NodoAux->atributos->NombreAlumno);
            printf("Matricula: %u \n",NodoAux->atributos->matricula);
            printf("Edad: %d \n",NodoAux->atributos->edad);
            printf("Licenciatura: %s \n",NodoAux->atributos->licenciatura);
            printf("Division: %s \n",NodoAux->atributos->division);
             printf("-----------------------------------------------\n");
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

Nodo *buscaElementoA(ListaCompleta *lista, int matricula){
    Nodo *NodoAux = lista->Cabeza;
    if(estaVacia(*lista)==1){
        while(NodoAux->atributos -> matricula != matricula){
            if(NodoAux->Siguiente !=NULL){
                NodoAux = NodoAux -> Siguiente;
            }else{
                printf("El alumno no se encontro");
                NodoAux = NULL;
                return(NodoAux);
                break;
            }
        }
        if(NodoAux ->atributos->matricula == matricula){
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

void quitar_cabeza(ListaCompleta *lista){
    Nodo *NodoAux;
    if(estaVacia(*lista)==1){
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


void quitar_enmedio(ListaCompleta *lista, int matricula){
    Nodo *anterior;
    Nodo *borrar;

    if(estaVacia(*lista)==0){
        printf("La pila esta vacia, estoy dentro del procedimiento quitar en medio\n");
    }else{
        borrar = buscaElementoA(lista,matricula);

        if(borrar==NULL){
            printf("No hay nada que borrar\n\n");
        }else{

            if(lista->Cabeza==borrar){
                quitar_cabeza(lista);
                printf("Elemento eliminado\n\n");
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
                printf("Elemento eliminado");
            }

        }
    }
}




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
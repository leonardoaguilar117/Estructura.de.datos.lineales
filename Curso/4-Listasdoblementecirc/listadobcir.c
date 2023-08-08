#include <stdio.h>
#include <stdlib.h>
#include "dbcir.h"
#include <string.h>

ListaCD *crear_Lista(){
     ListaCD *aux=(ListaCD*)malloc(sizeof(ListaCD));
     aux->cabeza=NULL;
     aux->cola=NULL;
     return aux;
}

Alumno *crear_alumno(int id, char nombre[35], int edad){
     Alumno *aux=(Alumno*)malloc(sizeof(Alumno));
     aux->id=id;
     aux->edad=edad;
     strcpy(aux->nombre,nombre);
     return aux;
}

Nodo *crear_nodo(Alumno *alumno){
     Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
     aux->datos=alumno;
     aux->sigui=NULL;
     aux->ant=NULL;
     return aux;
}

int listaisEmpty(ListaCD *lista){
    if(lista->cabeza==NULL){
        return 0;
    } 
    else{
        return  1;
    }
}

void insertar_cabeza(ListaCD *lista,Nodo *nodo){
    if(listaisEmpty(lista)==0){ // verificar si la lista esta vacia 
        lista->cabeza=nodo; // si esta vacia insertar un nodo en la cabeza
        lista->cola=nodo;   // como nodo tendra dos apuntadores los dos seran el nodo que llego
        lista->cabeza->ant=nodo;
        lista->cabeza->sigui=nodo;
    }
    else{                         // si no esta vacia 
        nodo->sigui=lista->cabeza;// el nodo siguiente apuntara a lista cabeza ->
        lista->cabeza->ant=nodo;  // flechas del nodo a lista cabeza <-
        nodo->ant=lista->cola;    // flechas del nodo a la cola <-
        lista->cola->sigui=nodo;  // el último noddo de la lista apuntara al nodo que llego ->
        lista->cabeza=nodo;       // movemos el apuntador de lista cabeza    
        
    }
}

void insertar_cola(ListaCD *lista,Nodo *nodo){ 
    if(listaisEmpty(lista)==0){ // verificar si la lista esta vacia
        insertar_cabeza(lista,nodo); // si esta vacia se inserta el nodo
    }
    else{
        nodo->ant=lista->cola; //pegar la flechita del nodo antrior a la cola
        lista->cola->sigui=nodo; //apuntar de la cola al nodo que llego
        nodo->sigui=lista->cabeza;  // apuntar del nodo siguiente a la lista cabeza para que sea circular
        lista->cabeza->ant=nodo;    // apuntar la flechita de a cabeza anterior al nodo que llego
        lista->cola=nodo;          // mover la cola
    }
}

void insertar_enmedio(ListaCD *lista,Nodo *antes, Nodo *nodo){
   if(listaisEmpty==0 || lista->cabeza == lista->cola){
        insertar_cabeza(lista,nodo);
    }else{
        nodo->sigui=antes->sigui; 
        antes->sigui->ant=nodo; 
        nodo->ant=antes;    
        antes->sigui=nodo;  
    }
}

void quitar_cabeza(ListaCD *lista){
    Nodo *nodo=lista->cabeza;
    if(listaisEmpty(lista)==0){
        printf("La lista se encuentra vacia quitar cabeza\n\n");
    }
    else{
        if(lista->cabeza==lista->cola){
                nodo=lista->cabeza;
                lista->cabeza=NULL; //quitar los apuntadores del nodo que quedo 
                lista->cola=NULL;   //quitar los apunadores del nodo que quedo
        }
        else{ 
            lista->cabeza=lista->cabeza->sigui; //cambiar la cabeza de posicion
            lista->cabeza->ant=lista->cola;    // de la cabeza a la cola
            lista->cola->sigui=lista->cabeza; // cambiar de apuntador el sig de la cola ya que se quito la cabeza
            nodo->sigui=NULL;     // poner el apuntador siguiente de la anterior cabeza en NULL Recordar que el orden es importante
            nodo->ant=NULL;       // Desconectar lo del nodo que se quiere eliminar
        }    
         //printf("asdasd");
         //free(nodo);
    }
     //printf("asdasd");
    free(nodo);
    // printf("asdasd");
}



void quitar_cola(ListaCD *lista){
    Nodo *aux;
    if(listaisEmpty(lista)==0){  // Caso en el que se encuentre la lista vacia
        printf("La lista se encuentra vacia no puedo quitar la cola\n");
    }
    else if(lista->cabeza==lista->cola){
        quitar_cabeza(lista);
    }
    else{
        aux=lista->cabeza;
        while(aux->sigui!=lista->cola){
          aux=aux->sigui;
        }
        lista->cola=aux;  // cambiar la cola de lugar
        aux=aux->sigui;   // Cambiar el aux de lugar
        lista->cola->sigui=lista->cabeza; //lista cola siguinte ahora apuntara a la cabeza 
        lista->cabeza->ant=lista->cola; // la lista apunta a la cola denuevo
        aux->ant=NULL;    // desconectar el aux por la izquierda EL ORDEN IMPORTA
        aux->sigui=NULL; // desconectar el aux por la derecha
        free(aux);
    }
}

Nodo *buscar_elemento(ListaCD *lista, Nodo *nodo){
    Nodo *aux;
    aux=lista->cabeza;
    if(listaisEmpty(lista)==1){  // Verificando si la lista esta vacia
        while(aux->datos->id!=nodo->datos->id){ // Si son diferentes los elementos; el inicial y el que me pide
            if(aux->sigui==lista->cabeza){ /// Si el siguiente apunta a NULLO significa que es la cola
                printf ("El elemento con ID %d, no se encuentra",nodo->datos->id); // Por lo que no se encontro
                break;
                }
            else{
                aux=aux->sigui; // Pasar al siguiente elemento de la lista
            }  
        }
        printf ("El elemento con ID %d, si esta en la lista",nodo->datos->id); // Por lo que se encuentra el elemento
        return aux; // retorna el elemento que se encontro
    }
    else{
        printf("La lista se encuentra vacía no se puede imprimir nada buscar elemento\n\n"); //Esta vacia la pila ya que no entró al if
        return NULL;
    }
}  


void quitar_enmedio(ListaCD *lista, Nodo *elemento){
    Nodo *nodo;
    Nodo *borrar;
    if(listaisEmpty(lista)==0){ // verificar si la lista esta vacia
        printf ("La lista se encuentra vacia, no se puede eliminar nada quitar enmedio\n\n");
        system("pause");
    }
    if(lista->cabeza==lista->cola){ //caso en el que solo hay un elemento
        quitar_cabeza(lista);
    }
    else{
        borrar=buscar_elemento(lista, elemento); // si no se encuentra vacia entonces buscar el elemento que se quiere borrar
        if (borrar==NULL){  // verificando si se encuentra
            printf("No se encontro el elemento o la lista esta vacia\n\n");
        }
        else{
            if(lista->cabeza==borrar){ // si el elemento que se quiere borrar esta en la cabeza
            quitar_cabeza(lista); // quitamos la cabeza
            }
            else if(lista->cola==borrar){
                quitar_cola(lista);
            }
            else{                   // en caso de que se encuentre enmedio
                nodo=lista->cabeza;  // meter la cabeza en un nodo aux
                while(nodo->sigui!=borrar){ // verificar antes de que nodo esta el que queremos borrar
                    nodo=nodo->sigui;    // ir recorriendo la lista
                }
                nodo->sigui=borrar->sigui;   // una vez encontrado . Esto es para que mi nodo siguiente sea el borrar siguiente; osea salta el que quiero borrar 
                borrar->sigui->ant=nodo;     //Conectar el apuntador que esta despues de borrar al nodo que esta antes de borrar
                borrar->ant=NULL;            // Desconetar las flechitas de borrar
                borrar->sigui==NULL;         // Desconectar las flechitas de borrar
                free(borrar); //libero el que quiero borrar
            }
        }
    }    
}

void print_lista(ListaCD *lista){
    Nodo *aux=lista->cabeza;
    Alumno *alu;
    if(listaisEmpty(lista)==0){
        printf("La lista se encuentra vacia, no hay nada que imprimir \n\n");
    }
    else{
        alu = aux->datos;
        printf("ID: %d \n", alu->id);
        aux=aux->sigui;
        while(aux!=lista->cabeza){
            alu = aux->datos;
            printf("ID: %d \n", alu->id);
            aux=aux->sigui;
        }
    }
}

void vaciarlista(ListaCD *lista){
    Nodo *nodo=lista->cabeza;
    if(listaisEmpty(lista)==0){
        printf("La lista se encuentra sin nada no se puede vaciar\n\n");
    }
    else{
        while(nodo!=lista->cola){
            nodo=nodo->sigui;
            quitar_cabeza(lista);
          //  printf("asdas");
        }
        quitar_cola(lista);
    }
}

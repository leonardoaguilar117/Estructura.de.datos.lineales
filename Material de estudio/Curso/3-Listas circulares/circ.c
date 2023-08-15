// Integrantes Alejandro Chavez Flores y Rodolfo Andre Ortega Garcia 
#include <stdio.h>
#include <stdlib.h>
#include "circ.h"
#include <string.h>

Alumno *crear_alumno(char nombre[35],int matricula,int edad){
     Alumno *aux=(Alumno*)malloc(sizeof(Alumno));
     strcpy(aux->nombre,nombre);
     aux->edad=edad;
     aux->matricula=matricula;
     return aux;
}

Nodo *crear_nodo(Alumno *alumno){
     Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
     aux->datos=alumno;
     aux->Siguiente=NULL;
     return (aux);
}

ListaCircular *crear_Lista(){
     ListaCircular *aux=(ListaCircular*)malloc(sizeof(ListaCircular));
     aux->cabeza=NULL;
     aux->cola=NULL;
     return(aux);
}

int listaisEmpty(ListaCircular *lista){
    if(lista->cabeza==NULL){
        return 0;
    } 
    else{
        return 1;
    }
}

void insertar_cabeza(ListaCircular *lista,Nodo *nodo){
    if(listaisEmpty(lista)==0){ // verificar si la lista esta vacia 
        lista->cabeza=nodo; // si esta vacia insertar un nodo en la cabeza
        lista->cola=nodo;   // como nodo tendra dos apuntadores los dos seran el nodo que llego
        lista->cola->Siguiente=nodo;
    }
    else{                         // si no esta vacia 
        nodo->Siguiente=lista->cabeza;
        lista->cabeza=nodo; 
        lista->cola->Siguiente=lista->cabeza;  // el último noddo de la lista apuntara al nodo que llego
              // movemos el apuntador de lista cabeza    
    }
}

void print_lista(ListaCircular *lista){
    Nodo *aux=lista->cabeza;
    Alumno *alu;

    if(listaisEmpty(lista)==1){
        while(aux != lista->cola){
            alu = aux ->datos;
            printf("%s \n",alu->nombre);
            printf("%u \n",alu->matricula);
            printf("%d \n",alu->edad);
            aux = aux ->Siguiente;
        }
        alu = lista->cola->datos;
    }else{
        printf("La lista esta vacia");
        
    }
   
}

void insertar_cola(ListaCircular *lista,Nodo *nodo){ 
    if(listaisEmpty(lista)==0){ // verificar si la lista esta vacia
        insertar_cabeza(lista,nodo); // si esta vacia se inserta el nodo
    }
    else{
        lista->cola->Siguiente=nodo; //apuntar de la cola al nodo que llego
        nodo->Siguiente=lista->cabeza;  // apuntar del nodo siguiente a la lista cabeza para que sea circular
        lista->cola=nodo;          
    }
}

void insertar_enmedio(ListaCircular *lista,Nodo *ant, Nodo *nodo){
    if(listaisEmpty==0){
        insertar_cabeza(lista,nodo);
    }
    else if(lista->cabeza==lista->cola){
        insertar_cola(lista,nodo);
    }
    else{
        nodo->Siguiente=ant->Siguiente; //El nodo sig va a apuntar lo que apuntaba ant sig
        ant->Siguiente=nodo;  // ant sig ahora apuntara al nuevo nodo a introducir 
    }
}

void quitar_cabeza(ListaCircular *lista){
    Nodo *nodo;
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
            
            nodo=lista->cabeza;  // meter la cabeza en un nodo aux
            lista->cabeza=lista->cabeza->Siguiente; //cambiar la cabeza de posicion
            lista->cola->Siguiente=lista->cabeza; // cambiar de apuntador el sig de la cola ya que se quito la cabeza
            nodo->Siguiente=NULL;     // poner el apuntador siguiente de la anterior cabeza en NULL
        }      
    }
    free(nodo);
}

void quitar_cola(ListaCircular *lista){
    Nodo *aux;
    if(listaisEmpty(lista)==0){  
        printf("La lista se encuentra vacia no puedo quitar la cola\n");
    }
    else if(lista->cabeza==lista->cola){
        quitar_cabeza(lista);
    }
    else{
        aux=lista->cabeza;
        while(aux->Siguiente!=lista->cola){
          aux=aux->Siguiente;
        }
        lista->cola=aux;  // la lista cola ahora sera el aux
        aux=aux->Siguiente;   // aux ahora sera aux sig
        lista->cola->Siguiente=lista->cabeza; //lista cola siguinte ahora apuntara a la cabeza 
        aux->Siguiente=NULL; // aux siguiente sera nullo
        free(aux);
    }
}


void vaciarlista(ListaCircular *lista){
    Nodo *nodo=lista->cabeza;
    if(listaisEmpty(lista)==0){
        printf("La lista se encuentra sin nada no se puede vaciar\n\n");
    }
    else{
        while(nodo!=lista->cola){
            nodo=nodo->Siguiente;
            quitar_cabeza(lista);
        }
        quitar_cola(lista);
    }
    free(nodo);
}


int buscar_elemento(ListaCircular *lista, int matricula){
    Nodo *aux;
    aux=lista->cabeza;
    if(listaisEmpty(lista)==1){  // Verificando si la lista esta vacia
        while(aux->datos->matricula!=matricula){ // Si son diferentes los elementos; el inicial y el que me pide
            if(aux->Siguiente==lista->cabeza){ /// Si el siguiente apunta a NULLO significa que es la cola
                printf ("La matricula %u no se encuentra\n",matricula); // Por lo que no se encontro
                break;
                }
            else{
                aux=aux->Siguiente; // Pasar al siguiente elemento de la lista
            }  
        }
        printf ("La matricula %u si se encuentra\n",matricula); // Por lo que se encuentra el elemento
        return matricula; // retorna el elemento que se encontro
    }
    else{
        printf("La lista se encuentra vacía no se puede imprimir nada buscar elemento\n\n"); //Esta vacia la pila ya que no entró al if
    }
}  

Nodo *buscar_elementoP(ListaCircular *lista, Nodo *nodoAbuscar){
    Nodo *aux;
    aux=lista->cabeza;
    if(listaisEmpty(lista)==1){  // Verificando si la lista esta vacia
        while(aux->datos->matricula!=nodoAbuscar->datos->matricula){ // Si son diferentes los elementos; el inicial y el que me pide
            if(aux->Siguiente==lista->cabeza){ /// Si el siguiente apunta a NULLO significa que es la cola
                printf ("La matricula %u no se encuentra\n",nodoAbuscar->datos->matricula); // Por lo que no se encontro
                break;
                }
            else{
                aux=aux->Siguiente; // Pasar al siguiente elemento de la lista
            }  
        }
        printf ("La matricula %u si se encuentra\n",nodoAbuscar->datos->matricula); // Por lo que se encuentra el elemento
        return aux; // retorna el elemento que se encontro
    }
    else{
        printf("La lista se encuentra vacía no se puede imprimir nada buscar elemento\n\n"); //Esta vacia la pila ya que no entró al if
        return NULL;
    }
} 

void quitar_enmedio(ListaCircular *lista, Nodo *elemento){
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
        borrar=buscar_elementoP(lista, elemento); // si no se encuentra vacia entonces buscar el elemento que se quiere borrar
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
                while(nodo->Siguiente!=borrar){ // verificar antes de que nodo esta el que queremos borrar
                    nodo=nodo->Siguiente;    // ir recorriendo la lista
                }
                nodo->Siguiente=borrar->Siguiente;   // una vez encontrado . Esto es para que mi nodo siguiente sea el borrar siguiente; osea salta el que quiero borrar 
                borrar->Siguiente==NULL;
                free(borrar); //libero el que quiero borrar
            }
        }
    }    
}


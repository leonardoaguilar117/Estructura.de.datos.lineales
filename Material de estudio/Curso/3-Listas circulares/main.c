#include <stdio.h>
#include <stdlib.h>
#include "circ.c"

int main(){
    ListaCircular *lista = crear_Lista();
    Nodo *aux = crear_nodo(crear_alumno(" ",0,0));
    insertar_cabeza(lista,aux);


    Nodo *aux1 = crear_nodo(crear_alumno("Nombre 1",2203025005,33));
    Nodo *aux2 = crear_nodo(crear_alumno("Nombre 2",220302566,33));
    Nodo *aux3 = crear_nodo(crear_alumno("Nombre 3",22030256,33));
    Nodo *aux4 = crear_nodo(crear_alumno("Nombre 4",220302505,33));
   
    
    insertar_cabeza(lista,aux1);
    insertar_cabeza(lista,aux2);
    insertar_cabeza(lista,aux3);
    insertar_cabeza(lista,aux4);

    quitar_enmedio(lista,aux2);
    print_lista(lista);




    return 0;
}
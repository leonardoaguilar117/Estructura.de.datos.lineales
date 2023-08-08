#include <stdio.h>
#include <stdlib.h>
#include "listadobcir.c"

int main(){

    ListaCD *lista = crear_Lista();
    Nodo *nodo1 = crear_nodo(crear_alumno(1,"AAA",2));
    Nodo *nodo2 = crear_nodo(crear_alumno(2,"BBB",2));
    Nodo *nodo3 = crear_nodo(crear_alumno(3,"CCC",2));

    insertar_cabeza(lista, nodo1);
    insertar_cabeza(lista, nodo2);
    insertar_enmedio(lista, nodo1, nodo3);
    //quitar_cabeza(lista);
    //quitar_cola(lista);
    //buscar_elemento(lista,nodo1);
    //quitar_enmedio(lista,nodo3);
    vaciarlista(lista);
    print_lista(lista);
    return 0;
}
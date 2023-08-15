#include <stdlib.h>
#include <stdio.h>
#include "listad.c"

int main(){

    ListaD *listaDoble = crear_ListaD();
    Nodo *primero = crear_Nodo(crear_Alumno(777,"Nombre",11));
    insertar_cabeza(listaDoble,primero);
    insertar_cola(listaDoble, crear_Nodo(crear_Alumno(666,"Angel",33)));
    insertar_enmedio(listaDoble,primero,crear_Nodo(crear_Alumno(111,"Metatron",888)));

    
    printLista(listaDoble);
    isEmpty(listaDoble);


    return 0;
}   
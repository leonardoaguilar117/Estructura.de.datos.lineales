#include <stdlib.h>
#include <stdio.h>
#include "Funciones.c"

int main(){
    
    ListaCompleta *listaPrueba = crearLista();
    insertar_cabeza(listaPrueba, crear_Nodo(crearTarea("Tarea 1",30)));

    Nodo *nuevoNodo = crear_Nodo(crearTarea("Tarea 2",45));
    insertar_cola(listaPrueba,nuevoNodo);

    Nodo *nuevoNodo1 = crear_Nodo(crearTarea("Tarea 3",45));
    insertar_cola(listaPrueba,nuevoNodo1);

    Nodo *nodoMedio = crear_Nodo(crearTarea("Tarea 2.5",67));
    insertar_en_medio(listaPrueba,nuevoNodo,nodoMedio);
    
    /*Se crea puntero llamado Lista prueba que almacena la creación de una lista, seguido de ello
      al ser funciones que requieren parametros se puede anidar una dentro de otra, respetando la 
      jerarquía de cada una: Crear Tarea -> Crear Nodo ->znsertar en la cabeza dicho nodo;
    */
    
    buscaElemento(listaPrueba,nodoMedio);
    quitar_enmedio(listaPrueba,nodoMedio);
    printLista(listaPrueba);
    
    return 0; 
}




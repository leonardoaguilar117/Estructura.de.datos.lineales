/*main de la lista doble circular main_listaDC.c*/

//typedef int TipoDato;
#include "listadobcir.c"
#include <stdio.h>
#include <stdlib.h>


int main(){
    Lista *p;
    Nodo *aux, *aux2;

    p=crear_Lista();
    vaciarlista(p);
    
    quitar_cabeza(p);
    
    insertar_cabeza(p,crear_nodo(crear_numero(25))); //Probada
    insertar_cabeza(p,crear_nodo(crear_numero(24))); 
    aux2=crear_nodo(crear_numero(23));   
    insertar_cabeza(p,aux2); 
    print_lista(p);
    insertar_cola(p,crear_nodo(crear_numero(21))); //Probada
    printf("\n\n");
    print_lista(p);
   
    ///aux2=crear_nodo(crear_numero(24));
    //aux2=crear_Nodo(crear_Alumno(7,"alvarez",24));  
    //aux=buscar_elemento(p, aux2);                 //Probada

    //quitar_enmedio(p, aux);                       //Probada
    ///printf("\n\n");
    //print_lista(p);

    insertar_enmedio(p, aux2, crear_nodo(crear_numero(28)));//Probada
    printf("\n\n");
    print_lista(p);                                   // Probada
    //system("pause");
    quitar_cabeza(p); // Probada
    printf("\n\n");
    print_lista(p);

    quitar_cola(p); // Probada
     printf("\n\n");
    print_lista(p);
    system("pause");

    vaciarlista(p); // Probada
    printf("\n\n");
    print_lista(p);
    //printLista(p);

    //aux2=crear_Nodo(crear_Alumno(4,"rojo",24));
    //aux=buscaElemento(p, aux2);
    //insertar_enmedioD(p, aux, crear_Nodo(crear_Alumno(7,"torres",28)));
    //printLista(p);

    
    ///insertar_cabeza(p,crear_Nodo(crear_Alumno(7,"Tami",25)));
    ///insertar_cabeza(p,crear_Nodo(crear_Alumno(8,"Wiwi",25)));
    ///insertar_cabeza(p,crear_Nodo(crear_Alumno(9,"Waya",25)));
   
    ///printLista(p);

   /// quitar_cabeza(p);
    ///quitar_cola(p);
    ///printLista(p);
    
   /// vaciarListaR(p);
    ///printLista(p);
    ///vaciarLista(p);
    ///printLista(p);

    //free(p);
    //free(aux);
    //free(aux2);
    system ("pause");
    return(0);
}
#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"
PilaCompleta *pilaPrincipal;
PilaCompleta *pilaPares;
PilaCompleta *pilaImpar;

int main(){
    pilaPrincipal = crear_Pila();
    pilaPares = crear_Pila();
    pilaImpar = crear_Pila();
    int dato;
 
    do{
        printf("Introduce un numero entre 1 y 50: ");
        scanf("%d",&dato);
        Nodo *num = crear_Nodo(crearNumero(dato));

        if(dato>=1 && dato <=50){
            push(pilaPrincipal,num);
        }else{
            printf("Introduce un numero dentro del rango\n");
            }
    }while(dato != 0);

    printPila(pilaPrincipal);

    Nodo *aux = pilaPrincipal->cabeza;
    int numeroAux;

    do{
        Nodo *numero;
        if((aux -> atributos -> numero) % 2 == 0){
            numeroAux = aux->atributos->numero;
            numero = crear_Nodo(crearNumero(numeroAux));
            push(pilaPares,numero);
        }else{
            numeroAux = aux->atributos->numero;
            numero = crear_Nodo(crearNumero(numeroAux));
            push(pilaImpar,numero);
        }
        aux=aux->Siguiente;

    }while(aux != NULL);
      
    printf("\nPares: \n");
    printPila(pilaPares);
    printf("\n\n");

    printf("Impares: \n");
    printPila(pilaImpar);
    printf("\n\n");
   
    return 0;    
}
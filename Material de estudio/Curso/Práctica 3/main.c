/*LEONARDO AGUILAR MARTINEZ 2203025005*/
#include <stdio.h>
#include <stdlib.h>
//#include "funcionesCola.c"
#include "funcionesPila.c"

//Se definen tres pilas: la que recopila los primeros datos, la que guardará los pares y otra los impares
PilaCompleta *pilaPrincipal;
PilaCompleta *pilaPares;
PilaCompleta *pilaImpar;

int main(){ 

    pilaPrincipal = crear_Pila();
    pilaPares = crear_Pila();
    pilaImpar = crear_Pila();
    int dato;

    /*Se introducen los numeros con la condición que sean entre 1 a 50, de lo contrario
      se manda un mensaje para informar que no es valido.
      Si la condición se cumple, se hace un push de ese numero a la pila principal
      */

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

    /*Una vez llenada la pila principal, se recorrerá esta pila para encontrar los numeros
      pares e impares, en este caso, la lógica es la siguiente:

      Si el numero es par{
        el numero que almacena el nodo se lo asignamos a un nodo auxiliar
        se introduce ese nodo auxiliar a la pila de pares
      }de lo contrario{
        el numero que almacena el nodo se lo asignamos a un nodo auxiliar
        se intruduce ese nodo auxiliar a la pila de impares
      }
      */

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
        aux=aux->Siguiente; //Iterador entre nodos

    }while(aux != NULL);
      
    /*Se imprime la pila de pares e impares*/
    printf("\nPares: \n");
    printPila(pilaPares);
    printf("\n\n");

    printf("Impares: \n");
    printPila(pilaImpar);
    printf("\n\n\n\n\n\n\n\n");






    return 0;
}
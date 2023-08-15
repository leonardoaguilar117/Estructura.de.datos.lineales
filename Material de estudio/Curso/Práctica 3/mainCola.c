/*LEONARDO AGUILAR MARTINEZ 2203025005*/
#include <stdlib.h>
#include <stdio.h>
#include "funcionesCola.c"

/*Se inicializan de forma global las colas principal y ordenados*/
ColaCompleta *colaPrincipal;
ColaCompleta *colaOrdenados;

int main(){
    /*Se utilizan 2 iteradores para los ciclos do while */
    colaPrincipal = crearCola();
    colaOrdenados = crearCola();
    int dato1=10,num,i=0,j=10;
    
    /*Se solicitan los numeros y se rellena la cola principal 10 veces */

   do{ 
        printf("Introduzca un numero para insertar en cola: ");
        scanf("%d",&num);
        Nodo *num1 = crearNodo(crear_Numero(num));
        encolar(colaPrincipal,num1);
        dato1--;
   }while(dato1!=0);
    
   printCola(colaPrincipal);
   

   Nodo *mayAux = colaPrincipal -> cabeza;
   Numero *numAux = mayAux ->atributos;
   int mayor;
   mayor = numAux->numero;

    do{
        /*Se aplica el algoritmo para encontrar el numero mayor dentro de la lista*/
        do{
        if(mayAux->atributos->numero > mayor){
            mayor = mayAux->atributos->numero;
        }
        mayAux = mayAux -> Siguiente;
        i++;
        }while(i!=10);
    
        printf("El mayor es: %d \n",mayor);
        
        Nodo *num2 = crearNodo(crear_Numero(mayor));
        encolar(colaOrdenados,num2); //El numero se inserta dentro de la cola de ordenados
        j--;
    }while(j!=0);
    printCola(colaOrdenados); //Se imprime la cola de ordenados 
    return 0; 
}
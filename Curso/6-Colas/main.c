#include <stdlib.h>
#include <stdio.h>
#include "funcionesCola.c"
ColaCompleta *colaPrincipal;
ColaCompleta *colaOrdenados;

int main(){

    colaPrincipal = crearCola();
    colaOrdenados = crearCola();
    int dato1=10,num,i=0,j=10;

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
        do{
        if(mayAux->atributos->numero > mayor){
            mayor = mayAux->atributos->numero;
        }
        mayAux = mayAux -> Siguiente;
        i++;
        }while(i!=10);
    
        printf("El mayor es: %d \n",mayor);
        
        Nodo *num2 = crearNodo(crear_Numero(mayor));
        encolar(colaOrdenados,num2);
        j--;
    }while(j!=0);
    printCola(colaOrdenados);
    return 0; 
}
#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

void newPila(Pila *pila){
    pila->cima=-1;
}

int isFull(Pila pila){
    if(pila.cima==TAMPILA-1){
        printf("La pila esta llena");
        return(1);
    }else{
        printf("La pila aun no esta llena");
        return(0);
    }
}

int isEmpty(Pila pila){
    if(pila.cima==-1){
        printf("La pila esta vacia");
        return 1;
    }else{
        printf("La pila no esta vacia");
        return 0;
    }
    
}

void push(Pila *pila,TipoDato elemento){
    if(isFull(*pila)==1){
        printf("Desbordamiento de pila, no se puede insertar");
        exit(1);
    }else{
        pila->cima++;
        pila->listaPila[pila->cima]=elemento;
    }
}

TipoDato pop(Pila *pila){
    TipoDato elemento;
    if(isEmpty(*pila)==1){
        printf("La pila esta vacia, no es posible eliminar nada");
        exit(1);
    }else{
        elemento=pila->listaPila[pila->cima];
        printf("El elemento eliminado es: %d",elemento);
        pila->cima--;
        return elemento;
    }
}

TipoDato cima(Pila pila){
    if(isEmpty(pila)==1){
        printf("Error de ejecucion, pila vacia");
        exit(1);
    }else{
        printf("El elemento de la cima es: %d",pila.listaPila[pila.cima]);
        return (pila.listaPila[pila.cima]);
    }
}

int count(Pila pila){
    if(isEmpty(pila)==1){
        printf("Error de ejecucion, pila vacia");
        return 0;
    }else{
        printf("La pila tiene %d elementos",pila.cima+1);
        return(pila.cima+1);
    }
}

void clear(Pila *pila){
    pila->cima=-1;
    printf("Pila limpia");
}

int tamMax(){
    printf("Esta pila almacena un maximo de: %d elementos",TAMPILA);
    return(TAMPILA);
}

void printPila(Pila pila){
    if(isEmpty(pila)==1){
        printf("Error de ejecución, pila vacia");
    }else{
        for(int i=pila.cima;i>-1;i--){
            printf("Elemento %d: %d", i, pila.listaPila[i]);
        }
    }
}










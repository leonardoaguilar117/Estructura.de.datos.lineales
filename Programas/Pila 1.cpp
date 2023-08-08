#include<stdio.h>
#include<stdlib.h>
/*  PILAS:
	1er paso - Crear espacio en memoria para almacenar un nodo
	2do paso -   
*/

//Estructura de tipo Nodo con un dato y un apuntador al siguiente nodo 
struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&pila, int n); //Prototipo 1

int main(){
	Nodo *pila = NULL; 
	int x,y;
	
	printf("Digite un numero: ");
	scanf("%d",&x);
	agregarPila(pila,x);
	
	printf("Digite un segundo numero: ");
	scanf("%d",&y);
	agregarPila(pila,y);
	
	return 0;
}

void agregarPila(Nodo *&pila, int n){
	Nodo *nuevoNodo;
	nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo)); //1
	nuevoNodo->dato=n;                                     //2
	nuevoNodo->siguiente=pila;							   //3
    pila = nuevoNodo;									   //4
    printf("El elemento %d ha sido agregado a PILA",n);
}



































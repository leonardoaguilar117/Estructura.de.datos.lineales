#include<stdio.h>
#include<stdlib.h>
/* Crear un libro que contenga todas sus caracteristicas, los
   datos de este se almacenen de forma dinamica y al final te 
   de la opcion de mostrar cada elemento del libro a través de
   un menú 
*/

struct libro{
	char nombre[30];
	char autor[30];
	int numeroPag;
	float precio;
};

void infoLibro(struct libro *p);

int main(){
	int x;
	struct libro *libroApuntado;
	libroApuntado = (struct libro*)calloc(4,sizeof(struct libro));
	
	printf("Titulo del libro: ");
	scanf("%s",&libroApuntado->nombre);
	
	printf("Autor:  ");
	scanf("%s",&libroApuntado->autor);
	
	printf("Numero de paginas:  ");
	scanf("%u",&libroApuntado->numeroPag);
	
	printf("Precio: ");
	scanf("%u",&libroApuntado->precio);
	
		
	do{
		printf("Que desea seleccionar del menú%c \n",63);
		printf("1-Mostrar nombre del libro: \n");
		printf("2-Mostrar autor del libro: \n");
		printf("3-Mostrar numero de páginas: \n");
		printf("4-Mostrar precio del libro:    \n");
		printf("5-Mostrar todo: \n");
		printf("0-Salir del menú\n");
		scanf("%d",&x);
		fflush(stdin);
		
		switch(x){
			case 1: printf("%s",libroApuntado->nombre);
			break;
			
			case 2: printf("%s",libroApuntado->autor);
			break;
			
			case 3: printf("%u",libroApuntado->numeroPag);
			break;
			
			case 4: printf("%f",libroApuntado->precio);
			break;
			
			case 5: infoLibro(libroApuntado);
			break;
			
			default:
				printf("Digite una opción valida: ");
			break;
		}
	}while(x!=0);
	
	return 0; 
}

void infoLibro(struct libro *p){
	printf("Nombre: %s \n Autor: %s \n Numero de paginas: %u \n  Precio: %u \n ",p->nombre,p->autor,p->numeroPag,p->precio);
}


























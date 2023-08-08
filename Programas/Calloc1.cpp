#include<stdlib.h>
#include<stdio.h>

/* CALLOC sirve para solicitar un bloque de memoria con un tamaño el cual es expresado
   en bytes 
   El retorno de esta funcion es un puntero de tipo void, en caso de que no se cuente con
   la memoria, se retorna NULL
   Esta funcion es muy similar a MALLOC con la diferencia que inicializa los espacios de
   memoria con un valor de 0 
   malloc[$,%,+,ñ] *valores que no fueron borrados con anterioridad 
   calloc[0,0,0,0]
*/

int main(){
	int num=0, x,*vector,i,k;
	
	printf("Ingrese la cantidad de valores a cargar: ");
	scanf("%d",&num);
	
	//Verificacion de dato
	if(num <=0){
		printf("Ingrese un valor mayor a 0");
		exit(1);
	}	
	
	//Obtención de memoria y almacenamiento en puntero
	vector = (int*)calloc(num,sizeof(int));
	
	//Verificación de memoria
	if(vector == NULL){
		printf("No es posible almacenar ");
		exit(1);
	}else{
		printf("Existe espacio!");	
	}
	
	//Introducción de datos al vector
	for(i=0;i<num;i++){
		printf("Dato %d: ",i+1);
		scanf("%d",&vector[i]);
	}
	//Mostrar datos 
	for(k=0;k<num;k++){
		printf("%d",vector[k]);
	}
	
	free(vector);
	return 0;
}























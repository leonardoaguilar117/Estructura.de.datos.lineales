#include<stdio.h>
/*Rellenar un array con 10 digitos e indicar con punteros cuales son numeros pares
  y sus direcciones en memoria 
*/
int main(){
	int i,j,array[10],*direccion;
	
	for(i=0;i<10;i++){
		printf("Digite un numero: ");
		scanf("%d",&array[i]);
	}
	
	for(j=0;j<10;j++){
		direccion = &array[j];
		if(*direccion%2==0){
			printf("El numero %d es par y su direccion de memoria es: %d\n",*direccion,direccion);
			
		}else{
			printf("El numero %d no es par y su direccin de memoria es: %d\n",*direccion,direccion);
		}
	}
	
	return 0;
}
























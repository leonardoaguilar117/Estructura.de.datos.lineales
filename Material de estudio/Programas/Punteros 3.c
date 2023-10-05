#include<stdio.h>
//Correspondecia entre arrays y punteros
int main(){
	int numeros[]={1,2,3,4,5}; 
	int *puntero,i;
	
	for(i =0;i<5;i++){
		puntero = &numeros[i];
		printf("Numero: %d y Direccion de memoria: %d \n",*puntero,puntero);
	}
	 
	return 0; 
}





























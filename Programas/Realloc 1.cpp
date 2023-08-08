#include<stdio.h>
#include<stdlib.h>
/*REALLOC: La función realloc redimensiona el espacio asignado de forma dinámica anteriormente a un puntero.
  Tiene la siguiente definición:
  void *realloc(void *ptr, size_t size); 
*/

//prototipos de funciones 
void pedirDatos(int *V,int N);
void mostrarDatos(int*V,int N);

int main(){
	/*V almacena la memoria almacenar
	 *N almacena la cantidad de elementos del vector o arreglo
	 *VNew almacena el proximo espacio de memoria (ya sea una ampliación o una reducción) 
	*/
	int *V,N,*VNew;
	
	printf("Cuantos elementos desea almacenar%c: ",63);
	scanf("%d",&N);
	//se reserva memoria en el puntero V
	V = (int*)calloc(N,sizeof(int));
	
	//Condicional para verificar si la memoria 
	if(V!=NULL){
		pedirDatos(V,N);
		mostrarDatos(V,N);
	}else{
		printf("No existe memoria suficiente para realizar el proceso: ");
		exit(1);
	}
	free(V);
	
	//Uso de realloc para dar mas espacio al vector 
	printf("Cuantos elementos tendra el nuevo vector%c",63);
	scanf("%d",&N);
	
	VNew = (int*)realloc(V,N);
	//Condicional y ejecucion de las funciones 
	if(VNew !=NULL){
		pedirDatos(V,N);
		mostrarDatos(V,N);
	}else{
		printf("No existe memoria para realizar el proceso! ");
	}
	
	free(VNew);	
	return 0;
}

//Función pedir datos
void pedirDatos(int *V,int N){
	int i;
	for(i=0;i<N;i++){
		printf("Dato %d: \n",i+1);
		scanf("%d",&V[i]);
	}
}

//Funcion mostrar datos
void mostrarDatos(int *V,int N){
	int i;
	for(i=0;i<N;i++){
		printf("Dato %d: %d \n",i+1,V[i]);
	}
}





























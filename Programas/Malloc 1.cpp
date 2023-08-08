//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
		/*-La memoria estática tiene una duración fija, que se reserva y libera de forma automática.
		  -En la memoria dinamica se tienen que llevar a cabo varias tareas como buscar un espacio de memoria libre y 
		  almacenar la posición y tamaño de la memoria asignada
		  
		  Funcion malloc()
		  Asigna un bloque de memoria que es el numero de bytes pasados como argumento 
		  Esta funcion devuelve un puntero, que es la direccion del bloque asignado de memoria
		  (Reservar memoria de forma dinamica, sin tener que definir cuantos espacios necesitamos)  
		*/
int main(){
	
	char *MemCaracteres,cadena[100]; //Apuntador para memoria que consumen los caracteres y arreglo de caracteres [100]
	int TamCadena; 					//Variable para tamaño de cadena 
	
	//Introducir cadena
	printf("Escriba una frase: ");
	scanf("%d",&cadena);
	
	//Tamaño de la cadena igual a funcion strlen que obtiene los caracteres de cadena 
	TamCadena = strlen(cadena);
	
	//En memoria de caracteres se almacena el resultado de la funcion malloc la cual nos dice cuanto espacio
	//vamos a necesitar de forma dinamica (cantidad de caracteres * tamaño que ocupa un dato char)
	MemCaracteres =(char*) malloc((TamCadena)*sizeof(char));

	//Si la memoria es diferente de NULL significa que existe espacio para almacenar la frase
	if(MemCaracteres!=NULL){
		printf("Hay memoria disponible para almacenar %s",MemCaracteres);
		
	}else{
		printf("No hay memoria disponible para almacenar %s",MemCaracteres);	
	}
	//free libera memoria de la RAM 
	free(MemCaracteres);

	return 0;
}


































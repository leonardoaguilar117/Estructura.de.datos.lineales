#include<stdio.h>

/* Un puntero * es una variable que almacenar� la direcci�n de memoria de 	
&n = La direccion de n
*n = La variable cuya direccion est� almacenada en n 
*/

int main(){
 	int num=20,*dirNum;
 	
 	dirNum = &num; //Almacena la direcci�n de la variable
 	
//----------------------------------------------------------------------------------------------------------------------
	printf("Numero: %d\n",num);
	printf("Direccion de memoria: %p\n",&num); //Para mostrar la direccion de memoria de una variable se coloca & 
	
	printf("Numero: %d\n",*dirNum); //Un * antes de la variable puntero muesta el contenido de la variable a la que se apunta
	printf("Direccion de la memoria: %p",dirNum); //dirNum por si solo muestra unicamente la direcci�n de memoria 

	return 0;
}





































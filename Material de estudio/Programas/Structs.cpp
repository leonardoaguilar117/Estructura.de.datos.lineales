#include<stdio.h>
#include<stdlib.h>

/*Las estructuras son colecciones de variables relacionadas bajo un nombre.
Las estructuras pueden contener variables de muchos tipos diferentes de datos,
a diferencia de los arreglos que contienen unicamente elementos de un mismo
tipo de datos.
*/
struct libro{
	char titulo[30];
	char autor[30];
	int numPaginas;
	float precio;	
}toallaMoj;

//Struct anidada
struct direccion{
	char direccion[30];
	char ciudad[20];
};

struct empleado{
	char nombre[30];
	struct direccion dirEmpleado;
	double salario;
};

int main(){
	
	//Para usar un elemento de una estructura se utiliza nomEstruc.elemento
	printf("Introduce el nombre del libro: ");
	gets(toallaMoj.titulo);
	printf("Introduce el nombre del autor: ");
	gets(toallaMoj.autor);
	printf("Introduce el numero de paginas: ");
	scanf("%d",&toallaMoj.numPaginas);
	printf("Introduce el precio:  ");
	scanf("%f",&toallaMoj.precio);
	
	puts(toallaMoj.titulo);
	puts(toallaMoj.autor);
	printf("%d \n",toallaMoj.numPaginas);
	printf("%f",toallaMoj.precio);

		
	//Podemos ver el uso de structs como una analogia al uso de clases 
	//variableStruc.Struc2.variableStruc2
	empleado empleado1;
	printf("Introduzca la ciudad: ");
	gets(empleado1.dirEmpleado.ciudad);
	printf("%s",empleado1.dirEmpleado.ciudad);
	
	
	
	return 0;
}



















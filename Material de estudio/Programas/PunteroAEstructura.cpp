#include<stdio.h>
#include<stdlib.h>

//Estructura fecha con 3 parametros
struct fecha{
	unsigned int dia;
	unsigned int mes;
	unsigned int aa;
};

//Prototipo de función escribir con un puntero de tipo fecha de parametro
void escribir (struct fecha *p);

int main(){
	struct fecha *hoy; //puntero de tipo fecha 
	
	hoy = (struct fecha*)malloc(sizeof(struct fecha)); //Reserva memoria con calloc 
	//(dato tipo struct fecha)calloc(3 digitos,de tamano(struct fecha));
	
	printf("Introduce la fecha (dia-mes-ano)\n");
	printf("Introduce el dia: ");
	scanf("%u",&hoy->dia);
		
	printf("Introduce el mes ");
	scanf("%u",&hoy->mes);
	
	printf("Introduce el a�o: ");
	scanf("%u",&hoy->aa);
	
	/*Si se define un puntero en un struct este nos ayudara a ingresar los datos requeridos o bien sacarlos datos para 
	una operacion o una impresion. Por cada dato a introducir en el struct utilizamos el operador -> que se usa para acceder 
	a un miembro de una estructura al que hace referencia el puntero*/
	
	escribir(hoy);
	free(hoy);
	
	//No usar free antes de usar el puntero s
	return 0;
}

void escribir (struct fecha *p){
	printf("Dia: %d Mes: %d Ano: %d",p->dia,p->mes, p->aa);
}





















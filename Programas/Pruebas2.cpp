#include<stdio.h>

int main(){
	//Uso formal del puntero:
	int A =20, B, *P,*Q;
	
	printf("    A = 20 B=NULL, P Y Q son apuntadores:\n\n");
	Q = &A;
	printf("Q esta apuntando a la direccion %p que es de A\n",Q);
	
	B = *Q;
	printf("B contiene el valor de A=%d, ya que Q = &A\n",B);
	
	P=&B;
	printf("P es igual a la direccion de B: %p\n",P);
	
	*P=25; 
	printf("En la direccion %p esta el dato: %d\n",Q,*P);
	
	printf("---------------------------------------------------------------\n\n");
	//Operaciones con punteros 
	int T[5]={1,2,3,4,5};
	int *k;
	
	printf("K2 ap");
	
	return 0;
}





























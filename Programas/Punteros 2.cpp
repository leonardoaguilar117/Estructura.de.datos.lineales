#include<stdio.h>

int main(){
	int x,*dirNum;
	printf("Introduzca un numero: ");
	scanf("%d",&x);
	
	if(x%2 == 0){
		dirNum = &x;
		printf("El numero %d es par y su direccion es: %d",*dirNum,dirNum);
	}else{
		printf("El numero no es par");
	}
	
	
	return 0;
}






























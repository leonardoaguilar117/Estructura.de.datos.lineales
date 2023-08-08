#include <stdio.h>
#include <stdlib.h>

int main(){
    int A=10, B, *P, *Q;  

    Q=&A; //Q almacena la dirección de memoria de A
 

    B=*Q;  //B almacena el valor que guarda Q, no su dirección 
    

    *P=155; //Un * antes de la variable puntero muesta el contenido de la variable a la que se apunta


    return 0;
}
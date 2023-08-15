//Librias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <time.h>

/*-La memoria est�tica tiene una duraci�n fija, que se reserva y libera de forma autom�tica.
  -En la memoria dinamica se tienen que llevar a cabo varias tareas como buscar un espacio de memoria libre y 
  almacenar la posici�n y tama�o de la memoria asignada
  
  Funcion malloc()
  Asigna un bloque de memoria que es el numero de bytes pasados como argumento 
  Esta funcion devuelve un puntero, que es la direccion del bloque asignado de memoria
  (Reservar memoria de forma dinamica, sin tener que definir cuantos espacios necesitamos)  
*/
int main(){
    char cadena[125];
    char *cadenita;
    int tamcadenita;

    puts("\n Introduce una cadena de caracteres\n");
    gets(cadena);

    tamcadenita=strlen(cadena);//en tamcadenita estar� almacenado el valor dinamico del tama�o de la cadena
    
    //cadenita = (char*)malloc((tamcadenita+1)*sizeof(char));
    
    cadenita = (char*)malloc((tamcadenita)*sizeof(char));
    
    
    if(tamcadenita!=NULL){
        printf("\nMemoria sufiente\n");
    }
    else{
        printf("\n No hay memoria sufiente\n");
        exit;
    }
    
    strcpy(cadenita,cadena);
    printf("Cadenita: %s",cadenita);
    free(cadenita);

}




























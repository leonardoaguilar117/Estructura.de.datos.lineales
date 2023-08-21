/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include "ListaArreglos.h"

using namespace std;
int main()
{
    
    ListaArreglos listita; //1Manda llamar al constructo autmaticamente
    ListaArreglos listota; //1,2,3,4,5,5,6,7
    ListaArreglos lista; //10
    ListaArreglos listucha; //6
    
    ListaArreglos lista3;
    listita.insertar(1,listita.fin());
    listita.eliminar(0);
    int indice=listita.buscar(1);
    
    printf("Hello World");
  //Cuando se acaba el programa se manda llamar el destructor automaticamente
     return 0;
}
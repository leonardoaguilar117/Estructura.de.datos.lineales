#include<stdio.h>
#include<stdlib.h>

int main(){
	//declaramos las variables enteras A, B y los punteros P y Q a enteros*/

	int A = 10, B,  *P, *Q;
    
    Q = &A; //asigna la dirección de “A” a la variable Q, por lo que Q estaría apuntando a la variable A.
	printf("Q esta apuntando a la direccion: %p\n",Q);

    B = *Q; // Asigna a B el contenido de la dirección Q. 
    printf("B contiene lo que esta apuntando Q que es la direccion de A y A es: %d\n",B);

    P=&B; 
    printf("P esta apuntando a la direccion de B: %p\n",P);

	*P = 25; //Error, pues es una asignación a un puntero no valido. ¿A dónde apunta P?
	
    printf("En la dirección %p esta el dato: %d \n",Q,A);
	printf ("En la dirección %p esta el dato %d \n", P, *P);
    

        
    printf ("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n");
    printf ("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n");

    int T[5]={1,2,3,4,5};
    int U=666;
    int *K ; // Declaración de * como puntero a un entero
    
    K=&U;
    //K=&T;
    printf("K1 apunta a: %p \n",K);

    K =T;

    printf("K2 apunta a: %p \n",K);

    K++ ;  // Hace que P apunte al siguiente entero
    printf("K++ es: %p \n",K);
    
    K=K+1 ;  // Hace que P apunte al siguiente entero
    printf("K+1 es: %p \n",K);

    K--;  //Hace que P apunte al entero anterior
    printf("K-- es: %p \n",K);
 
    ++K ;  // Hace que P apunte al siguiente entero
    printf("++K es: %p \n",K);
    
    --K;  //Hace que P apunte al entero anterior
    printf("--K es: %p \n",K);

    K = K + 3; //Avanza 3 enteros
    printf("K+3 es: %p \n",K);

    K = K - 3;//Retrocede 3 enteros (Cuidado cuando cuando se trabaja con arrays y punteros (P-Q)
    printf("K-3 es: %p \n",K);
    
    printf ("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n");
    printf ("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n");
    
    int C=25, D=13, *PC, *PD;
    int Y[5]={1,2,3,4,5};

    printf("C es: %d \n",C);
    printf("D es: %d \n",D);
    
    PC=&C;
    PD=&D;

    printf("PC es la direccion de C y es %p: \n",PC);
    printf("PC es la direccion D y es%p: \n",PD);

    D = *PC + 1; // Al valor apuntado por PC se le suma 1, y el resultado se guarda en D
    printf("D ahora es *PC+1: %d \n",D);
   
    PC=Y;
    printf("PC es ahora la direccion %p: \n",PC);

    D = *(PC + 1); // El siguiente entero al entero apuntado por PC, es asignado a D
    printf("D ahora es *(PC+1): %d \n",D);
    
    PC = &D; // A PC se le asigna la dirección de la variable D;
    printf("PC ahora es la direccion de D: %p \n",PC);

    printf ("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n");
    printf ("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n");


    //Si suponemos que D esta apuntado por PD tenemos que:
    PD=&D;//
    printf("PD ahora es la direccion de D PD=&D: %p \n",PD);

    
    *PD = 0; //Se le da a la variable D el valor de cero
    printf("D es *PD = 0: %d \n",*PD);

    *PD  += 2; // La variable D se incrementa en dos unidades
    printf("D ahora es *PD  += 2: %d \n",*PD);

    printf("D es: %d \n",D);
    
    (*PD)--; //La variable D se decrementa en una unidad. 
    printf("D ahora es (*PD) - -: %d \n",*PD);
    printf("D1 es: %d \n",D);

    printf("Antes PD1 ahora es la direccion de D PD=&D: %p \n",PD);
    *PD++ ; // Se decrementa en una unidad a PD
    printf("PD ahora es *PD++: %p \n",PD);
    printf("D2 es: %d \n",D);
    printf("Despues PD1 ahora es la direccion de D PD=&D: %p \n",PD);

    *PD-- ; // Se decrementa en una unidad a PD
    printf("PD ahora es *PD--: %p \n",PD);
    printf("D3 es: %d \n",D);
    printf("PD2 ahora es la direccion de D PD=&D: %p \n",PD);


    
    printf("D antes es: %d \n",D);
    printf("PD antes es *PD++: %p \n",PD);
    ++*PD ; // Se decrementa en una unidad a PD
    printf("D despues es: %d \n",D);
    printf("PD despues es *PD++: %p \n",PD);
    printf("PD ahora es ++*PD: %d \n",*PD);//modifica lo q esta apuntando no la direccion o el apuntador



    printf("D antes1 es: %d \n",D);
    printf("PD antes1 es *PD++: %p \n",PD);
    --*PD ; // Se decrementa en una unidad a PD
    printf("D despues1 es: %d \n",D);
    printf("PD despues1 es *PD++: %p \n",PD);
    printf("PD ahora es --*PD: %d \n",*PD);

    return (0);
}
























//------ Tiempos de ejecucion ------- Leonardo Aguilar Martínez Valeria Perez de Celis Martinez------ 2203025005 -------//
#include <iostream>
#include "FuncionesOrden.cpp"
using namespace std;

int main(){
    int Array_A[10], Array_B[100], Array_C[1000], Array_D[10000];
    int increm = 10;
    double  proBurb[4], promInser[4], promSelec[4], promQuick[4], promMerge[4];

//----------- Array decrementado -----------//
    proBurb[0] = promedioBurbujaDec(Array_A, 10);
    proBurb[1] = promedioBurbujaDec(Array_B, 100);
    proBurb[2] = promedioBurbujaDec(Array_C, 1000);
    proBurb[3] = promedioBurbujaDec(Array_D, 10000);

    promInser[0] = promedioInsercionDec(Array_A, 10);
    promInser[1] = promedioInsercionDec(Array_B, 100);
    promInser[2] = promedioInsercionDec(Array_C, 1000);
    promInser[3] = promedioInsercionDec(Array_D, 10000);    
    
    promSelec[0] = promedioSeleccionDec(Array_A, 10);
    promSelec[1] = promedioSeleccionDec(Array_B, 100);
    promSelec[2] = promedioSeleccionDec(Array_C, 1000);
    promSelec[3] = promedioSeleccionDec(Array_D, 10000); 

    promQuick[0] = promedioQuickDec(Array_A, 10);
    promQuick[1] = promedioQuickDec(Array_B, 100);
    promQuick[2] = promedioQuickDec(Array_C, 1000);
    promQuick[3] = promedioQuickDec(Array_D, 10000);

    promMerge[0] = promedioMergeDec(Array_A, 10);
    promMerge[1] = promedioMergeDec(Array_B, 100);
    promMerge[2] = promedioMergeDec(Array_C, 1000);
    promMerge[3] = promedioMergeDec(Array_D, 10000);

    cout<<"*---------*      Prom ejec arry 10 **         Prom ejec array 100 **     Prom ejec array 1,000 **     Prom ejec array 10,000**"<<endl;
    cout<<"* Burbuja *         "<< proBurb[0]<<"               "<< proBurb[1]<<"                      "<< proBurb[2]<<"                       "<< proBurb[3]<< endl;
    cout<<"* Insercion *       "<< promInser[0]<<"             "<< promInser[1]<<"                 "<< promInser[2]<<"                       "<< proBurb[3]<<endl;
    cout<<"* Seleccion *       "<< promSelec[0]<<"             "<< promSelec[1]<<"                 "<< promSelec[2]<<"                       "<< promSelec[3]<<endl;
    cout<<"* QuickSort *       "<< promQuick[0]<<"             "<< promQuick[1]<<"                 "<< promQuick[2]<<"                       "<< promQuick[3]<<endl;
    cout<<"* MergeSort *       "<< promMerge[0]<<"             "<< promMerge[1]<<"                 "<< promMerge[2]<<"                       "<< promMerge[3];       
}
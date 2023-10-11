#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

double tiempoEjecucion(unsigned t0, unsigned t1){
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    return time;
}

void imprimirArray(int array[], int tam){
    for(int i=0; i<tam; i++){
        cout<<array[i]<<endl;
    }
}
void rellenarArrayRAND(int array[], int tam){
    int a = 0;
    for(int i = 0; i<tam; i++){
        a = rand() % 100;
        array[i] = a;
    }
}

int* bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar arr[j] y arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int * insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;

        // Mover los elementos mayores que la clave a la derecha
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Colocar la clave en su posición correcta
        arr[j + 1] = clave;
    }
    return arr;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;

        // Buscar el índice del elemento más pequeño en la parte desordenada
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Intercambiar el elemento más pequeño con el primer elemento de la parte desordenada
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

//--------------- Quick sort y merge sort--------------//
void combinar(int A[], int inicio, int medio, int fin) {
    int aux[fin - inicio + 1];
    int i = inicio;    
    int j = medio + 1; 
    int h = 0;

    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }


    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } 
    else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }
   
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
}

void mergeSort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergeSort(A, inicio, medio);
        mergeSort(A, medio + 1, fin);
        combinar(A, inicio, medio, fin);
    }
}

void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

int particionar(int A[], int p, int r) {
    int pivote = A[r];
    int ultimo = p - 1;

    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = particionar(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

//-----    Funciones para obtención de promedio ------------//
double promedioBurbuja(int array[], int TAM){
    unsigned t1, t0;
    double tiempo;
    rellenarArrayRAND(array, TAM);

    for(int i = 0; i<10; i++){
        t0 = clock();
        bubbleSort(array, TAM);
        t1 = clock();
        tiempo += (double(t1-t0)/CLOCKS_PER_SEC); 
        rellenarArrayRAND(array, TAM);
    }

    return (tiempo / 10);
}

double promedioInsercion(int array[], int TAM){
    unsigned t1, t0;
    double tiempo;
    rellenarArrayRAND(array, TAM);

    for(int i = 0; i<10; i++){
        t0 = clock();
        insertionSort(array, TAM);
        t1 = clock();
        tiempo += (double(t1-t0)/CLOCKS_PER_SEC); 
        rellenarArrayRAND(array, TAM);
    }
    return (tiempo / 10);
}

double promedioSeleccion(int array[], int TAM){
    unsigned t1, t0;
    double tiempo;
    rellenarArrayRAND(array, TAM);

    for(int i = 0; i<10; i++){
        t0 = clock();
        selectionSort(array, TAM);
        t1 = clock();
        tiempo += (double(t1-t0)/CLOCKS_PER_SEC); 
        rellenarArrayRAND(array, TAM);
    }
    return (tiempo / 10);
}

double promedioQuick(int array[], int TAM){
    unsigned t1, t0;
    double tiempo;
    rellenarArrayRAND(array, TAM);

    for(int i = 0; i<10; i++){
        t0 = clock();
        quickSort(array, 0,TAM);
        t1 = clock();
        tiempo += (double(t1-t0)/CLOCKS_PER_SEC); 
        rellenarArrayRAND(array, TAM);
    }
    return (tiempo / 10);
}

double promedioMerge(int array[], int TAM){
    unsigned t1, t0;
    double tiempo;
    rellenarArrayRAND(array, TAM);

    for(int i = 0; i<10; i++){
        t0 = clock();
        mergeSort(array, 0, TAM);
        t1 = clock();
        tiempo += (double(t1-t0)/CLOCKS_PER_SEC); 
        rellenarArrayRAND(array, TAM);
    }
    return (tiempo / 10);
}

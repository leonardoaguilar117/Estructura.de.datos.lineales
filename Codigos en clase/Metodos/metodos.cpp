#include<iostream>
#include <cstdlib>


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

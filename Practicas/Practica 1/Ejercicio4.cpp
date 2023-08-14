#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Se crea la funci�n que desde un arreglo permuta aleatoriamente 

void permut_aleat(int arr[], int size) {

// Se da la semilla para crear n�meros aleatorios
    srand(time(0)); 

// Se crea el bucle que toma el tama�o del arreglo para despues
// generar aleatorimanete la selecci�n de elementos a intercambiar

    for (int i=size-1; i>0; --i) {
        int j=rand() % (i+1);   
        swap(arr[i], arr[j]);      
    }
}


// Se crea la funci�n que intercambia los elementos (swap)
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


// Desde el principal, se ingresaron valores del 1 al 10 para probar las funciones.
// El tama�o del arreglo lo toma autom�ticamente de los valores entregados.

int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(values) / sizeof(values[0]);

    cout << "Arreglo original: " << endl;
    for (int i=0; i<size; ++i) {
        cout << values[i] << " ";
    }
    cout << endl;

    permut_aleat(values, size);

    cout << "Arreglo permutado aleatoriamente: " << endl;
    for (int i=0; i<size; ++i) {
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}

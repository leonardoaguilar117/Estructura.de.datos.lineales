#include <iostream>
using namespace std;


// Se crea una función que mida si el valor del número
// de elementos es los suficientemente grande para poder
// tener elementos que obtengan un producto igual a 10.

void enc_par_produc10(const int arr[], int size) {
    if (size < 2) {
        cout << "El arreglo es demasiado pequeño para encontrar parejas." << endl;
        return;
    }

    cout << "Parejas con producto igual a 10:" << endl;
    for (int i=0; i<size-1; ++i){
        if (arr[i] * arr[i + 1] == 10) {
            cout << "(" << arr[i] << ", " << arr[i + 1] << ")" << endl;
        }
    }
}

// Se crea el main donde se proporcionan los valos enteros que serán parte del arreglo.
// Elegí algunos valores menores a 10.
int main() {
    int values[] = {2, 5, 1, 2, 3, 1, 0, 4, 6, 7, 8, 9};
    int size = sizeof(values) / sizeof(values[0]);

// Se llama a la función.

    enc_par_produc10(values, size);

    return 0;
}


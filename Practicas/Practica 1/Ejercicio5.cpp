#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int renglones;
    cout << "Introduce el número de renglones: ";
    cin >> renglones;

    int num = 1;
    for (int i = 1; i <= renglones; i++) {
        // Imprimir espacios
        for (int j = renglones; j > i; j--) {
            cout << "   "; // Tres espacios son suficientes para la mayoría de los casos
        }
        // Imprimir números
        for (int j = 1; j <= i; j++) {
            cout << setw(2) << num++ << " ";
        }
        cout << endl; // Salto de línea después de cada renglón
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

#define TAM 40

class ListaArreglos {
public:
    int arreglo[TAM];
    int n; // Describe el número de elementos "reales" en la lista

public:
    ListaArreglos(); // Constructor
    ~ListaArreglos(); // Destructor
    bool insertar(int x, int p);
    bool eliminar(int p);
    int buscar(int x) const;
    int fin() const;
    int primera() const;
    int siguiente(int pos) const;
    int anterior(int pos) const;
    void hacerVacia();
    bool esVacia() const;
    string toString() const;
    int obtener(int p) const;
};

ListaArreglos::ListaArreglos() {
    n = 0;
}

ListaArreglos::~ListaArreglos() {
    // No se requiere liberación de memoria en este caso
}

int ListaArreglos::fin() const {
    return n;
}

bool ListaArreglos::insertar(int x, int p) {
    bool exito = false;

    if (p >= 0 && p <= n && n < TAM) {
        exito = true;
        for (int i = n; i >= p; i--)
            arreglo[i + 1] = arreglo[i];
        arreglo[p] = x;
        n++;
    }

    return exito;
}

bool ListaArreglos::eliminar(int p) {
    bool exito = false;
    if (p >= 0 && p < n && n < TAM) {

        exito = true;
        for (int i = p; i < n; i++) {
            arreglo[i] = arreglo[i + 1];
        }
        n--;
    }
    return exito;
}

void ListaArreglos::hacerVacia() {
    n = 0;
}

int ListaArreglos::buscar(int x) const {
    int posicion = -1;
    int i = 0;
    bool encontrado = false;

    while (i < n && !encontrado) {
        if (arreglo[i] == x) {
            posicion = i;
            encontrado = true;
        }
        i++;
    }

    return posicion;
}

int ListaArreglos::primera() const {
    return 0;
}

int ListaArreglos::siguiente(int pos) const {
    if (pos < n - 1) {
        return pos + 1;
    } else {
        return -1; // No hay siguiente
    }
}

int ListaArreglos::anterior(int pos) const {
    if (pos > 0 && pos < n) {
        return pos - 1;
    } else {
        return -1; // No hay anterior
    }
}

bool ListaArreglos::esVacia() const {
    return (n == 0);
}

string ListaArreglos::toString() const {
    string res = "";

    for (int i = 0; i < n; i++) {
        res += to_string(arreglo[i]) + " ";
    }

    return res;
}

int ListaArreglos::obtener(int p) const {
    return arreglo[p];
}
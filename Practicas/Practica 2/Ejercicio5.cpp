#include <iostream>
#include <string>

using namespace std;

#define TAM 40

class ListaArreglos {
public:
    int arreglo[TAM];
    int n; 

public:
    ListaArreglos(); // Constructor
    ~ListaArreglos(); // Destructor
    bool insertar(int x, int p);
    bool eliminar(int p);
    int fin() const;
    int siguiente(int pos) const;
    void hacerVacia();
    bool esVacia() const;
    int obtener(int p) const;
};

ListaArreglos::ListaArreglos() {
    n = 0;
}

ListaArreglos::~ListaArreglos() {
   
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

bool ListaArreglos::esVacia() const {
    return (n == 0);
}

int ListaArreglos::obtener(int p) const {
    return arreglo[p];
}

int ListaArreglos::siguiente(int pos) const {
    if (pos < n - 1) {
        return pos + 1;
    } else {
        return 0; 
    }
}

int josephus_problem(int n, int m) {
    ListaArreglos people;

   
    for (int i = 1; i <= n; ++i) {
        people.insertar(i, people.fin());
    }

    int currentPos = people.fin() - 1;

    while (!people.esVacia()) {
        currentPos = people.siguiente(currentPos);

        
        for (int i = 0; i < m - 1; ++i) {
            currentPos = people.siguiente(currentPos);
        }

        int eliminated = people.obtener(currentPos);
        cout << "Eliminado: " << eliminated << endl;
        people.eliminar(currentPos);
    }

    return currentPos + 1; 
}

int main() {
    int N, M;
    cout << "Ingrese el numero total de personas (N): ";
    cin >> N;

    cout << "Ingrese el numero de personas a saltar (M): ";
    cin >> M;

    int survivor = josephus_problem(N, M);
    cout << "La posicion en la que debes estar para sobrevivir es: " << survivor << endl;

    return 0;
}
#include "NodoDobEnlaz.h"
#include <string>

template <typename T>
class ListaDE {
public:
    Nodo<T> *cabeza;
    Nodo<T> *cola;
    int num_elemento;

public:
    ListaDE() : cabeza(nullptr), cola(nullptr), num_elemento(0) {} // Constructor
    ~ListaDE() {} // Destructor

    bool insertar(T x, Nodo<T> *p);
    bool eliminar(Nodo<T> *p);
    Nodo<T> *buscar(T x) const;
    Nodo<T> *fin() const;
    Nodo<T> *primera() const;
    Nodo<T> *siguiente(Nodo<T> *pos) const;
    Nodo<T> *anterior(Nodo<T> *pos) const;
    void hacerVacia();
    bool esVacia() const;
    std::string toString() const;
    T obtener(Nodo<T> *p) const;
    int getNumElementos() const;
    void invierte();
};

// Implementación de las funciones

template <typename T>
bool ListaDE<T>::insertar(T x, Nodo<T> *p) {
    // Implementa la inserción de un elemento x antes del nodo p
    // Debes manejar los casos especiales cuando p es la cabeza o la cola
}

template <typename T>
bool ListaDE<T>::eliminar(Nodo<T> *p) {
    // Implementa la eliminación del nodo p
    // Debes manejar los casos especiales cuando p es la cabeza o la cola
}

template <typename T>
Nodo<T> *ListaDE<T>::buscar(T x) const {
    // Implementa la búsqueda de un elemento x en la lista
    // Devuelve un puntero al nodo que contiene x, o nullptr si no se encuentra
}

template <typename T>
Nodo<T> *ListaDE<T>::fin() const {
    // Implementa la obtención del último nodo de la lista (cola)
}

template <typename T>
Nodo<T> *ListaDE<T>::primera() const {
    // Implementa la obtención del primer nodo de la lista (cabeza)
}

template <typename T>
Nodo<T> *ListaDE<T>::siguiente(Nodo<T> *pos) const {
    // Implementa la obtención del nodo siguiente a pos
}

template <typename T>
Nodo<T> *ListaDE<T>::anterior(Nodo<T> *pos) const {
    // Implementa la obtención del nodo anterior a pos
}

template <typename T>
void ListaDE<T>::hacerVacia() {
    // Implementa la eliminación de todos los elementos de la lista
}

template <typename T>
bool ListaDE<T>::esVacia() const {
    return num_elemento == 0;
}

template <typename T>
std::string ListaDE<T>::toString() const {
    // Implementa la conversión de la lista a una cadena de caracteres
}

template <typename T>
T ListaDE<T>::obtener(Nodo<T> *p) const {
    // Implementa la obtención del elemento contenido en el nodo p
}

template <typename T>
int ListaDE<T>::getNumElementos() const {
    return num_elemento;
}

template <typename T>
void ListaDE<T>::invierte() {
    // Implementa la inversión de la lista
}




#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main() {

    /*Se utiliza la biblioteca time para generar una semilla que alimente a un generador de numeros
    aleatorios entre 0 y 1*/
    unsigned seed = static_cast<unsigned>(time(nullptr));
    mt19937 gen(seed);
    uniform_real_distribution<double> dist(0.0, 1.0);

    //Se rellena un arreglo de 1 y 0, tambien una probabilidad
    int n = 0, aux = 0;
    double proba = 0;
    cout<<"Digite el tamano del arreglo: ";
    cin>>n;
    cout<<"Digita la probabilidad (0 a 1): ";
    cin>>proba;
    int arrayA[n], arrayB[n];

    for(int i=0;i<n;i++){
        cout<<"Digita un numero, solo 1 o 0: ";
        cin>>aux; 
        arrayA[i] = aux;
        double random = dist(gen);
        //Si el numero aleatorio es menor a la probabilidad, se coloca un 1 al array, de lo contrario 0
        (random < proba) ? arrayB[i] = 1: arrayB[i] = 0;
    }

    for(int i=0;i<n;i++){
        cout<<arrayB[i];
    }
    
}
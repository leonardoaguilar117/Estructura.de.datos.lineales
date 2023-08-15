#include<iostream>
#include<string.h>
using namespace std;

/*Prototipos de funcion*/
string agregar(int matricula[], int promedio[], string nombre[], int n);
void buscar(int matricula);
void insertar(int matricula[], int promedio[], string nombre[]);


int main(){
    int n;
    cout<<"Cuantos alumnos existen en lista: ";
    cin>>n;
    n+=2;

    int matricula[n],promedio[n];
    string nombre[n];

    cout<<"Ingrese los valores de su matriz"<<endl;
    agregar(matricula,promedio,nombre,n);


    cout<<"Digite una opcion: "<<endl;
    cout<<"1-Agregar elemento al final"<<endl;
    cout<<"2-Agregar elemento en medio"<<endl;
    cout<<"3-Borrar elemento segun indice"<<endl;
    cout<<"4-Modificar elemento"<<endl;
    cout<<"5-Mostrar elementos"<<endl;
    cout<<"6-Eliminar todos los elementos"<<endl;
    return 0;
}

string agregar(int *matricula, int *promedio, string *nombre,int n){
    int mat=0,pro;
    string nom;

    for(int i=0; i<n-2; i++){
        cout<<"Inserte nombre "<<i+1<<": ";
        cin>>nom;
        nombre[i] = nom;
        cout<<"Inserte matricula: "<<i+1<<": ";
        cin>>mat;
        matricula[i] = mat;
        cout<<"Inserte promedio "<<i+1<<": ";
        cin>>pro;
        promedio[i] = pro;
    }
    return matricula[n],promedio[n], nombre[n];
}




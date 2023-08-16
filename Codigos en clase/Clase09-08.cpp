#include<iostream>
#include<string.h>
using namespace std;

/*Prototipos de funcion*/
void mostrarLista(long int matricula[], string nombre[],float promedio[], int n);
void buscarAlumno(long matric_a_buscar,string nombre[],float promedio[],long matricula[], int n);
int main(){
    //Variables auxiliares
    int n,opc;
    long mat;
    float pro;
    string nom;
    
    //Ingreso de tamaño y creación de arrays
    cout<<"Cuantos alumnos existen en lista: ";
    cin>>n;
    n+=2;
    long matricula[n];
    float promedio[n];
    string nombre[n];

    //Ingreso de valores a arrays
    cout<<"Ingrese los valores de su matriz"<<endl;
    for(int i=0; i<n-2; i++){
        cin.ignore();
        cout<<"Inserte nombre "<<i+1<<": ";
        getline(cin, nom);
        nombre[i] = nom;
        cout<<"Ingresa la matricula: ";
        cin>>mat;
        matricula[i] = mat;
        cout<<"Ingresa el promedio: ";
        cin>>pro;
        promedio[i] = pro;
        
    }


    
    //Menu de opciones con llamada a funciones externas para hacer los procedimientos
    do{
        cout<<"Digite una opcion "<<endl;
        cout<<"1-Mostrar toda la lista "<<endl;
        cout<<"2-Buscar si un alumno existe "<<endl;
        cout<<"3-Ingresar alumno nuevo"<<endl;
        cout<<"4-Eliminar alumno "<<endl;
        cout<<"5-Modificar alumno "<<endl;
        cout<<"6-Eliminar todos los elementos"<<endl;
        cout<<"7-Salir"<<endl;
        cin>>opc;

        //Opciones
        switch(opc){
            case 1: mostrarLista(matricula, nombre, promedio, n);
            break;
            case 2: 
                cout<<"Digite la matricula a buscar: ";
                cin>>mat;
                buscarAlumno(mat, nombre, promedio, matricula, n);
            break;
            default:cout<<"ola";
        }
    }while(opc!=7);
}




void mostrarLista(long matricula[], string nombre[],float promedio[], int n){
    for(int i=0; i<n-2;i++){
        cout<<"Nombre: "<<nombre[i]<<endl;
        cout<<"Matricula: "<<matricula[i]<<endl;
        cout<<"Promedio: "<<promedio[i]<<endl;
        cout<<"\n";
    }
}

void buscarAlumno(long matric_a_buscar,string nombre[],float promedio[],long matricula[], int n){
    int flag;
    for(int i=0; i<n-2;i++){
        if(matric_a_buscar == matricula[i]){
            cout<<"Alumno encontrado: "<<endl;
            cout<<"Nombre: "<<nombre[i]<<endl;
            cout<<"Matricula: "<<matricula[i]<<endl;
            cout<<"Promedio: "<<promedio[i]<<endl;
            flag = 1;
        }
    }
    (flag == 1) ? "Alumno no encontrado" : " " ; 
    
    
}


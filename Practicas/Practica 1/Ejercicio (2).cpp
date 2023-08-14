#include <iostream>
using namespace std;

int main(){
    int arr[5];
    cout<<"Este es un programa que ordena cuatro numeros de manera ascendente."<<endl;
    for(int i = 0; i<4; i++){
        cout<<"Numero "<< i+1 << ": ";
        cin>>arr[i];
    }

    for (int i = 0; i<3; i++){
        for (int j = 0; j<3 - i; j++){
                if (arr[j]>arr[j+1]){
                int hlp = arr[j];            
                arr[j] = arr[j+1];
                arr[j+1] = hlp;
                }
        }
    }
    cout<<endl;
    cout<<"Numeros ordenados:"<<endl<<endl;
    for(int i = 0; i<4; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}

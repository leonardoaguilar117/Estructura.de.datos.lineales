//sucesión de fibonacci
#include <iostream>
using namespace std;

int main(){
    long long int n, sum = 0, sumdos = 1, res=1;
    cout<<"Cuantos numeros de la sucesion de fibonacci quieres sumar?: ";
    cin >> n;
	if (n<=0){
		cout<<"Error, digita un numer mayor a 0";
	}
	if(n>0){
    cout<<"0 ";
    if (n>=2){
        cout<<"1 ";
    }
	if(n>2){
    for (int cont = 3; cont<=n ; cont++){
        res = sum + sumdos;
        cout<<res<<" ";
        sum = sumdos;
        sumdos = res;
    }
	}
}
    return 0;
}
/*
#include <stdio.h>

int main(){
	long long int n, sum=0, sumdos=1, cont, res=1;
	printf("Dame n: ");
	scanf("%lld",&n);	
	printf("0 ");  
	if (n>=2){
		printf("1 ");
	}

	if(n<0){
		printf("Error, digita un numero mayor o igual a 0");
	}
	else if(){
	for(cont = 3; cont<=n; cont++)
	{
		res = sum + sumdos;
		printf("%lld ",res);
		sum = sumdos;
		sumdos = res;
	}
	}
	return 0;
}







*/
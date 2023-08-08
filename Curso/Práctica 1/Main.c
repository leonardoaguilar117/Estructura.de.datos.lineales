#include <stdlib.h>
#include <stdio.h>
#include "Funciones.c"

ListaCompleta *lista;

int main(){
  char nombre[35];
  char lic[40];
  char div[40];
  int matricula=0;
  int edad=0;
  lista = crearLista();

  int opcion = 0;
    while(opcion != 9){
      printf("----------------------------------------------------------.\n");
      printf(".             S I S T E M A  U A M I T O                  .\n");
      printf(".           Seleccione la opcion a realizar:              .\n");
      printf(".                1-Crear lista nueva                      .\n");
      printf(".                 2-Importar lista                        .\n");
      printf(".              3-A%cadir alumno a lista                    .\n",164);
      printf(".                 4-Buscar Alumno                         .\n");
      printf(".                5-Eliminar alumno                        .\n");
      printf(".                 6-Mostrar lista                         .\n");
      printf(".                7-Eliminar lista                         .\n");
      printf(".                 8-Exportar lista                        .\n");
      printf(".                    9-Salir                              .\n");
      printf("----------------------------------------------------------.\n");
      scanf("%d",&opcion);

        
      if(opcion == 1){
        printf("INGRESE LOS DATOS DEL ALUMNO: \n");
        printf("Digite el nombre: ");
        scanf(" %[^\n]",nombre);
        printf("Digite la edad: ");
        scanf("%d",&edad);
        printf("Digite la matricula: ");
        scanf("%d",&matricula);
        printf("Digite la licenciatura: ");
        scanf(" %[^\n]",lic);
        printf("Digite la division: ");
        scanf(" %[^\n]",div);
        insertar_cabeza(lista,crear_Nodo(crearAlumno(nombre,edad,matricula,lic,div)));
      }else if(opcion == 2){
        printf("Importar\n");
      }else if(opcion == 3){
        printf("INGRESE LOS DATOS DEL NUEVO ALUMNO: \n");
        printf("Digite el nombre: ");
        scanf(" %[^\n]",nombre);
        printf("Digite la edad: ");
        scanf("%d",&edad);
        printf("Digite la matricula: ");
        scanf("%d",&matricula);
        printf("Digite la licenciatura: ");
        scanf(" %[^\n]",lic);
        printf("Digite la division: ");
        scanf(" %[^\n]",div);
        insertar_cabeza(lista,crear_Nodo(crearAlumno(nombre,edad,matricula,lic,div)));
      }else if(opcion == 4){
        printf("Ingrese la matricula del alumno a buscar: \n");
        scanf("%d",&matricula);
        buscaElemento(lista,matricula);
      }else if(opcion == 5){
        printf("Ingrese la matricula del alumno a eliminar: \n");
        scanf("%d",&matricula);
        quitar_enmedio(lista,matricula);
      }else if(opcion == 6){
        printLista(lista);
      }else if(opcion == 7){
        vaciarLista(lista);
      }else if(opcion == 8){
        printf("Exportar \n");
      }
          	

          
    }

}










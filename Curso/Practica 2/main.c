#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"

ListaD *lista;
ListaD *listaEdad;

int main(){ 
  //Variables auxiliares
  int opcion = 0;
  int matricula, edad;
  char nombre[35];

  ListaD *lista = crear_ListaD();
  ListaD *listaEdad = crear_ListaD();

    do{
      printf("----------------------------------------------------------.\n");
      printf(".             S I S T E M A  U A M I T O                  .\n");
      printf(".           Seleccione la opcion a realizar:              .\n");
      printf(".                1-Crear lista nueva                      .\n");
      printf(".              2-A%cadir alumno a lista                    .\n",164);
      printf(".                 3-Buscar Alumno                         .\n");
      printf(".                4-Eliminar alumno                        .\n");
      printf(".                 5-Mostrar lista                         .\n");
      printf(".                6-Eliminar lista                         .\n");
      printf(".                    7-Salir                              .\n");
      printf("----------------------------------------------------------.\n\n\n");
      scanf("%d",&opcion);
      system("cls");


      switch(opcion){
          case 1: printf("Inserte la matricula del primer alumno: ");
                  scanf("%d",&matricula);
                  printf("Inserte el nombre del primer alumno: ");
                  scanf(" %[^\n]",nombre);
                  printf("Inserte la edad del primer alumno: ");
                  scanf("%d",&edad);
                  insertar_cabeza(lista,crear_Nodo(crear_Alumno(matricula,nombre,edad)));
          break;  
          case 2: printf("Inserte la matricula del primer alumno: ");
                  scanf("%d",&matricula);
                  printf("Inserte el nombre del primer alumno: ");
                  scanf(" %[^\n]",nombre);
                  printf("Inserte la edad del primer alumno: ");
                  scanf("%d",&edad);
                  if(buscaElementoA(lista,matricula) == NULL){
                     insertar_cabeza(lista,crear_Nodo(crear_Alumno(matricula,nombre,edad)));
                  }else{
                     printf("Ya existe un alumno con la misma matricula, ingrese otro alumno \n\n");
                  } 
          break;
          case 3: printf("Ingrese la edad a buscar en la lista: ");
                  scanf("%d",&edad);
                  Nodo *aux = lista->cabeza;
                  Alumno *alu = aux->datos;
                  Nodo *nodo;
                  if(isEmpty(lista)!=1){
                    while(aux!=NULL){ 
                        if(alu->edad==edad){
                            printf("\nNombre: %s\n",aux->datos->name);
                            printf("\nEdad: %d\n",aux->datos->edad);
                            printf("\nMatricula: %u\n\n",aux->datos->matricula);
                            //nodo = aux;
                            //insertar_cabeza(listaEdad,nodo); se pretende almacenar en lista e imprimir lista después
                            //pero desconocemos el motivo de un "ciclado", se hizo una lista especial para los alumnos
                            //con la edad buscada
                            aux=aux->sig;
                        }else{
                            printf("No hay alumnos con esa edad");
                            break;
                        }
                    }
                 }else{
                        printf("\n Lista sin elementos \n");
                 }
          break;
          case 4: printf("Inserte la matricula del alumno a eliminar: ");
                  scanf("%d",&matricula);
                  quitar_enmedio(lista, matricula);
          break;
          case 5: printLista(lista);
          break;
          case 6: vaciarLista(lista);
                  printf("Se ha vaciado la lista correctamente\n\n");
          break;
      }

    }while(opcion!=7);
  
    return 0;
}










#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int TareaID; //Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; //entre 10 – 100
}Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo *Sig;
}Nodo;

void * crearNodoTarea(int indice, int duracion);
void insertarNodo(Nodo **start, Nodo *NNodo);

int main(){
    char valor;
    int indice=1000,duracion;
   
 Nodo *start=NULL;
 Nodo *aux;

    

    printf("Lista de tares pendientes: \n");
    printf("¿Desea cargar una tarea? (S/N):");
    scanf("%c",&valor);
    
    while(valor==115 || valor==83){
        
        indice++;
        printf("Duracion: ");
        scanf("%d",&duracion);
        insertarNodo(&start,crearNodoTarea(indice,duracion));
        getchar();
        fflush(stdin);
        printf("¿Desea cargar otra tarea? (S/N):");
        scanf("%c",&valor);

    }
    
    
    /*
    codigo para mostrar lista enlazada. despues lo tengo que poner en una funcion.
    aux=start;
    
    while(aux){
        printf("Indice: %d \n",aux->T.TareaID);
        printf("Duracion: %d \n",aux->T.Duracion);
        aux=aux->Sig;
    }*/



    return 0;

}

void * crearNodoTarea(int indice, int duracion){

    Nodo *NNodo=(Nodo *)malloc(sizeof(Nodo));
    NNodo->T.TareaID=indice; 
    //printf("Ingresar descripcion de la tarea:");
    //gets(NNodo->T.Descripcion);
    NNodo->T.Duracion=duracion;
    NNodo->Sig=NULL;
    return NNodo;
           

}

void insertarNodo(Nodo **start, Nodo *NNodo){
    NNodo->Sig=*start;
    *start=NNodo;
}
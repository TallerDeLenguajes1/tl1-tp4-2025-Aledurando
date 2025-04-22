#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100;


typedef struct {
    int TareaID; //Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; //entre 10 – 100
}Tarea;

typedef struct Nodo{
    Tarea T;
    struct Nodo *Sig;
}Nodo;


Nodo *CrearListaVacia();
void * crearNodoTarea(int indice, int duracion);
void insertarNodo(Nodo **start, Nodo *NNodo);
Nodo * BuscarNodo(Nodo ** Start,int id);
Nodo * QuitarNodo(Nodo ** Start,int id);
void ListarLista(Nodo **start);

int main(){
    char valor;
    int indice=1000,duracion,iaux;
    char descrip[MAX];
   
    Nodo * start = CrearListaVacia();
    Nodo * startLR= CrearListaVacia();
    Nodo * aux;

    

    printf("Lista de tares pendientes: \n");
    printf("¿Desea cargar una tarea? (S/N):");
    scanf("%c",&valor);
    
    while(valor==115 || valor==83){
        
        indice++;
        printf("Descripcion");
        gets(descrip);
        printf("Duracion: ");
        scanf("%d",&duracion);
        
        insertarNodo(&start,crearNodoTarea(indice,duracion));

        getchar();
        fflush(stdin);
        printf("¿Desea cargar otra tarea? (S/N):");
        scanf("%c",&valor);

    }
    
        printf("\n ID de la tarea pendiente para marcar realizada(0 para terminar): ");
        scanf("%d",&iaux);
        
        
        while(iaux!=0){

     
        aux=BuscarNodo(&start,iaux);
            
                if(aux){
                    aux=QuitarNodo(&start,iaux);
                    insertarNodo(&startLR,aux);
                    
                }else {
                    printf("id no encontrado");
                    
                };

        printf("\n ID de la tarea pendiente para marcar realizada(0 para terminar):  ");
        scanf("%d",&iaux);

        }


    
    
    printf("\n\n LISTA DE TARES REALIZADAS\n");
    ListarLista(&startLR);
    printf("\n\n LISTA DE TAREAS PENDIENTES\n");
    ListarLista(&start);




    return 0;

}

void * crearNodoTarea(int indice, int duracion){

    Nodo *NNodo=(Nodo *)malloc(sizeof(Nodo));
    NNodo->T.TareaID=indice;

    NNodo->T.Duracion=duracion;
    NNodo->Sig=NULL;
    return NNodo;
           

}

void insertarNodo(Nodo **start, Nodo *NNodo){
    NNodo->Sig=*start;
    *start=NNodo;
}

Nodo * BuscarNodo(Nodo ** Start,int id)
{
  Nodo * Aux = (*Start);
  while (Aux && Aux->T.TareaID != id)
  {
    Aux = Aux->Sig;
    
  }
  return Aux;
}


Nodo * CrearListaVacia()
{
    return NULL;
}

Nodo * QuitarNodo(Nodo ** Start,int id)
{
  Nodo * Aux = *Start;
  Nodo * AuxAnterior=NULL;

  while (Aux!=NULL && Aux->T.TareaID!= id)
  {
    AuxAnterior=Aux;
    Aux = Aux->Sig;
    
  }

  if (Aux!=NULL){

        if(Aux==(*Start)){

            (*Start)=Aux->Sig;
        }else
        {
            AuxAnterior->Sig=Aux->Sig;
        }
    
        Aux->Sig=NULL;
  } 

  return(Aux);

    
  }

  void ListarLista(Nodo **start){

    Nodo *aux;
    aux=*start;
    
    while(aux){
        printf("Indice: %d \n",aux->T.TareaID);
        printf("Duracion: %d \n",aux->T.Duracion);
        aux=aux->Sig;
    }

  }
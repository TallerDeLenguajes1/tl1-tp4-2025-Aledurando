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


Nodo *CrearListaVacia();
void * crearNodoTarea(int indice);
void insertarNodo(Nodo **start, Nodo *NNodo);
Nodo * BuscarNodo(Nodo ** Start,int id);
Nodo * QuitarNodo(Nodo ** Start,int id);
void ListarLista(Nodo **start);

int main(){
    int valor;
    int indice=1000,iaux,opcion;

   
    Nodo * start = CrearListaVacia();
    Nodo * startLR= CrearListaVacia();
    Nodo * aux;

    printf("Ingresar opcion:");
    scanf("%d",&opcion);
    switch (opcion)
    {
        case 1: {
                    do{
                        printf("Lista de tares pendientes: \n");
                        printf("¿Desea cargar una tarea?( [1].SI [0].NO ) : ");
                        scanf("%d",&valor);

                        if(valor==1)insertarNodo(&start,crearNodoTarea(indice));                  
                    
                    }while(valor!=0);

            
                    }
        
        break;
    
    default:
        break;
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

void * crearNodoTarea(int indice){

    Nodo *NNodo=(Nodo *)malloc(sizeof(Nodo));
    
    indice++;
    int tareaDuracion,control=0;
    char *buff = (char *)malloc(sizeof(char)*100); //creamos variable buffer. 
    
    NNodo->T.TareaID=indice;

    printf("\nIngrese la descripcion de la tarea: ");
    fflush(stdin);
    getchar();
    gets(buff);

    NNodo->T.Descripcion = (char *)malloc((strlen(buff)+1)*sizeof(char)); //RECORDAR LIBERAR
    strcpy(NNodo->T.Descripcion, buff); 
    free(buff);


 
        do{
            printf("\nIngresar duracion de la tarea entre 10-100:  ");
            scanf("%d",&tareaDuracion);
            if(tareaDuracion>=10 && tareaDuracion<=100){
                NNodo->T.Duracion=tareaDuracion;
                control=1;
            }else 
                printf("\nERROR VALOR FUERA DE RANGO.");
        
        }while(control!=1);

  
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    int TareaID; //Numérico autoincremental comenzando en 1000
    char *Descripcion; //char menor a 100 caracteres.
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
void BuscarPalabraClave(Nodo *L1, Nodo *L2);

int main(){
    int valor;
    int indice=1000,iaux,opcion;

    Nodo * start = CrearListaVacia();
    Nodo * startLR= CrearListaVacia();
    Nodo * aux;

    do{
        
        printf("\n [1]Agregar Lista de tareas pendientes: ");
        printf("\n [2]Marcar Tarea pendiente como realizada: ");
        printf("\n [3]Mostrar Listas pendientes y realizadas: ");
        printf("\n [4]Buscar por id o palabra clave en lista: ");
        printf("\n [5]Salir: ");
        printf("\n\t\t Ingresar opcion: ");
        scanf("%d",&opcion);
        
        switch (opcion)
        {
            case 1: {
                        do{
                            
                            printf("¿Desea cargar una tarea pendiente?( [1].SI [0].NO ) : ");
                            scanf("%d",&valor);

                            if(valor==1){
                                    
                                    insertarNodo(&start,crearNodoTarea(indice));
                                    indice++;
                                    }                  
                        
                        }while(valor!=0);

                
                        }
            
            break;
        
            case 2:{
                        printf("\n ID de la tarea pendiente para marcar realizada(0 para terminar): ");
                        scanf("%d",&iaux);
                        
                        while(iaux!=0){
                            aux=BuscarNodo(&start,iaux);
                            
                                if(aux){ //Si existe el nodo que devuelve buscarnodo.
                                    aux=QuitarNodo(&start,iaux); //lo quito al nodo de la lista pendientes
                                    insertarNodo(&startLR,aux); //agrego al nodo a la lista realizados.
                                    
                                }else {
                                    printf("id no encontrado");
                                    
                                };
                
                        printf("\n ID de la tarea pendiente para marcar realizada(0 para terminar):  ");
                        scanf("%d",&iaux);
                
                        }
                    }

            break;
            
            case 3: {    
                    printf("\n\n LISTA DE TARES REALIZADAS: \n");
                    ListarLista(&startLR);
                    printf("\n\n LISTA DE TAREAS PENDIENTES: \n");
                    ListarLista(&start);
                    }
            break;
            
            case 4:{ 
                    
                    BuscarPalabraClave(start,startLR);

            }
            break;
            
            
            default:
            break;
        }
    
    }while(opcion!=5);

    return 0;

}



void * crearNodoTarea(int indice){

    Nodo *NNodo=(Nodo *)malloc(sizeof(Nodo));
    
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
        printf("Descricion: ");
        puts(aux->T.Descripcion);
        printf("Duracion: %d \n",aux->T.Duracion);
        aux=aux->Sig;
    }

  }


void BuscarPalabraClave(Nodo *LPendientes, Nodo *LRealizadas){
    int opcion;
    char *clave;

    printf("\n Buscar por: \n[1].Palabra Clave \n[2].ID \n Seleccionar opcion: ");
    scanf("%d",&opcion);
    getchar();
    fflush(stdin);
    

    switch (opcion)
    {
    case 1: //caso de busqueda con palabra clave. 
        {
            char *buff = (char *)malloc(sizeof(char)*100); //creamos un buffer auxiliar para alojar el string hasta 100 caracteres.
            printf("\nIngrese la palabra clave a buscar: ");
            fflush(stdin);
            gets(buff);
            getchar();
            
            clave = (char *)malloc((strlen(buff)+1)*sizeof(char)); //palabra para comparar y ya con memoria justa para la palabra.
            strcpy(clave, buff); //copiando buffer en clave.
            free(buff); //liberamos el buffer.

            while(LPendientes!=NULL && strstr(LPendientes->T.Descripcion,clave)==NULL){
                LPendientes=LPendientes->Sig; //recorremos hasta encontrar la palabra.
            }
            if(LPendientes!=NULL){
                printf("\n Palabra clave encontrada: ");
                printf("\n Se encuentra en Listado Tarea Pendientes: ");
                printf("\n Id de tarea: %d",LPendientes->T.TareaID);
                printf("\n Descripcion de la tarea: ");
                puts(LPendientes->T.Descripcion);
                printf("\n Duracion de la tarea: %d",LPendientes->T.Duracion);

                    // muestro el nodo encontrado.
            }else{
                while (LRealizadas!=NULL && strstr(LRealizadas->T.Descripcion,clave)==NULL){
                    LRealizadas=LRealizadas->Sig;
                }
                if(LRealizadas!=NULL){
                    
                    printf("\n Palabra clave encontrada: ");
                    printf("\n Se encuentra en Listado Tarea Realizadas: ");
                    printf("\n Id de tarea: %d",LRealizadas->T.TareaID);
                    printf("\n Descripcion de la tarea: ");
                    puts(LRealizadas->T.Descripcion);
                    printf("\n Duracion de la tarea: %d",LRealizadas->T.Duracion);
                    //muestro nodo.
                }

            }
            free(clave); //liberamos la palabra usada.
        }
        break;
    

    case 2:{ //caso de busqueda con id.


            //declaro un id auxiliar, un nodo auxiliar ya que voy a usar la funcion Buscarnodo que devuelve el nodo que encuentra.
            int idbuscado;
            Nodo *aux=(Nodo*)malloc(sizeof(Nodo));
            printf("\nIngresar ID a buscar: ");
            scanf("%d",&idbuscado);
            fflush(stdin);
            getchar();


            aux=BuscarNodo(&LPendientes,idbuscado);
            if(aux!=NULL){ //si lo encuentra en la lista de pendientes lo muestra y si no, prueba en el siguiente else.
                printf("\n ID encontrado: ");
                printf("\n Se encuentra en Listado Tarea Pendientes: ");
                printf("\n Id de tarea: %d",LPendientes->T.TareaID);
                printf("\n Descripcion de la tarea: ");
                puts(LPendientes->T.Descripcion);
                printf("\n Duracion de la tarea: %d",LPendientes->T.Duracion);
            }else {
                aux=BuscarNodo(&LRealizadas,idbuscado);
                if(aux!=NULL){
                    printf("\n ID encontrado: ");
                    printf("\n Se encuentra en Listado Tarea Realizadas: ");
                    printf("\n Id de tarea: %d",LRealizadas->T.TareaID);
                    printf("\n Descripcion de la tarea: ");
                    puts(LRealizadas->T.Descripcion);
                    printf("\n Duracion de la tarea: %d",LRealizadas->T.Duracion);
                    
                }else {

                    printf("\n ID no encontrado en ninguna lista.");
                }
    
            }
            free (aux);
        }
        

            break;



    default:
        break;
    }

    

}
/* **********************************************************************
NOMBRE DEL PROGRAMA: ProyectoFinalHospital.c
OBJETIVO: Ordenar a los pacientes de un hospital dependiendo la prioridad 
		  de la urgencia con la que lleguen a �ste.
AUTORES: Ramirez Gonzalez Yaremi
		 Segura Rios Brenda Stephanie
FECHA: 28/11/2019
********************************************************************** */
//LIBRER�AS
#include  <stdio.h>
#include <stdlib.h>


/* ESTRUCTURAS -------------------
NOMBRE: Define un nombre y un n�mero de prioridad.
NODOCp: Define un nodo con apuntador a siguiente 
		y un name de tipo Nombre.
----------------------------------*/
typedef struct{
	int prioridad;
	char Paciente[20];
}Nombre;
typedef Nombre *Nodo;


typedef struct RegistroCP{
	Nombre name;
	struct RegistroCP* sig;
}NodoCp;
typedef NodoCp *ColaPrioridad;//Declaramos un apuntador "ColaPrioridad" de tipo NodoCp


/* --------------------------------------------------------------------
NOMBRE: Funci�n Cola_vacia
TIPO: entero int
PAR�METROS: 	Pacientes: 	Apuntador al inicio de la estructura.
DESCRIPCI�N: 	Funci�n que indica que una estructura est� vac�a.
-------------------------------------------------------------------- */
int Cola_vacia(ColaPrioridad Pacientes){
	return (Pacientes == NULL);
}


/* --------------------------------------------------------------------
NOMBRE: funci�n ver_primero
TIPO:  void
PAR�METROS: 	Pacientes: apuntador al incio de Cola de prioridad.
DESCRIPCI�N: Funci�n que muestra el elemento inicial de la cola.
-------------------------------------------------------------------- */
void ver_primero(ColaPrioridad Pacientes){
  
  	printf("\t\t\t\t\t\t PRIORIDAD: %d  \n\n\t\t\t\t\t\t NOMBRE: %s \n\n\n\t\t\t\t\t", Pacientes->name.prioridad, Pacientes->name.Paciente);
   
  system("pause");
}


/* --------------------------------------------------------------------
NOMBRE: funci�n BorrarCp
TIPO:  void
PAR�METROS: 	Pacientes: apuntador al incio de Cola de prioridad.
DESCRIPCI�N: Funci�n que borra los datos de la cola que se encuentren aun en espera a la hora de terminar la jornada.
-------------------------------------------------------------------- */
void BorrarCp(ColaPrioridad* Pacientes){
	
	NodoCp *ab;
	
	if(Cola_vacia(*Pacientes)){
	   printf ("Sin pacientes en espera");	
	}

	ab = *Pacientes;
	*Pacientes	= ab->sig;
	
	free (ab);
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n Insertar
TIPO: void
PAR�METROS: Pacientes:	De tipo (ColaPrioridad).
			nombre: cadena recibida desde la funcion main.
DESCRIPCI�N: Funci�n que agrega un paciente a la cola.
-------------------------------------------------------------------- */
void Insertar(ColaPrioridad* Pacientes, Nombre nombre){ 
 
	 NodoCp *nuevonodo;
	 
		if (*Pacientes == NULL) {
			 nuevonodo = NuevoNodoCp(nombre);
				*Pacientes = nuevonodo;
				
		}else if (nombre.prioridad < (*Pacientes)->name.prioridad)	{
		
				nuevonodo = NuevoNodoCp(nombre);
				nuevonodo->sig = *Pacientes;
				*Pacientes = nuevonodo;
				
		}else
		Insertar(&((*Pacientes)->sig),nombre);
		
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n NuevoNodoCp
TIPO: NodoColaPrioridad
PAR�METROS: nombre: de tipo estructura "Nombre"
DESCRIPCI�N: Funci�n que agrega un nodo a la cola. Reserva la memoria. 
-------------------------------------------------------------------- */
void NuevoNodoCp(Nombre nombre){
	
  NodoCp *nuevonodo ;
  
  nuevonodo= (NodoCp*)malloc(sizeof(NodoCp));
  nuevonodo->sig = NULL; 
  nuevonodo->name = nombre;
  
  return *nuevonodo;
}


/* --------------------------------------------------------------------
NOMBRE: ver_cola
TIPO: void
ARGUMENTOS:		Pacientes: apuntador al incio de Cola de prioridad.
DESCRIPCI�N: Funci�n que muestra los pacientes en espera.
-------------------------------------------------------------------- */
void ver_cola(ColaPrioridad Pacientes) {
	
  printf("\n\n\n\t\t\t\t\t\tPACIENTES EN ESPERA\n\n\n");
  
  for (; Pacientes; Pacientes = Pacientes->sig)
			printf("\t\t\t\t\t PRIORIDAD: %d \t NOMBRE: %s\n\n", Pacientes->name.prioridad, Pacientes->name.Paciente);
			printf("\n\n\t\t\t\t\t");
			system("pause");
}


/* --------------------------------------------------------------------
NOMBRE: Funci�n borrar_primero
TIPO: int
PAR�METROS: Prioridad: Prioridad de la que se va a borrar el valor.
DESCRIPCI�N: Funci�n que elimina un elemento de una cola.
-------------------------------------------------------------------- */
void borrar_primero(ColaPrioridad *Pacientes) {
	
	NodoCp *ab;
	
	printf("\n\n\t\t\t\t\t   SE BORR%C EL PACIENTE: \n\n\n", 224);
	ver_primero(*Pacientes);//Le muestra al usuario el paciente que ser� borrado de la cola.
	
	ab = *Pacientes;
	*Pacientes	= ab->sig;
	
	printf("\n\n");
	ver_cola((*Pacientes));
	
	free (ab);

} 


/* --------------------------------------------------------------------
NOMBRE: Funci�n men�
TIPO: void
PAR�METROS: N/A
DESCRIPCI�N: Funci�n que muestra el men� en pantalla.
-------------------------------------------------------------------- */
void menu(){

		printf("\t\t\t\t\t\t %cBIENVENIDO%c\n\n", 173, 33);
    	printf("\t\t\t\tPrioridad de pacientes en %crea de urgencias.\n\n", 160);
    	printf("\t\t\t\t\t  %c 1. Agregar paciente\n\n", 254);
    	printf("\t\t\t\t\t  %c 2. Ver pacientes en espera\n\n", 254);
    	printf("\t\t\t\t\t  %c 3. Ver siguiente paciente en ser atendido\n\n", 254);
    	printf("\t\t\t\t\t  %c 4. Borrar registro del paciente atendido\n\n", 254);
    	printf("\t\t\t\t\t  %c 5. Borrar registros del dia\n\n", 254);
}


/* --------------------------------------------------------------------
NOMBRE: main
TIPO: void
PAR�METROS: N/A
DESCRIPCI�N: Funci�n que declara un arreglo, lo inicializa, trabaja con el,
			 y lo imprime en pantalla.
-------------------------------------------------------------------- */
void main(){
   
   Nombre nombr;
   int op;
   ColaPrioridad  Pacientes;
   Pacientes = NULL;
   	
	do{
   	menu();
   	printf("\n\n\t\t\t\tIntroduzca el n%cmero de la acci%cn que deseas realizar: ", 163, 162);
    scanf("%d", &op); 		//Leer variable eOpcion.
   	system("cls");				//Limpiar pantalla.
   	fflush(stdin);
	  	
		  switch(op){
	  		
			  case 1:
			  	printf("\n\n\n\t\t\t\t\t\t   AGREGAR PACIENTE");
			    printf("\n\n\n\n\n\t\t\t\t\tIntroduzca prioridad de la persona: ");
			    scanf("%d", &nombr.prioridad);
		  		printf("\n\n\t\t\t\t\tIntroduzca el nombre del paciente: ");
		  		scanf("%s", &nombr.Paciente);
		  		printf("\n\n\t\t\t\t\t");
		  		Insertar(&Pacientes,nombr);
		  		system("pause");
		  		system("cls");		
	  			break;
	  			
	  		case 2:
	  			if(Cola_vacia(Pacientes)){ 
     				printf ("\n\n\n\t\t\t\t\t\tSin pacientes en espera.\n\n\t\t\t\t\t");
     				system("pause");
				}else{
	  			ver_cola(Pacientes);
	  			}
	  			system("cls");	
	  			break;
	  			
	  		case 3: 
		  		if(Cola_vacia(Pacientes)){ 
     				printf ("\n\n\n\t\t\t\t\t\tSin pacientes en espera.\n\n\t\t\t\t\t");
     				system("pause");
				}else{
	  			printf("\n\n\t\t\t\t\t\tPRIMER PACIENTE: \n\n\n");
		  		ver_primero(Pacientes);
		  		}
		  		system("cls");
				break;
					
	  		case 4:
	  			if(Cola_vacia(Pacientes)){ 
     				printf ("\n\n\n\t\t\t\t\t\tSin pacientes en espera.\n\n\t\t\t\t\t");
     				system("pause");
				}else{
	  			borrar_primero(&Pacientes);
	  			}
				system("cls");	
	  		break;
	  		case 5:
	  			break;
			default:
	  			printf("\n\n\n\t\t\t\t\t\tIngrese un numero valido\n\n\t\t\t\t\t ");
	  			break;
	  		
		  }
  } while (op!=5);
  	
	printf("\n\n\n\t\t\t\t\t\tBORRANDO COLA DE PRIORIDAD\n");
	if(Cola_vacia(Pacientes)){ 
   		printf ("\n\n\n\t\t\t\t\t\tSin pacientes en espera.\n\n\n\n\t\t\t\t\t");
    	system("pause");
	}else{
	ver_cola(Pacientes);
	BorrarCp(&Pacientes);
	}
	system("cls");
}



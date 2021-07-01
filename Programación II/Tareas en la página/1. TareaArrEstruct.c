/* **********************************************************************
NOMBRE DEL PROGRAMA: TareaArregloEstructurado.c
COPYRIGHT: SR 2019
AUTOR: Segura Rios Brenda Stephanie
OBJETIVO: Mostrar como funcionan los arreglos numéricos y de cadena.
FECHA: 09/08/2019
********************************************************************** */

//BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

//CONSTANTES
#define MAX_CALIFICACIONES 7

//TIPOS
typedef char * TCadena[30];
typedef float TaCalificacion[MAX_CALIFICACIONES];

//PROTOTIPOS
void LeerDatos(int);
float CalcularPromedio(TaCalificacion);

/* ----------------------------------------------------------------------
NOMBRE:main
TIPO: void
ARGUMENTOS: N/A
OBJETIVO: Función que pide los datos y manda a llamar funciones.
---------------------------------------------------------------------- */
int main(){
	
	int eNumAlumnos;
	
	printf("Programa que calcula el promedio de 7 calificaciones de la cantidad de alumnos que se indiquen.");
	printf("%cCuantos alumnos quiere ingresar?  \n", 168);
	scanf("%d", &eNumAlumnos);
	LeerDatos(eNumAlumnos);
	
	fflush(stdin);
	getchar();
	return 0;
}

/* ----------------------------------------------------------------------
NOMBRE:LeerDatos
TIPO: void
ARGUMENTOS: eNumAlumnos que indica cuantos alumnos se vana ingresar.
OBJETIVO: Función que pide las calificciones y nombres de alumnos.
---------------------------------------------------------------------- */
void LeerDatos(int eNumAlumnos){
	
	TCadena aAlumnos[eNumAlumnos];
	TaCalificacion aCalificaciones[MAX_CALIFICACIONES];
	int eCont, eIndice;
	
	for ( eCont = 0; eCont < eNumAlumnos; eCont ++){
		
		printf("Ingresa el nombre del alumno [%d]:  ", eCont + 1);
		scanf("%s", &aAlumnos[eCont]);
	
		for ( eIndice = 0; eIndice < MAX_CALIFICACIONES; eIndice ++ ){
			
			printf("Ingrese la calificaci%cn [%d]:  ", 162, eIndice + 1);
			scanf("%f", &aCalificaciones[eIndice]);

		}
		

		printf("El promedio de las %d calificaciones es: %.2f\n\n", MAX_CALIFICACIONES, CalcularPromedio(aCalificaciones[MAX_CALIFICACIONES]));
		fflush(stdin);
	} 

}

/* ----------------------------------------------------------------------
NOMBRE:Calcularpromedio
TIPO: float
ARGUMENTOS: aCalificaciones es un arreglo donde se guardaron las calificaciones
			de los alumnos.
OBJETIVO: Función que pide calcula el promedio de las calificaciones inresadas.
---------------------------------------------------------------------- */
float CalcularPromedio(TaCalificacion aCalificaciones[MAX_CALIFICACIONES]){
	
	int eCalificacion = 0;
	float fSuma = 0.0f;
	
	for ( eCalificacion == 0; eCalificacion < MAX_CALIFICACIONES; eCalificacion ++){
		
		fSuma += aCalificaciones[eCalificacion];
		
	}
	
	return fSuma / MAX_CALIFICACIONES;
	
}


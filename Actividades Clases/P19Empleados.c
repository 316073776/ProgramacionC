/* **********************************************************************
NOMBRE DEL PROGRAMA: 
OBJETIVO: 
AUTOR: 
FECHA: 
********************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define PARTICIPANTES 5

void LeerInformacionEmpleados(TaNombreEmpleados, TaSalarioEmpleados);//Prototipos
float SalarioPromedio(TaSalarioEmpleados);
void EmpleadoPorSalario (float fSalarioMinimo, float fSalarioMaximo, TaSalarioEmpleados aSalarioEmpleados, TaNombreEmpleados aNombreEmpleados);


int main (){
	
	TaNombreEmpleados aNombreEmpleados;
	TaSalarioEmpleados aSalarioEmpleados;
	
	printf("Programa que lee y guarda el nombre y salario de 50 empleados y \nsaca el promedio de los salarios y te dice quien gana entre 1250 y 2500. \n\n");
	LeerInformacionEmpleados(aNombreEmpleados, aSalarioEmpleados);
	printf("\n\nEl promedio de los salarios es: %.2f", SalarioPromedio (aSalarioEmpleados));
	EmpleadoPorSalario(1250, 2500, aSalarioEmpleados, aNombreEmpleados);
	
	getchar();
	return 0;
}


void LeerInformacionEmpleados ( TaNombreEmpleados aNombreEmpleados, TaSalarioEmpleados aSalarioEmpleados){
	
	int eIndice;
	
	for ( eIndice = 0; eIndice < EMPLEADOS; eIndice ++ ){
		
		printf("\nIngrese el nombre del empleado %d: ", eIndice + 1);
		gets(aNombreEmpleados[eIndice]);
		
		printf("Ingrese el salario del empleado %d: ", eIndice + 1);
		scanf("%f", &aSalarioEmpleados[eIndice]);
		
	fflush(stdin);
	
	}
	
}


float SalarioPromedio(TaSalarioEmpleados aSalarioEmpleados){
	
	int eIndice;
	float fSuma = 0.0f;
	
	for ( eIndice = 0; eIndice < EMPLEADOS; eIndice ++ ){
		
		fSuma = fSuma + aSalarioEmpleados[eIndice];
		
	}
	
	return fSuma / EMPLEADOS;
	
}


void EmpleadoPorSalario (float fSalarioMinimo, float fSalarioMaximo, TaSalarioEmpleados aSalarioEmpleados, TaNombreEmpleados aNombreEmpleados){
	
	int eIndice;
	
	printf("\n\nEstos empleados ganaron entre %.2f y %.2f : \n", fSalarioMinimo, fSalarioMaximo);
	
	for ( eIndice = 0; eIndice < EMPLEADOS; eIndice ++ ){
		
		if ( aSalarioEmpleados[eIndice] >= fSalarioMinimo && aSalarioEmpleados[eIndice] <= fSalarioMaximo){
			
			printf("\t%s, %.2f\n", aNombreEmpleados[eIndice], aSalarioEmpleados[eIndice]);
			
		}
	
	}

}

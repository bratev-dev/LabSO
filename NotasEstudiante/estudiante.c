#include <stdio.h>

#include "estudiante.h"

Estudiante estudiante;

void llenarEstudiante() // Procedimiento para almacenar los datos de un estudiante ingresados por el usuario
{
	printf("Digite el codigo del estudiante: ");
	fflush(stdin);
	gets(estudiante.codigo);	// Se pide y se almacena el codigo del estudiante
	
	printf("\nDigite el nombre del estudiante: ");
	fflush(stdin);
	gets(estudiante.nombre);	// Se pide y se almacena el nombre del estudiante
}

void calculoPromPeriodo()	// Procedimiento que calcula y almacena el promedio de cada periodo de un estudiante
{
	int n = 0; 	// Variable n para almacenar cantidad de notas a almacenar por periodo
	int aux = 0;	// Variable aux para validar cada nota antes de almacenarla en la estructura de estudiante
	float notas = 0;	// Variable notas para almacenar la sumatoria de notas durante un periodo
	for(int i = 0; i < 3; i++)	// Ciclo para iterar cada periodo
	{
		do{	// Ciclo para validar que la cantidad de notas a ingresar sea valida
			printf("\nDigite la cantidad de notas a ingresar para el periodo %d (maximo 5): ", (i+1));
			scanf("%d", &n);	// Lectura de la variable n
			if(n <= 0){	// Validacion adicional con advertencia para el usuario
				printf("\nDebe digitar una cantidad mayor a 0");
			}
		}while(n > 5 || n < 1);
		
		for(int j = 0; j < n; j++){	// Ciclo para iterar por la cantidad de notas establecidas por el usuario para un periodo
			do{	// Ciclo para validar que la nota ingresada sea valida
				printf("\nDigite la nota %d: ", (j+1));
				scanf("%d", &aux);	// Lectura de cada nota
				if(aux > 5 || aux < 0)	// Validacion adicional con advertencia para el usuario
				{
					printf("La nota debe ser valida (comprendida entre 0 y 5)");
				}
			}while(aux > 5 || aux < 0);
			
			notas += aux;	// Se agrega el valor actual de cada nota a la sumatoria de notas para un periodo
			aux = 0;	// Se reinicia la variable para almacenar nuevo valor del siguiente periodo
		}
		
		estudiante.notaPeriodo[i] = (notas / n);	// Almacenamiento de promedio para cada periodo
		
		notas = 0;	// Reinicio de la sumatoria para nuevo valor del siguiente periodo
		n = 0;	// Reinicio de la cantidad de notas para nuevo valor del siguiente periodo
	}
}

void mostrarEstudiante() // Procedimiento para mostrar todos los datos del estudiante
{
	float notaDef = 0;	// Variable notaDef para almacenar la nota definitiva del estudiante
	printf("DATOS ESTUDIANTE");
	printf("\nCodigo: %s", estudiante.codigo);	// Muestra el codigo del estudiante
	printf("\nNombre: %s", estudiante.nombre);	// Muestra el nombre del estudiante
	printf("\n\nPromedio por periodos:");
	
	for(int i = 0; i < 3; i++)	// Ciclo para iterar por cada periodo
	{
		printf("\nPromedio semestre %d: %.2f", (i+1), estudiante.notaPeriodo[i]);	// Se muestra el promedio de cada periodo
	}
	notaDef = (estudiante.notaPeriodo[0] * 0.35) + (estudiante.notaPeriodo[1] * 0.35) + (estudiante.notaPeriodo[2] * 0.3);	// Se calcula la ponderacion correspondiente a cada periodo
	printf("\n\n\tNota Definitiva: %.2f\n\n", notaDef);	// Se muestra la nota definitiva del estudiante
}
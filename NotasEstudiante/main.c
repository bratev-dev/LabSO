#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "estudiante.h"

/*
Autores: Brayan Steven Gomes Lasso
	 	 Juan David Perdomo Ramos
*/

int main(int argc, char *argv[]) {
	int opcion = 0; // Variable opcion almacena opcion elegida del menu por el usuario
	bool estudianteLleno;	// Variable estudianteLleno para validar que ya se llenaron los datos del estudiante
	bool notasLleno;	// Variable notasLleno para validar que ya se llenaron las notas del estudiante
	
	do{	// Ciclo para iterar hasta que el usuario digite la opcion de salir
		printf("===== MENU =====");	// Se muestra el menu de opciones al usuario
		printf("\n1. Llenar datos del estudiante.");
		printf("\n2. Llenar notas del estudiante.");
		printf("\n3. Mostrar datos del estudiante.");
		printf("\n4. Salir\n");
		scanf("%d", &opcion);	// Lectura de la opcion que elige el usuario
		system("cls");
		switch(opcion){	// Casos posibles que puede elegir el usuario
			case 1:
				llenarEstudiante();	// Llamado al procedimiento que almacena los datos del estudiante
				estudianteLleno = true;	// Se valida que ya se llenaron los datos del estudiante
				system("cls");	// Limpiar pantalla
				break;
			
			case 2:
				calculoPromPeriodo();	// Llamado a procedimiento que calcula y almacena el promedio de cada periodo
				notasLleno = true;	// Se valida que ya se llenaron las notas del estudiante
				system("cls");
				break;

			case 3:
				if(!estudianteLleno || !notasLleno)	// Se valida que ya se hayan llenado los datos y notas del estudiante
				{
					printf("\nPrimero debe llenar los datos y las notas del estudiante para poder mostrar su informacion.\n"); // Se muestra advertencia y se rompe el ciclo
					break;
				}
				mostrarEstudiante();	// Se muestran los datos y notas del estudiante
				system("pause");
				system("cls");
				break;
				
			case 4:
				printf("\nSaliendo ...\n");	// Advierte al usuario que esta saliendo del programa
				break;
				
			default:
				printf("\nDigite una opcion valida\n");	// Advierte al usuario para que digite una opcion valida
				break;
		}	
	}while(opcion != 4);
	
	return 0;
}
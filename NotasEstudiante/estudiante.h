typedef struct{
	char codigo[10];
	char nombre[30];
	float notaPeriodo[3];
}Estudiante;

void llenarEstudiante();	// Procedimiento para almacenar los datos de un estudiante ingresados por el usuario
void calculoPromPeriodo();	// Procedimiento que calcula y almacena el promedio de cada periodo de un estudiante
void mostrarEstudiante();	// Procedimiento para mostrar todos los datos del estudiante
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//ESPECIALIDADES
typedef struct especialidade{
	float valorConsulta;
	char nome[100];
	struct medico *medicos;
}ESP;

typedef struct Elem_esp{
	ESP info;
	//struct Elem_esp *anterior;
	struct Elem_esp *seguinte;
}ELEM_ESP;

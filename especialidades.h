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
	//struct Elem_esp *esp_anterior;
	struct Elem_esp *esp_seguinte;
}ELEM_ESP;

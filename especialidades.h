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
	struct Elem_esp *seguinte;
}ELEM_ESP;

//FUNCOES
ESP criarEspec();
int inserirFimListaESP(ELEM_ESP **iniListaEsp, ELEM_ESP **fimListaEsp, ESP newEspecialidade);
int gravaFichEsp(ELEM_ESP *iniListaEsp);
int lerFichEsp(ELEM_ESP **iniListaEsp, ELEM_ESP **fimListaEsp);
void listarEspecialidades(ELEM_ESP *iniListaEsp);
void alteraConsulta(ELEM_ESP *iniListaEsp);

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define TOTAL_MED 45

typedef struct medico{
	int n_ordem, numero, NIF, telefone, dias_indisponivel;
	char nome[100], morada[100], especialidade[20], data_entrada[11], motivo_inactivo[200];
	bool disponibilidade;
}MEDICO;

typedef struct Elem{
	MEDICO info;
	struct Elem *seguinte;
}ELEM_MED;

//Menu
int menuMed();
//Funcoes de Medicos
MEDICO inserirMedico(int *num);
int inserirFimLista(ELEM_MED **iniLista, ELEM_MED **fimLista, MEDICO newMedico);
int listaMedicos(ELEM_MED *iniLista);
int getSize(ELEM_MED *iniLista, int total);
void listaAlfabetica(ELEM_MED *iniLista, int total);
//Funcoes de ficheiros
//int gravaMedicos(ELEM_MED *iniLista);
int gravaEspecialidadesMedicos(ELEM_MED *iniLista);
int lerMedicos(ELEM_MED *iniLista);
void limparLista(ELEM_MED **iniLista);

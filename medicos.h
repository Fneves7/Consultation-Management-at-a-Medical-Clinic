#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TOTAL_MED 45

//MEDICOS
typedef struct medico{
	int n_ordem, numero, NIF, telefone, disponibilidade;
	char nome[100], morada[100], especialidade[20], data_entrada[11];
}MEDICO;

typedef struct Elem{
	MEDICO info;
	//struct Elem *anterior;
	struct Elem *seguinte;
}ELEMENTO;


int menuMed();
MEDICO inserirMedico(int *num);
int inserirFimLista(ELEMENTO **iniLista, ELEMENTO **fimLista, MEDICO newMedico);
int listaMedicos(ELEMENTO *iniLista);
int getSize(ELEMENTO *iniLista, int total);
void listaAlfabetica(ELEMENTO *iniLista, int total);

//Ficheiros
int gravaMedicos(ELEMENTO *iniLista);
int gravaEspecialidadesMedicos(ELEMENTO *iniLista);
int lerMedicos(ELEMENTO *iniLista);
void limparLista(ELEMENTO **iniLista);

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TOTAL_MED 45

typedef struct medico{
	int n_ordem;
	char nome[100];
	int numero, NIF;
	char morada[100];
	int telefone;
	char data_entrada[11];
}MEDICO;

typedef struct elem{
	MEDICO info;
	struct elem *seguinte;
}ELEM;

int menuMed();
MEDICO inserirMedico(MEDICO medicos[], int num);
int inserirFimLista(ELEM **iniLista, MEDICO newMedico);

int gravaMedicos(MEDICO medico[], int num);
int lerMedicos(MEDICO medicos[]);
void listaMedicos(MEDICO medicos[], int num);

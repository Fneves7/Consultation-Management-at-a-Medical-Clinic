#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define TOTAL_MED 45

typedef struct medico{
	int n_ordem, numero, NIF, telefone;
	char nome[100], morada[100], data_entrada[11];
}MEDICO;

typedef struct elem{
	MEDICO info;
	struct elem *anterior, *seguinte;
}ELEMENTO;

int menuMed();
MEDICO inserirMedico(int *num);
int inserirFimLista(ELEMENTO **iniLista, ELEMENTO **fimLista, MEDICO newMedico);
int listaMedicos(ELEMENTO *iniLista);

int gravaMedicos(MEDICO medico[], int num);
int lerMedicos(MEDICO medicos[]);

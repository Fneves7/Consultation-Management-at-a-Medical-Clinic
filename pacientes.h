#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TOTAL_MED 45

typedef struct pacientes{
	int n_ordem;
	char nome[100];
	int numero, NIF;
	char morada[100];
	int telefone;
	char data_entrada[11];
}PACIENTE;

int menuPac();

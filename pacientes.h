#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TOTAL_MED 45

typedef struct pacientes{
	char nome[100];
	int SNS;
	int telefone;
	char morada[50];
	int NIF;
	char CC[12];
	char data_nascimento[11];
	int num;
}PACIENTE;

int menuPac();

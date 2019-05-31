#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define TOTAL_MED 45

typedef struct pacientes{
	char nome[100];
	int SNS;
	int telefone;
	char morada[50];
	int NIF;
	char CC[12];
	int data_nascimento;
	int num;
}PACIENTE;

int menuPac();
int inserirPaciente(PACIENTE pacientes[], int total);
int alteraNIF_Nome(PACIENTE pacientes[], int total);
void ordenaNome(PACIENTE pacientes[], int total);
void listarPorNome(PACIENTE pacientes[], int total);
int pesquisaPaciente(PACIENTE pacientes[], int total);
int listarDepoisDeData(PACIENTE pacientes[], int total);
int gravaFile(PACIENTE pacientes[], int total);
int lerFicheiro(PACIENTE pacientes[]);
int menuPacIni(int total);


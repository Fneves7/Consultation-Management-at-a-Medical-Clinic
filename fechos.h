#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//CONSULTAS
typedef struct consultas{
	char data[11],hora[5];
	int SNS, n_ordem;
	struct especialidade *especialidades;
	struct medico *medicos;
	struct pacientes *paciente;
}CONSULTA;

typedef struct Elem_cons{
	CONSULTA info;
	struct Elem_cons *seguinte;
}ELEM_CONS;

int inserirFimListaCons(ELEM_CONS **iniListaCons, CONSULTA newConsulta);
int gravaFichCons(ELEM_CONS *iniListaCons);
int lerFichCons(ELEM_CONS *iniListaCons);

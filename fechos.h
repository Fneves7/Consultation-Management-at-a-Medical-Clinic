#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//FECHOS
/*typedef struct fechos{
	float valorPago;
	struct medico *medicos;
	struct pacientes *paciente;
}FECHO;

typedef struct Elem_fech{
	FECHO info;
	struct Elem_fech *seguinte;
}ELEM_FECH;*/

//CONSULTAS
typedef struct consultas{
	char data[11];
	struct medico *medicos;
	struct especialidade *especialidades;
	struct pacientes *paciente;
}CONSULTA;

typedef struct Elem_cons{
	CONSULTA info;
	struct Elem_cons *seguinte;
}ELEM_CONS;


int menuFecho();
//CONSULTA marcarConsulta(PACIENTE pacientes[], int total);
int inserirFimListaCons(ELEM_CONS **iniLista, CONSULTA newConsulta);
void listarConsultas(ELEM_CONS *iniLista);

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

/*
int RelatorioFechoDia(ELEM_CONS *iniListaCons, char data[]){
	//no final do dia deve ser elaborado um relat�rio com as consultas feitas no dia, valores pagos e somat�rio dos valores pagos. 
	//O relat�rio deve ser impresso para ficheiro de texto. O dia deve fazer parte do nome do ficheiro. Esta op��o est� tamb�m dispon�vel para qualquer dia � escolha do utilizador
	ELEM_CONS *aux=NULL;
	FILE*fp=NULL;
	char nomeFicheiro[30];
	float soma=0;
	
	sprintf(nomeFicheiro, "relat-dia-%s.txt", data); 
	
	fp = fopen(nomeFicheiro, "w");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro \n");
		return -1;
	}
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
		if(stricmp(aux->info.data, data) <= 0){ 
			fprintf(fp,"Data consulta: %s\n",aux->info.data);
			fprintf(fp,"Medico consulta: %s\n",aux->info.medicos->nome);
			fprintf(fp,"Paciente consulta: %s\n",aux->info.paciente->nome);
			fprintf(fp,"Pre�o consulta: %s\n",aux->info.especialidades->valorConsulta);
			sleep(1);
		}
	}
	fclose(fp);
	printf("Relat�rio efetuado com sucesso!\n");
	return -1;
}

void FechoDia(ELEM_CONS *iniListaCons){
	char data[11];
	printf("Introduza o dia (AAAA-MM-DD): ");
	fflush(stdin);
	gets(data);
	RelatorioFechoDia(iniListaCons, data);
}*/

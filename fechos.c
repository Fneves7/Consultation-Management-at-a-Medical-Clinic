#include "fechos.h"
#include "especialidades.h"
#include "medicos.h"
#include "pacientes.h"

//CRIAR CONSULTA
CONSULTA marcarConsulta(PACIENTE pacientes[], int total){
	
	CONSULTA consulta;	
	int i=0, sns=0;
	
	if(total == 0){
		printf("Nao existem pacientes no sistema!\n");
	}
	
	printf("Introduza o SNS do paciente:\n");
	scanf("%i", &sns);
	
	for(i=0; i< total; i++){
		//printf("Nome: %s; CC: %s; SNS: %i; NIF: %i; Telefone: %i; Data de nascimento: %i; Morada: %s; Numero: %i\n",\
	//	pacientes[i].nome, pacientes[i].CC, pacientes[i].SNS, pacientes[i].NIF, pacientes[i].telefone, pacientes[i].data_nascimento, pacientes[i].morada, pacientes[i].num);
		
		if(sns == pacientes[i].SNS){
			printf("SNS Existente \n");
			
			printf("Introduza a data de inicio(Formato AAAA-MM-DD)\n");
			fflush(stdin); gets(consulta.data);
		}else{
			printf("SNS Inválido \n"); 
			system("pause"); 
			return;
		}
	}
	
	printf("Data inserida: %s", consulta.data);
	system("pause");
	return consulta;
}

int inserirFimListaCons(ELEM_CONS **iniLista, CONSULTA newConsulta){
	
	ELEM_CONS *novo=NULL;
	novo = (ELEM_CONS *) calloc(1,sizeof(ELEM_CONS));
	if(novo==NULL){
		printf("Out of memory \n");
		return -1;
	}
	
	novo->info = newConsulta;
	novo->seguinte = NULL;
	
	if((*iniLista)==NULL){
		(*iniLista)=novo;
	}else{novo->seguinte=(*iniLista);
		(*iniLista)=novo;
	}
	return 0;
}


void listarConsultas(ELEM_CONS *iniLista){
	ELEM_CONS *aux=NULL;
	
	if(iniLista == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}
	
	for(aux=iniLista; aux != NULL; aux = aux->seguinte){
		printf("Data da consulta: %s\n", aux->info.data);
	}
	system("pause");
	return;
}

int RelatorioFechoDia(ELEM_CONS *iniLista, char data[]){
	//no final do dia deve ser elaborado um relatório com as consultas feitas no dia, valores pagos e somatório dos valores pagos. 
	//O relatório deve ser impresso para ficheiro de texto. O dia deve fazer parte do nome do ficheiro. Esta opção está também disponível para qualquer dia à escolha do utilizador
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
	
	for(aux=iniLista; aux != NULL; aux = aux->seguinte){
		if(stricmp(aux->info.data, data) <= 0){ 
			fprintf(fp,"Data consulta: %s\n",aux->info.data);
			fprintf(fp,"Medico consulta: %s\n",aux->info.medicos->nome);
			fprintf(fp,"Paciente consulta: %s\n",aux->info.paciente->nome);
			fprintf(fp,"Preço consulta: %s\n",aux->info.especialidades->valorConsulta);
			sleep(1);
		}
	}
	fclose(fp);
	printf("Relatório efetuado com sucesso!\n");
	return -1;
}

void FechoDia(ELEM_CONS *iniLista){
	char data[11];
	printf("Introduza o dia (AAAA-MM-DD): ");
	fflush(stdin);
	gets(data);
	RelatorioFechoDia(iniLista, data);
}


//MENU DOS FECHOS
int printFechoMenu(int opc){
	setlocale(LC_ALL, "Portuguese");

	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE FECHOS\n\n");
	printf("Introduza a opcao:\n");
	
	printf("1 - Marcar uma consulta para um medico para uma determinada data/hora\n");
	printf("2 - Listar todas as consultas marcada até agora\n");
	printf("3 - Listar todas a consultas de um determinado médico\n");
	printf("4 - Listar todas a consultas de um determinado médico para um determinado dia\n");
	printf("5 - Listar todas as consultas de uma determinada especialidade\n");
	printf("6 - Simular o atendimento de um paciente: informar o cliente sobre o total a pagar, registar hora de realização da consulta e receber o pagamento\n");
	printf("7 - Listar todas as consultas de um determinado paciente (nº), ao longo dos tempos\n");
	printf("8 - Listar nome e data de nascimento dos pacientes de um determinado médico\n");
	printf("9 - Listar todas as consultas marcadas, mas que não foram realizadas (por ex. porque o paciente faltou)\n");
	printf("10 - Saber, por cada especialidade, quanto foi recebido em consultas até agora\n");
	printf("11 - Saber, qual o tempo médio de espera das consultas, partindo do princípio de que o paciente chega na hora marcada para a consulta\n");
	printf("12 - Fecho do dia\n");
	printf("13 - Fecho do mês: deve ser permitido elaborar um relatório mensal, onde devem ser listadas todas as consultas efetuados durante um mês, valores recebidos e somatório dos valores. Esta opção deve estar disponível para qualquer mês introduzido pelo utilizador. O relatório deve ser impresso para ficheiro de texto onde o ano e mês deve fazer parte do nome do ficheiro\n");
	printf("14 - Fecho do ano: no fecho do ano, deve apresentar o somatório de valores pagos pelas consultas em cada mês, assim como o somatório anual e o valor total de IVA a pagar, sabendo que as consultas pagam 6% de IVA\n");
	
	printf("0- Sair\n");
	printf(">"); scanf("%i",&opc);
	return opc;
}

int menuFecho(){
		int opc=0, total = 0;
		char data[12],dataPagamento[12];
		
		CONSULTA newConsulta;
		PACIENTE pacientes[100];
	
		total=lerFicheiro(pacientes);
		ELEM_CONS *iniLista = NULL;
		
		do{
		opc=printFechoMenu(opc);
		switch(opc){
			default: printf("Opcao Errada\n"); system("pause"); break;
			case 0:	return -1; break;
			case 1:
				newConsulta=marcarConsulta(pacientes, total);  
				inserirFimListaCons(&iniLista, newConsulta); 
			break;
			case 2:listarConsultas(iniLista); break;
				

			case 12: printf("Fecho do Dia\n"); FechoDia(iniLista); break;
		}
	}while(opc != 0);
}



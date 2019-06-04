#include "fechos.h"
#include "especialidades.h"
#include "medicos.h"
#include "pacientes.h"

//CRIAR CONSULTA
CONSULTA marcarConsulta(ELEM_MED *iniLista){
	//PACIENTE pacientes[];
	ELEM_MED *medico = NULL;
	CONSULTA consulta;	
	int i=0;
	char data[11], hora[5];
	
	if(iniLista==NULL){
        printf("Erro: Não existem dados de medicos!\n");
        system("pause");
        system("cls");
        return;
    }
	
	printf("Introduza o Numero da Ordem do Medico:\n");
	scanf("%i", &consulta.n_ordem);
	
	for(medico = iniLista; medico != NULL; medico=medico->seguinte){
		if(consulta.n_ordem == medico->info.n_ordem){
			
			printf("Introduza a data da consulta(AAAA-MM-DD):\n");
			fflush(stdin);gets(consulta.data);
			
			printf("Introduza agora a hora (00:00):\n");
			fflush(stdin);gets(consulta.hora);
			
			printf("Data:%s - Hora:%s - Medico:%s\n", consulta.data, consulta.hora, medico->info.nome);
		}
	}
	system("pause");
	return consulta;
}

int inserirFimListaCons(ELEM_CONS **iniListaCons, CONSULTA newConsulta){
	
	ELEM_CONS *novo=NULL;
	novo = (ELEM_CONS *) calloc(1,sizeof(ELEM_CONS));
	if(novo==NULL){
		printf("Out of memory \n");
		return -1;
	}
	
	novo->info = newConsulta;
	novo->seguinte = NULL;
	
	if((*iniListaCons)==NULL){
		(*iniListaCons)=novo;
	}else{novo->seguinte=(*iniListaCons);
		(*iniListaCons)=novo;
	}
	return 0;
}

void listarConsultas(ELEM_CONS *iniListaCons, ELEM_MED *iniLista){
	
	ELEM_CONS *aux=NULL;
	ELEM_MED *medico = NULL;
	
	if(iniListaCons == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
		for(medico = iniLista; medico != NULL; medico=medico->seguinte){
			if(aux->info.n_ordem == medico->info.n_ordem){
				printf("Data:%s - Hora:%s - Medico:%s\n", aux->info.data, aux->info.hora, medico->info.nome);
			}
		}
	}
	system("pause");
	return;
}

void listarConsMed(ELEM_CONS *iniListaCons, ELEM_MED *iniLista){
	
	ELEM_CONS *aux=NULL;
	ELEM_MED *medico = NULL;
	int n_ordem=0;
	
	if(iniListaCons == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}
	
	printf("Introduza o Numero da Ordem do Medico:\n");
	scanf("%i", &n_ordem);
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
		if(n_ordem==aux->info.n_ordem){
			for(medico = iniLista; medico != NULL; medico=medico->seguinte){
				if(n_ordem == medico->info.n_ordem){
					printf("Data:%s - Hora:%s - Medico:%s\n", aux->info.data, aux->info.hora, medico->info.nome);
				}
			}
		}
	}
	system("pause");
	return;
}

void listarConsMedDia(ELEM_CONS *iniListaCons, ELEM_MED *iniLista){
	
	ELEM_CONS *aux=NULL;
	ELEM_MED *medico = NULL;
	int n_ordem=0;
	char data[11];
	
	if(iniListaCons == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}
	
	printf("Introduza o Numero da Ordem do Medico:\n");
	scanf("%i", &n_ordem);
	
	printf("Introduza a data que deseja consultar (AAAAMMDD):\n");
	fflush(stdin);gets(data);
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
		if(n_ordem==aux->info.n_ordem){
			for(medico = iniLista; medico != NULL; medico=medico->seguinte){
				if(n_ordem == medico->info.n_ordem && strcmp(data, aux->info.data) == 0){
					printf("Hora:%s - Medico:%s\n", aux->info.data, aux->info.hora, medico->info.nome);
				}
			}
		}
	}
	system("pause");
	return;
}

void listarConsEsp(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	
	ELEM_CONS *aux=NULL;
	ELEM_ESP *espec = NULL;
	ELEM_MED *medico = NULL;
	char especialidade[100];
	
	if(iniListaCons == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}
	
	if(iniListaEsp==NULL){
        printf("Erro: Não existem dados de especialidades!\n");
        system("PAUSE");
        system("cls");
        return;
    }
	
	if(iniLista==NULL){
        printf("Erro: Não existem dados de medicos!\n");
        system("pause");
        system("cls");
        return;
    }
	
	printf("Introduza o nome da especialidade:\n");
	fflush(stdin);gets(especialidade);

	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
				
		for(medico = iniLista; medico != NULL; medico=medico->seguinte){
			if(aux->info.n_ordem == medico->info.n_ordem && strcmp(especialidade, medico->info.especialidade) == 0){
				printf("Data:%s - Hora:%s - Medico:%s\n", aux->info.data, aux->info.hora, medico->info.nome);
			}
		}
	}
	
	system("pause");
	return;
}


//: deve ser permitido elaborar um relatório mensal, onde devem ser listadas todas as consultas efetuados durante um mês, 
//valores recebidos e somatório dos valores. Esta opção deve estar disponível para qualquer mês introduzido pelo utilizador. O relatório deve ser impresso para ficheiro de texto onde o ano e mês deve fazer parte do nome do ficheiro

//: no fecho do ano, deve apresentar o somatório de valores pagos pelas consultas em cada mês, 
//assim como o somatório anual e o valor total de IVA a pagar, sabendo que as consultas pagam 6% de IVA

//MENU DOS FECHOS
int printFechoMenu(int opc){
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE FECHOS\n\n");
	printf("Introduza a opcao:\n");
	printf("1 - Marcar uma consulta para um medico para uma determinada data/hora\n"); //FEITO
	printf("2 - Listar todas as consultas marcada até agora\n");//FEITO
	printf("3 - Listar todas a consultas de um determinado médico\n");//FEITO
	printf("4 - Listar todas a consultas de um determinado médico para um determinado dia\n");//FEITO
	printf("5 - Listar todas as consultas de uma determinada especialidade\n");//FEITO

	printf("6 - Simular o atendimento de um paciente: informar o cliente sobre o total a pagar, registar hora de realização da consulta e receber o pagamento\n");
	printf("7 - Listar todas as consultas de um determinado paciente (nº), ao longo dos tempos\n");
	printf("8 - Listar nome e data de nascimento dos pacientes de um determinado médico\n");
	printf("9 - Listar todas as consultas marcadas, mas que não foram realizadas (por ex. porque o paciente faltou)\n");

	printf("10 - Saber, por cada especialidade, quanto foi recebido em consultas até agora\n");
	printf("11 - Saber, qual o tempo médio de espera das consultas, partindo do princípio de que o paciente chega na hora marcada para a consulta\n");
	printf("12 - Fecho do dia\n");
	printf("13 - Fecho do mês\n");
	printf("14 - Fecho do ano\n\n");	
	printf("0- Sair\n\n");
	printf(">"); scanf("%i",&opc);
	return opc;
}

int menuFecho(){
		int opc=0, total = 0;
		char data[12],dataPagamento[12];
		
		CONSULTA newConsulta;
		PACIENTE pacientes[100];
		
		ELEM_CONS *iniListaCons = NULL;
		ELEM_ESP *iniListaEsp=NULL, *fimListaEsp=NULL;
		ELEM_MED *iniLista=NULL;
		
		lerFicheiroMed(&iniLista);
		lerFichEsp(&iniListaEsp,&fimListaEsp);
		total=lerFicheiro(pacientes);
		
		
		do{
		opc=printFechoMenu(opc);
		switch(opc){
			default: printf("Opcao Errada\n"); system("pause"); break;
			case 0:	return -1; break;
			case 1:
				newConsulta=marcarConsulta(iniLista);  
				inserirFimListaCons(&iniListaCons, newConsulta); 
			break;
			
			case 2:listarConsultas(iniListaCons, iniLista); break;
			case 3:listarConsMed(iniListaCons, iniLista); break;
			case 4:listarConsMedDia(iniListaCons, iniLista); break;
			case 5:listarConsEsp(iniListaCons, iniLista, iniListaEsp); break;
				

			//case 12: printf("Fecho do Dia\n"); FechoDia(iniListaCons); break;
		}
	}while(opc != 0);
}

/*	

	if(total == 0){
		printf("Nao existem pacientes no sistema!\n");
		system("pause");
        system("cls");
		return;
	}

	printf("Introduza o SNS do paciente:\n");
	scanf("%i", &sns);*/
	
	/*for(i=0; i< total; i++){
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
	}*/

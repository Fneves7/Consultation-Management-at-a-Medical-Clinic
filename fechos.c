#include "fechos.h"
#include "especialidades.h"
#include "medicos.h"
#include "pacientes.h"

//#1
CONSULTA marcarConsulta(ELEM_MED *iniLista){
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
			
			printf("Introduza a data da consulta(AAAAMMDD):\n");
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

int gravaFichCons(ELEM_CONS *iniListaCons){
	int res = 0;
	FILE *fp=NULL;
	ELEM_CONS *aux;
	fp = fopen("consultas.dat","wb");
	
	for(aux = iniListaCons; aux != NULL; aux=aux->seguinte){
		fwrite(aux,sizeof(CONSULTA),1,fp);
		res++;
	}
	
	printf("Gravou %i consultas com sucesso.\n", res); 
	system("pause");
	
	fclose(fp);
	return 0;
}

int lerFichCons(ELEM_CONS *iniListaCons){
	int res = 0;
	FILE *fp=NULL;
	CONSULTA aux;
	fp = fopen("consultas.dat","rb");
	
	while(fread(&aux,sizeof(CONSULTA),1,fp)){
        inserirFimListaCons(iniListaCons, aux);
		res++;
	}
	printf("Leu: %i Consultas\n", res); system("pause");
	fclose(fp);
	return 0;
}

//#2
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

//#3
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

//#4
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

//#5
void listarConsEsp(ELEM_CONS *iniListaCons, ELEM_MED *iniLista){
	
	ELEM_CONS *aux=NULL;
	ELEM_MED *medico = NULL;
	char especialidade[100];
	
	if(iniListaCons == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
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


//#10
int lucroEspecialidade(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	ELEM_CONS *aux=NULL;
	ELEM_ESP *espec = NULL;
	ELEM_MED *medico = NULL;
	char especialidade[100];
	float valor=0,total=0;
	int count=0;
	
	if(iniListaCons == NULL){
		printf("Nao existem dados\n");
		system("pause"); return -1;
	}
	
	if(iniListaEsp==NULL){
        printf("Erro: Não existem dados de especialidades!\n");
        system("PAUSE");
        system("cls");
        return -1;
    }
	
	if(iniLista==NULL){
        printf("Erro: Não existem dados de medicos!\n");
        system("pause");
        system("cls");
        return -1;
    }
	
	printf("Introduza o nome da especialidade:\n");
	fflush(stdin);gets(especialidade);

	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){			
		for(medico = iniLista; medico != NULL; medico=medico->seguinte){
			if(aux->info.n_ordem == medico->info.n_ordem && strcmp(especialidade, medico->info.especialidade) == 0){
				for(espec = iniListaEsp; espec != NULL; espec=espec->seguinte){			
					if(strcmp(medico->info.especialidade, espec->info.nome) == 0){
						count++;
						printf("Data: %s - Hora: %s - Valor consulta %.2f \n", aux->info.data, aux->info.hora, espec->info.valorConsulta);
							valor=espec->info.valorConsulta;
                 			total=valor*count;
					}
				}
			}
		}
	}
	
	printf("Total recebido: %.2f \n", total);
	
	system("pause");
	return;
}

//#11
/*int tempoMedio(iniListaCons){
	
	ELEM_CONS *aux=NULL;
	int count=0, valor=0, total=0, a=0,b=0;
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
	
		a=atoi(&aux->info.hora);
		b=atoi(&aux->seguinte->info.hora);
		
		count++;
		total += a-b;
		//while(total==0){
		//}
	}
	printf("Tempo medio de espera: %i\n", total/count); sleep(1);
}*/

//#12
void RelatorioFechoDia(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp, char data[]){
	//no final do dia deve ser elaborado um relatório com as consultas feitas no dia, valores pagos e somatório dos valores pagos. 
	//O relatório deve ser impresso para ficheiro de texto. O dia deve fazer parte do nome do ficheiro. Esta opção está também disponível para qualquer dia à escolha do utilizador
	ELEM_CONS *aux=NULL;
	ELEM_MED *medico = NULL;
	ELEM_ESP *espec = NULL;
	FILE*fp=NULL;
	char nomeFicheiro[30];
	float valor=0,total=0;
	int count=0;
	
	sprintf(nomeFicheiro, "Relat-Dia-%s.txt", data); 
	
	fp = fopen(nomeFicheiro, "w");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro \n");
		return ;
	}
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
		for(medico = iniLista; medico != NULL; medico=medico->seguinte){
			for(espec = iniListaEsp; espec != NULL; espec=espec->seguinte){
                 if(strcmp(data,aux->info.data) == 0 && strcmp(medico->info.especialidade, espec->info.nome) == 0 && aux->info.n_ordem == medico->info.n_ordem){
					count++;
					printf("Data: %s - Hora: %s - Especialidade: %s - Medico: %s - Valor consulta %.2f \n", aux->info.data, aux->info.hora, espec->info.nome, medico->info.nome, espec->info.valorConsulta);
					fprintf(fp,"Data: %s - Hora: %s - Especialidade: %s - Medico: %s - Valor consulta %.2f \n", aux->info.data, aux->info.hora, espec->info.nome, medico->info.nome, espec->info.valorConsulta);
					valor=espec->info.valorConsulta;
    	         	total = total+valor;
				}
			}
		}
	}
	printf("Total recebido: %.2f \n", total);
	fprintf(fp,"Total recebido: %.2f \n", total);
	printf("Relatório exportado com sucesso!\n");
	system("pause");
	fclose(fp);
	return;
}

//#13
void RelatorioFechoMes(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp, char data[]){
	//: deve ser permitido elaborar um relatório mensal, onde devem ser listadas todas as consultas efetuados durante um mês, 
	//valores recebidos e somatório dos valores. Esta opção deve estar disponível para qualquer mês introduzido pelo utilizador. O relatório deve ser impresso para ficheiro de texto onde o ano e mês deve fazer parte do nome do ficheiro

	ELEM_CONS *aux=NULL;
	ELEM_MED *medico = NULL;
	ELEM_ESP *espec = NULL;
	FILE*fp=NULL;
	char nomeFicheiro[30], cutStr[]="", novadata[]="";
	float valor=0,total=0;
	int count=0;
	
	sprintf(nomeFicheiro, "Relat-Mes-%s.txt", data); 
	fp = fopen(nomeFicheiro, "w");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro \n");
		return;
	}
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
		for(medico = iniLista; medico != NULL; medico=medico->seguinte){
			for(espec = iniListaEsp; espec != NULL; espec=espec->seguinte){
				
				memmove(cutStr, aux->info.data,7);
				strcpy(novadata, cutStr);
				
                 if(strcmp(data, novadata) == 0 && strcmp(medico->info.especialidade, espec->info.nome) == 0 && aux->info.n_ordem == medico->info.n_ordem){
					count++;
					printf("Data: %s - Hora: %s - Especialidade: %s - Medico: %s - Valor consulta %.2f \n", aux->info.data, aux->info.hora, espec->info.nome, medico->info.nome, espec->info.valorConsulta);
					fprintf(fp,"Data: %s - Hora: %s - Especialidade: %s - Medico: %s - Valor consulta %.2f \n", aux->info.data, aux->info.hora, espec->info.nome, medico->info.nome, espec->info.valorConsulta);
					valor=espec->info.valorConsulta;
    	         	total = total+valor;
				}
			}
		}
	}
	printf("Total recebido: %.2f \n", total);
	fprintf(fp,"Total recebido: %.2f \n", total);
	printf("Relatório exportado com sucesso!\n");
	system("pause");
	fclose(fp);
	return;
}

//#14
void RelatorioFechoAno(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp, char data[]){

	//: no fecho do ano, deve apresentar o somatório de valores pagos pelas consultas em cada mês, 
	//assim como o somatório anual e o valor total de IVA a pagar, sabendo que as consultas pagam 6% de IVA

	ELEM_CONS *aux=NULL;
	ELEM_MED *medico = NULL;
	ELEM_ESP *espec = NULL;
	FILE*fp=NULL;
	char nomeFicheiro[30], cutStr[]="", novadata[]="";
	float valor=0,total=0, desconto=0;
	int count=0;
	
	sprintf(nomeFicheiro, "Relat-Ano-%s.txt", data); 
	fp = fopen(nomeFicheiro, "w");
	
	if(fp==NULL){
		printf("Erro ao abrir o ficheiro \n");
		return;
	}
	
	for(aux=iniListaCons; aux != NULL; aux = aux->seguinte){
		for(medico = iniLista; medico != NULL; medico=medico->seguinte){
			for(espec = iniListaEsp; espec != NULL; espec=espec->seguinte){
				
				memmove(cutStr, aux->info.data, 4);
				strcpy(novadata, cutStr);
				
                if(strcmp(data, novadata) == 0 && strcmp(medico->info.especialidade, espec->info.nome) == 0 && aux->info.n_ordem == medico->info.n_ordem){
					count++;
					printf("Data: %s - Hora: %s - Especialidade: %s - Medico: %s - Valor consulta %.2f \n", aux->info.data, aux->info.hora, espec->info.nome, medico->info.nome, espec->info.valorConsulta);
					fprintf(fp,"Data: %s - Hora: %s - Especialidade: %s - Medico: %s - Valor consulta %.2f \n", aux->info.data, aux->info.hora, espec->info.nome, medico->info.nome, espec->info.valorConsulta);
					valor = espec->info.valorConsulta;
    	         	total = total+valor;
				}
			}
		}
	}
	printf("%s, %s", data, novadata); system("pause");
	printf("Total recebido: %.2f \n", total);
	// total);IVA                  *= 1.06
	fprintf(fp,"Total recebido: %.2f \n", total);
	printf("Relatório exportado com sucesso!\n");
	system("pause");
	fclose(fp);
	return;
}

void FechoDia(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	char data[11];
	printf("Introduza o dia (AAAA-MM-DD):\n");
	fflush(stdin); gets(data);
	RelatorioFechoDia(iniListaCons, iniLista, iniListaEsp, data);
}

void FechoMes(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	char data[11];
	printf("Introduza o dia (AAAA-MM):\n");
	fflush(stdin); gets(data);
	RelatorioFechoMes(iniListaCons, iniLista, iniListaEsp, data);
}

void FechoAno(ELEM_CONS *iniListaCons, ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	char data[11];
	printf("Introduza o dia (AAAA):\n");
	fflush(stdin); gets(data);
	RelatorioFechoAno(iniListaCons, iniLista, iniListaEsp, data);
}

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
//
	printf("6 - Simular o atendimento de um paciente: informar o cliente sobre o total a pagar, registar hora de realização da consulta e receber o pagamento\n");
	printf("7 - Listar todas as consultas de um determinado paciente (nº), ao longo dos tempos\n");
	printf("8 - Listar nome e data de nascimento dos pacientes de um determinado médico\n");
	printf("9 - Listar todas as consultas marcadas, mas que não foram realizadas (por ex. porque o paciente faltou)\n");
//
	printf("10 - Saber, por cada especialidade, quanto foi recebido em consultas até agora\n"); //FEITO
	printf("11 - Saber, qual o tempo médio de espera das consultas, partindo do princípio de que o paciente chega na hora marcada para a consulta\n");
	printf("12 - Fecho do dia\n");//FEITO
	printf("13 - Fecho do mês\n");//FEITO
	printf("14 - Fecho do ano\n\n");//FEITO	
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
		lerFichCons(&iniListaCons);
		
		do{
		opc=printFechoMenu(opc);
		switch(opc){
			default: printf("Opcao Errada\n"); system("pause"); break;
			case 0:	gravaFichCons(iniListaCons); return -1; break;
			case 1:
				newConsulta=marcarConsulta(iniLista);  
				inserirFimListaCons(&iniListaCons, newConsulta); 
			break;
			
			case 2:listarConsultas(iniListaCons, iniLista); break;
			case 3:listarConsMed(iniListaCons, iniLista); break;
			case 4:listarConsMedDia(iniListaCons, iniLista); break;
			case 5:listarConsEsp(iniListaCons, iniLista); break;
			
			case 6: break;
			case 7: break;
			case 8: break;
			case 9: break;
			
			case 10:lucroEspecialidade(iniListaCons, iniLista, iniListaEsp); break;
			//case 11: tempoMedio(iniListaCons); break;
			case 12: printf("Fecho do Dia\n"); FechoDia(iniListaCons, iniLista, iniListaEsp); break;
			case 13: printf("Fecho do Mes\n"); FechoMes(iniListaCons, iniLista, iniListaEsp); break;
			case 14: printf("Fecho do Ano\n"); FechoAno(iniListaCons, iniLista, iniListaEsp);break;
			
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

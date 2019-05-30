#include "medicos.h"
#include "especialidades.h"

ESP criarEspec(){
	
	ESP espec;
		
	fflush(stdin);
	printf("Introduza o nome da especialidade:\n");
	gets(espec.nome);
	
	printf("Introduza o valor da consulta:\n");
	scanf("%f", &espec.valorConsulta);
	
	printf("Especialidade:%s - Valor da consulta: %.2f\n", espec.nome, espec.valorConsulta);
	system("pause");
	
	return espec;
}

int inserirFimListaESP(ELEM_ESP **iniListaEsp, ELEM_ESP **fimListaEsp, ESP newEspecialidade){
	
	ELEM_ESP *novo = NULL, *aux=NULL;
	novo = (ELEM_ESP *) calloc(1, sizeof(ELEM_ESP));
	
	if(novo == NULL){
		printf("OUT OF MEMORY!\n"); 
		return -1;
	}
	novo->info = newEspecialidade;
	novo->seguinte = NULL;
	
	if(*iniListaEsp == NULL){
		*iniListaEsp = novo;
		}else{
			aux =*iniListaEsp;
			while(aux->seguinte != NULL){ aux=aux->seguinte; }
			aux->seguinte=novo;
	}return 0;
}

void listarEspecialidades(ELEM_ESP *iniListaEsp){
	
	ELEM_ESP *aux=NULL;
	if(iniListaEsp == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}
	
	printf("Especialidades:\n");
	for(aux = iniListaEsp; aux != NULL; aux=aux->seguinte){
		printf("%s - Valor da consulta: %.2f\n", aux->info.nome, aux->info.valorConsulta);
	}
	system("pause");
}

void alteraConsulta(ELEM_ESP *iniListaEsp){
	
	char nome[100];
	float valor=0;
	ELEM_ESP *aux=NULL;

    if(iniListaEsp==NULL){
        printf("Erro: N�o existem dados!\n");
        system("PAUSE");
        system("cls");
        return;
    }
	
	fflush(stdin);
	printf("Int. o nome da especialidade:\n");
	gets(nome);
	
	for(aux = iniListaEsp; aux != NULL; aux=aux->seguinte){
		
		if(strcmp(nome, aux->info.nome) == 0){
			
			printf("Int. o novo valor da consulta:\n");
			scanf("%f", &valor);	
			aux->info.valorConsulta=valor;
			//return aux;
		}
	}
}


//Zona dos m�dicos
MEDICO inserirMedico(int *num){
	
	MEDICO aux;
	(*num)++;
	aux.numero = (*num);
	
	if(aux.numero >= TOTAL_MED){
		printf("Nao aceita mais inscricoes!\n");
		system("pause");
		return;
	}
	
	printf("Introduza o n� da Ordem do M�dicos:\n");
	scanf("%i", &aux.n_ordem);
	
	fflush(stdin);
	printf("Introduza o nome:\n");
	gets(aux.nome);
	
	printf("Introduza o NIF:\n");
	scanf("%i", &aux.NIF);
	
	fflush(stdin);
	printf("Introduza a morada:\n");
	gets(aux.morada);
	
	printf("Introduza n� de telefone:\n");
	scanf("%i", &aux.telefone);
	
	fflush(stdin);
	printf("Introduza a data da sua entrada:\t (ex: 00-00-00)\n");
	gets(aux.data_entrada);
	
	strcpy(aux.especialidade, "Indefinido");
	
	aux.disponibilidade = true;
	
	return aux;
}

int inserirFimLista(ELEM_MED **iniLista, ELEM_MED **fimLista, MEDICO newMedico){
	
	ELEM_MED *novo = NULL;
	novo = (ELEM_MED *) calloc(1, sizeof(ELEM_MED));
	
	if(novo == NULL){
		printf("OUT OF MEMORY!\n"); 
		return -1;
	}
	novo -> info = newMedico;
	novo -> seguinte = NULL;
	//novo->anterior=NULL;
	
	if(*iniLista == NULL){
		*iniLista = novo;
		*fimLista = novo;
		}else{
		//novo->anterior = *fimLista;
		(*fimLista)->seguinte=novo;	
		*fimLista = novo;
	}return 0; 
}

void limparLista(ELEM_MED **iniLista){
    ELEM_MED *aux=NULL, *prox=NULL;
    aux = (*iniLista);
    while(aux!=NULL){
        prox=aux->seguinte;
        free(aux);
        aux=prox;
    }
    (*iniLista)=NULL;
}

int listaMedicos(ELEM_MED *iniLista){
	
	ELEM_MED *aux=NULL;
	if(iniLista == NULL){
		printf("Nao existem dados\n");
		system("pause"); return -1;
	}
	
	for(aux = iniLista; aux != NULL; aux=aux->seguinte){
		printf("%i: %i - %s - %i - %s - %i - %s - Data de entrada: %s - ",
		aux->info.numero,
		aux->info.n_ordem,
		aux->info.nome,
		aux->info.NIF,
		aux->info.morada, 
		aux->info.telefone, 
		aux->info.especialidade,
		aux->info.data_entrada);
		
		if(aux->info.disponibilidade==true) {
            printf("Medico disponivel\n");
        }else {
            printf("Indisponivel\n Dias de baixa: %i\n", aux->info.dias_indisponivel);
        }
	}
	system("pause");
}

int gravaMedicos(ELEM_MED *iniLista){
	
	FILE *fp = NULL;
	ELEM_MED *aux=NULL;
	int res=0;
	fp=fopen("Medicos.dat", "ab");
	
	if(fp==NULL){
		printf("Erro no ficheiro!\n");
		system("pause"); 
		return -1;
	}
	
	printf("%i\n", sizeof(1));
	
	for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
		res=fwrite(&aux, sizeof(MEDICO), 1, fp);
	}
	printf("Escreveu %i elementos com sucesso.\n", res); system("pause");
	
	fclose(fp); 
	return 0;
}

int lerMedicos(ELEM_MED *iniLista){
	
	FILE *fp = NULL;
	ELEM_MED *aux=NULL;
	
	int res=0;
	fp=fopen("Medicos.dat", "rb");
	
	if(fp==NULL){
		printf("Erro ao ler ficheiro Medicos.dat!\n"); return -1;
	}
	
	for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
		res=fread(&aux, sizeof(MEDICO), 1, fp);
	}
	
/*	while(fread(&aux, sizeof(MEDICO), 1,fp)){
		printf("Nome: %s\n", aux->info.nome);	
		printf("Idade: %s\n", aux->info.especialidade);
	}*/
	
	
	printf("Leu %i elementos com sucesso.\n", res); system("pause");
	
	fclose(fp);
	return 0;
}

int gravaEspecialidadesMedicos(ELEM_MED *iniLista){
	
	int i=0;
	
	FILE *fp = NULL;
	MEDICO temp;
	ELEM_MED *aux=NULL;
	fp=fopen("Especialidades.txt", "w");
	
	if(fp==NULL){
		printf("Erro no ficheiro!\n");
		system("pause"); return -1;
	}
	
	for(i=0; i<TOTAL_MED; i++){
		for(aux = iniLista; aux->seguinte != NULL; aux=aux->seguinte){
			if(strcmp(aux->info.especialidade, aux->seguinte->info.especialidade) > 0){	
				temp = aux->info;
				aux->info = aux->seguinte->info;
				aux->seguinte->info = temp;
			}
		}
	}
	
	printf("Dados Gravados no ficheiro:\n");
	for(aux = iniLista; aux != NULL; aux = aux->seguinte){
		printf("%s - %s\n", aux->info.especialidade, aux->info.nome);
	}
	
	for(aux = iniLista; aux != NULL; aux = aux->seguinte){
		fprintf(fp,"%s - %s\n", aux->info.especialidade, aux->info.nome);
	}
	system("pause");
	fclose(fp); 
	return 0;
}


void alteraMedico(ELEM_MED *iniLista){
	
	int nordem=0, telefone=0;
	char morada[100];
	
	ELEM_MED *aux=NULL;

    if(iniLista==NULL){
        printf("Erro: N�o existem dados!\n");
        system("PAUSE");
        system("cls");
        return;
    }
	
	fflush(stdin);
	printf("Int. o numero da ordem dos medicos:\n");
	scanf("%i", &nordem);
	
	for(aux = iniLista; aux != NULL; aux=aux->seguinte){
		if(nordem == aux->info.n_ordem){
					
			fflush(stdin);
			printf("Int. a nova morada:\n");
			gets(morada);
			
			printf("Int. o novo numero de telefone:\n");
			scanf("%i", &telefone);
				
			strcpy(aux->info.morada, morada);
			aux->info.telefone=telefone;
			//return aux;
		}
	}
}

int getSize(ELEM_MED *iniLista, int total){
	ELEM_MED *aux=NULL;
	
	for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
		total++;
	}
	printf("[Funct. getSize]Tamanho de entradas: %i\n", total); system("pause");
	return total;
}

//sort em listas ligadas
//total = getTamanho
void listaAlfabetica(ELEM_MED *iniLista, int total){
	
	ELEM_MED *aux;
	MEDICO temp;
	int i = 0;
	
	printf("O total do getsize e de: %i\n", total);
	
	for(i=0; i<TOTAL_MED; i++){
		for(aux = iniLista; aux->seguinte != NULL; aux=aux->seguinte){
			if(strcmp(aux->info.nome, aux->seguinte->info.nome) > 0){	
				temp = aux->info;
				aux->info = aux->seguinte->info;
				aux->seguinte->info = temp;
			}
		}
	}
	
	//A FUNCIONAR POR ARRAY DE ESTRUTURAS
	/*int i=0, j=0, qtd=0;
	MEDICO medicos[TOTAL_MED];
	MEDICO aux;
	ELEM_MED *aux_medicos = NULL;
	
	if(iniLista == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}

	printf("Total registos: %i\n", total);
	
	 for(aux_medicos=iniLista;aux_medicos!=NULL;aux_medicos=aux_medicos->seguinte){
    	medicos[qtd]=aux_medicos->info;
    	qtd++;
	}
	
	for(i=0; i<qtd; i++){
		for(j=0;j<qtd-1;j++){
    		if(strcmp(medicos[j].nome, medicos[j+1].nome) > 0){
				aux = medicos[j+1];
				medicos[j+1] = medicos[j];
				medicos[j] = aux;
         	}
		}
				
		printf("%i: %i - %s - %i - %s - %i - %s\n",
		medicos[i].numero,
		medicos[i].n_ordem,
		medicos[i].nome,
		medicos[i].NIF,
		medicos[i].morada,
		medicos[i].telefone,
		medicos[i].data_entrada);
	}*/
	system("pause");
}

void ListaMedicoEsp(ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	
	ELEM_MED *medico = NULL;
	ELEM_ESP *espec = NULL;
	char string[100];
	
	if(iniListaEsp==NULL){
        printf("Erro: N�o existem dados de especialidades!\n");
        system("PAUSE");
        system("cls");
        return;
    }
	
	if(iniLista==NULL){
        printf("Erro: N�o existem dados de medicos!\n");
        system("pause");
        system("cls");
        return;
    }
    
    fflush(stdin);
    printf("Introduza uma especialidade valida:\n");
    gets(string);
    
	for(espec = iniListaEsp; espec != NULL; espec=espec->seguinte){
		if(strcmp(string, espec->info.nome) == 0){
			
			printf("Medicos da especialidade:\n");			
			for(medico = iniLista; medico != NULL; medico=medico->seguinte){
				if(strcmp(string, medico->info.especialidade) == 0){
					printf("%s - %s\n", string, medico->info.nome);
				}
			}
		}
	}
	system("pause");
}

void addEspecialidadeMedico(ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	
	ELEM_MED *medico = NULL;
	ELEM_ESP *espec = NULL;
	
	int nordem=0;
	char string[100];
	
	if(iniListaEsp==NULL){
        printf("Erro: N�o existem dados de especialidades!\n");
        system("PAUSE");
        system("cls");
        return;
    }
	
	if(iniLista==NULL){
        printf("Erro: N�o existem dados de medicos!\n");
        system("pause");
        system("cls");
        return;
    }
    
	printf("Int. o numero da ordem dos medicos:\n");
	scanf("%i", &nordem);
	
	for(medico = iniLista; medico != NULL; medico=medico->seguinte){
		if(nordem == medico->info.n_ordem){
			printf("Introduza uma especialidade valida:\n");
			fflush(stdin);
			gets(string);
			for(espec = iniListaEsp; espec != NULL; espec=espec->seguinte){			
				
				if(strcmp(string, espec->info.nome) == 0){
					strcpy(medico->info.especialidade, string);
					printf("Alterado com sucesso.\n");
					system("pause");
					return 0;
				}/*else{
					printf("Erro: especialidade desconhecida.\n");
					system("pause");
					return ;
				}*/
			}
			return 0;
		}/*else{
			printf("Erro: Numero da ordem invalido.\n");
			system("pause");
			return;
		}*/
	}
}


//menu de medicos
int menuMed(){
	setlocale(LC_ALL, "Portuguese");
	MEDICO newMedico;
	ESP newEspecialidade;
	ELEM_MED *iniLista=NULL, *fimLista=NULL;
	ELEM_ESP *iniListaEsp=NULL, *fimListaEsp=NULL;;
	int opc=0, num=0, total=0;
	
	lerMedicos(iniLista);
	
	do{
		system("cls");
		printf("\t\t CLINICA MEDICA\n\n");
		printf("\tMENU DE MEDICOS\n\n");
		printf("Introduza a opcao:\n\n");
		printf("1- Criar especialidades e pre�os das consultas\n"); //FEITO
		printf("2- Listar informa��o sobre as especialidades\n"); //FEITO
		printf("3- Alterar pre�os das consultas\n"); //FEITO
		printf("4- Acrescentar informa��o sobre um m�dico.\n"); //FEITO
		printf("5- Listar informa��o sobre todos os m�dicos da cl�nica por ordem alfab�tica do nome\n"); //FEITO tanto por array como por listas
		printf("6- Alterar a informa��o sobre o m�dico, nomeadamente a morada e n� telefone\n");//FEITO
		printf("7- Listar todos os m�dicos de uma determinada especialidade\n");//FEITO
		printf("8- Colocar um m�dico indispon�vel (por ex. doen�a) durante um per�odo de tempo, deixando de ter possibilidade de marcar consultas para esse per�odo\n");
		printf("9- Criar um ficheiro de texto com as especialidades e o nome dos respetivos m�dicos. A informa��o deve estar ordenada pelo nome da especialidade\n");//FEITO
		printf("10- Atribuir especialidade a um medico\n");//FEITO
		printf("11- Listar todos os medicos\n");//DEBUG
		printf("12- GETSIZE medicos\n");//DEBUG
		
		printf("0- voltar\n\n");
		printf(">"); scanf("%i",&opc);
		
		switch(opc){
			default: printf("Opcao Errada\n");
			case 0:
				gravaMedicos(iniLista); 
				return -1; 
			break;
			case 1:
				newEspecialidade = criarEspec();
				inserirFimListaESP(&iniListaEsp, &iniListaEsp, newEspecialidade);
			break;
			
			case 2: listarEspecialidades(iniListaEsp); break;			
			case 3: alteraConsulta(iniListaEsp); break;		
			case 4:
				newMedico = inserirMedico(&num);
				inserirFimLista(&iniLista, &fimLista, newMedico);
			break;
			
			case 5:
				getSize(iniLista, total);
				listaAlfabetica(iniLista, total);
				listaMedicos(iniLista);
			break;
			
			case 6: alteraMedico(iniLista); break;
			case 7: ListaMedicoEsp(iniLista, iniListaEsp); break;		
			case 8: /*por fazer*/ break;
			case 9: gravaEspecialidadesMedicos(iniLista); break;
			case 10: addEspecialidadeMedico(iniLista, iniListaEsp); break;
			case 11: listaMedicos(iniLista); break;
			case 12: getSize(iniLista, total); break;
		}
	}while(opc != 0);
}

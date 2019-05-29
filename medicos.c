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
	novo->esp_seguinte = NULL;
	
	if(*iniListaEsp == NULL){
		*iniListaEsp = novo;
		}else{
			aux =*iniListaEsp;
			while(aux->esp_seguinte != NULL){ aux=aux->esp_seguinte; }
			aux->esp_seguinte=novo;
	}return 0;
}

void listarEspecialidades(ELEM_ESP *iniListaEsp){
	
	ELEM_ESP *aux=NULL;
	if(iniListaEsp == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}
	
	printf("Especialidades:\n");
	for(aux = iniListaEsp; aux != NULL; aux=aux->esp_seguinte){
		printf("%s - Valor da consulta: %.2f\n", aux->info.nome, aux->info.valorConsulta);
	}
	system("pause");
}

void alteraConsulta(ELEM_ESP *iniListaEsp){
	
	char nome[100];
	float valor=0;
	ELEM_ESP *aux=NULL;

    if(iniListaEsp==NULL){
        printf("Erro: Não existem dados!\n");
        system("PAUSE");
        system("cls");
        return;
    }
	
	fflush(stdin);
	printf("Int. o nome da especialidade:\n");
	gets(nome);
	
	for(aux = iniListaEsp; aux != NULL; aux=aux->esp_seguinte){
		
		if(strcmp(nome, aux->info.nome) == 0){
			
			printf("Int. o novo valor da consulta:\n");
			scanf("%f", &valor);	
			aux->info.valorConsulta=valor;
			//return aux;
		}
	}
}

MEDICO inserirMedico(int *num){
	
	MEDICO aux;
	(*num)++;
	aux.numero = (*num);
	
	if(aux.numero >= TOTAL_MED){
		printf("Nao aceita mais inscricoes!\n");
		system("pause");
		return;
	}
	
	printf("Introduza o nº da Ordem do Médicos:\n");
	scanf("%i", &aux.n_ordem);
	
	fflush(stdin);
	printf("Introduza o nome:\n");
	gets(aux.nome);
	
	printf("Introduza o NIF:\n");
	scanf("%i", &aux.NIF);
	
	fflush(stdin);
	printf("Introduza a morada:\n");
	gets(aux.morada);
	
	printf("Introduza nº de telefone:\n");
	scanf("%i", &aux.telefone);
	
	fflush(stdin);
	printf("Introduza a data da sua entrada:\t (ex: 00-00-00)\n");
	gets(aux.data_entrada);
	
	return aux;
}

int inserirFimLista(ELEMENTO **iniLista, ELEMENTO **fimLista, MEDICO newMedico){
	
	ELEMENTO *novo = NULL;
	novo = (ELEMENTO *) calloc(1, sizeof(ELEMENTO));
	
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

void limparLista(ELEMENTO **iniLista){
    ELEMENTO *aux=NULL, *prox=NULL;
    aux = (*iniLista);
    while(aux!=NULL){
        prox=aux->seguinte;
        free(aux);
        aux=prox;
    }
    (*iniLista)=NULL;
}

int listaMedicos(ELEMENTO *iniLista){
	
	ELEMENTO *aux=NULL;
	if(iniLista == NULL){
		printf("Nao existem dados\n");
		system("pause"); return -1;
	}
	
	for(aux = iniLista; aux != NULL; aux=aux->seguinte){
		printf("%i: %i - %s - %i - %s - %i - %s\n",
		aux->info.numero,
		aux->info.n_ordem,
		aux->info.nome,
		aux->info.NIF,
		aux->info.morada, 
		aux->info.telefone, 
		aux->info.data_entrada);
	}
	system("pause");
}

int gravaMedicos(ELEMENTO *iniLista){
	
	FILE *fp = NULL;
	ELEMENTO *aux=NULL;
	int res=0;
	fp=fopen("Medicos.dat", "wb");
	
	if(fp==NULL){
		printf("Erro no ficheiro!\n");
		system("pause"); return -1;
	}
	
	for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
		fwrite(aux, sizeof(MEDICO), 1, fp);
	}
	fclose(fp); return 0;
}

int gravaEspecialidadesMedicos(ELEMENTO *iniLista){
	
	int i=0;
	
	FILE *fp = NULL;
	MEDICO temp;
	ELEMENTO *aux=NULL;
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

int lerMedicos(ELEMENTO *iniLista){
	
	FILE *fp = NULL;
	ELEMENTO *aux=NULL;
	
	int res=0;
	fp=fopen("Medicos.dat", "rb");
	if(fp==NULL){
		printf("Erro no ficheiro!\n"); return -1;		
	}
	
	fread(aux,sizeof(MEDICO),1,fp);
	
	while(!feof(fp)){
		printf("%i: %i - %s - %i - %s - %i - %s\n",
		aux->info.numero,
		aux->info.n_ordem,
		aux->info.nome,
		aux->info.NIF,
		aux->info.morada, 
		aux->info.telefone, 
		aux->info.data_entrada);
	}
	system("pause");
	
	fclose(fp);
	return res;
}

void alteraMedico(ELEMENTO *iniLista){
	
	int nordem=0, telefone=0;
	char morada[100];
	
	ELEMENTO *aux=NULL;

    if(iniLista==NULL){
        printf("Erro: Não existem dados!\n");
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

int getSize(ELEMENTO *iniLista, int total){
	ELEMENTO *aux=NULL;
	
	for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
		total++;
	}
	printf("[Funct. getSize]Tamanho de entradas: %i\n", total); 
	return total;
}

//sort em listas ligadas
//total = getTamanho
void listaAlfabetica(ELEMENTO *iniLista, int total){
	
	ELEMENTO *aux;
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
	ELEMENTO *aux_medicos = NULL;
	
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

//menu de medicos
int menuMed(){
	setlocale(LC_ALL, "Portuguese");
	MEDICO newMedico;
	ESP newEspecialidade;
	ELEMENTO *iniLista=NULL, *fimLista=NULL;
	ELEM_ESP *iniListaEsp=NULL, *fimListaEsp=NULL;;
	int opc=0, num=0, total=0;
	
	lerMedicos(iniLista);
	
	do{
		system("cls");
		printf("\t\t CLINICA MEDICA\n\n");
		printf("\tMENU DE MEDICOS\n\n");
		printf("Introduza a opcao:\n\n");
		printf("1- Criar especialidades e preços das consultas\n"); //FEITO
		printf("2- Listar informação sobre as especialidades\n"); //FEITO
		printf("3- Alterar preços das consultas\n"); //FEITO
		printf("4- Acrescentar informação sobre um médico.\n"); //FEITO inc isto é acrescentar nao adicionar
		printf("5- Listar informação sobre todos os médicos da clínica por ordem alfabética do nome\n"); //FEITO tanto por array como por listas
		printf("6- Alterar a informação sobre o médico, nomeadamente a morada e nº telefone\n");//FEITO
		printf("7- Listar todos os médicos de uma determinada especialidade\n");
		printf("8- Colocar um médico indisponível (por ex. doença) durante um período de tempo, deixando de ter possibilidade de marcar consultas para esse período\n");
		printf("9- Criar um ficheiro de texto com as especialidades e o nome dos respetivos médicos. A informação deve estar ordenada pelo nome da especialidade\n");
		printf("10- Listar todos os medicos\n");
		printf("0- voltar\n\n");
		printf(">"); scanf("%i",&opc);
		
		switch(opc){
			default: printf("Opcao Errada\n");
			case 0: return -1; break;
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
			
			case 7:
				//por fazer 
			break;
			case 8: 
				//por fazer
			break;
			
			case 9: gravaEspecialidadesMedicos(iniLista); break;
			case 10: listaMedicos(iniLista); break;
		}
	}while(opc != 0);
	gravaMedicos(iniLista);
}

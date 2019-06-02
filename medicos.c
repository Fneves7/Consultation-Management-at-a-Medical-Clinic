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

int gravaFichEsp(){
	
	FILE *fp=NULL;
	ESP aux;
	fp = fopen("especialidades.dat","ab");
	fwrite(&aux,sizeof(ESP),1,fp);
	fclose(fp);
	
	return 0;
}

int lerFichEsp(){
	FILE *fp=NULL;
	ESP aux;
	fp = fopen("especialidades.dat","rb");
	fread(&aux,sizeof(ESP),1,fp);
	printf("DADOS: %s\n", aux.nome); system("pause");
	fclose(fp);
	return 0;
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
        printf("Erro: Não existem dados!\n");
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


//Zona dos médicos
MEDICO inserirMedico(int *num){
	
	//FILE *fp = fopen("medicos.dat", "ab");
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
	
	strcpy(aux.especialidade, "Indefinido");
	
	aux.disponibilidade = true;
	
	printf("%i: %i - %s - %i - %s - %i - %s - Data de entrada: %s - ",
		aux.numero,
		aux.n_ordem,
		aux.nome,
		aux.NIF,
		aux.morada, 
		aux.telefone, 
		aux.especialidade,
		aux.data_entrada); system("pause");
	
	//fwrite(&aux, sizeof(MEDICO), 1,fp);
	//fclose(fp);
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
	
	if(*iniLista == NULL){
		*iniLista = novo;
		*fimLista = novo;
		}else{
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
            printf("Indisponivel - Motivo: %s - Dias de baixa: %i\n", aux->info.motivo_inactivo, aux->info.dias_indisponivel);
        }
	}
	system("pause");
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

//sort em listas ligadas
void ordemAlfabetica(ELEM_MED *iniLista){
	
	ELEM_MED *aux;
	MEDICO temp;
	int i = 0;
	
	if(iniLista==NULL){
        printf("Erro: Não existem dados!\n");
        system("PAUSE");
        system("cls");
        return;
    }
	
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

void listaMedicoEsp(ELEM_MED *iniLista, ELEM_ESP *iniListaEsp){
	
	ELEM_MED *medico = NULL;
	ELEM_ESP *espec = NULL;
	char string[100];
	
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
					return;
				}/*else{
					printf("Erro: especialidade desconhecida.\n");
					system("pause");
					return;
				}*/
			}
			return;
		}/*else{
			printf("Erro: Numero da ordem invalido.\n");
			system("pause");
			return;
		}*/
	}
}

void baixaMedico(ELEM_MED *iniLista){
	
	int nordem=0;
	char activar;
	ELEM_MED *aux=NULL;

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
			do{
	            printf("Medico disponivel? (s/n/S/N)\n");
	            fflush(stdin);
	            scanf("%c",&activar);
	            switch(activar){
	                case 's':   case 'S':
	                	aux->info.disponibilidade=true;
	                break;
	                case 'n':   case 'N':
	                    aux->info.disponibilidade=false;
	                    printf("Introduza o motivo de inactividade:\n");
	                    fflush(stdin);
						gets(aux->info.motivo_inactivo);

	                    printf("Introduza quantos dias vai estar inactivo:\n");
						scanf("%i", &aux->info.dias_indisponivel);						
						
	                    break;
	                default: printf("Opcao errada!\n"); break;
	            }
        	}while(activar!='s' && activar!='S' && activar!='n' && activar!='N');
		}
	}
}

int gravaMedicos(ELEM_MED *iniLista){
	
	//MEDICO aux;
	ELEM_MED *aux = NULL;
	FILE *fp = NULL;
	int res=0;
	fp=fopen("medicos.dat", "ab");
	
	if(fp==NULL){
		printf("Erro no ficheiro!\n");
		system("pause"); 
		return -1;
	}
	
	//fwrite(&aux, sizeof(MEDICO), 1,fp);
	for(aux = iniLista; aux != NULL; aux=aux->seguinte){
		res=fwrite(&aux, sizeof(MEDICO), TOTAL_MED, fp);
		printf("%s, em medicos.dat inserido com sucesso \n", aux->info.nome); 
	}
	
	printf("Escreveu %i elementos com sucesso.\n", res); 
	system("pause");
	
	fclose(fp);
	return 0;
}

MEDICO lerFicheiroMed(MEDICO newMedico){
	
	MEDICO aux;
	FILE *fp = NULL;
	int res=0;
	fp = fopen("medicos.dat", "rb");
	
	if(!fp){
		printf("Erro de ficheiro.\n"); 
		system("pause"); 
	}
	
      fread(&aux, sizeof(MEDICO), 1,fp);
    /*while(!feof(fp)){
		res = fread(&aux, sizeof(MEDICO), 1,fp);
		printf("numero da ordem: %i\n", aux.n_ordem);
		printf("Nome: %s\n", aux.nome);	
	}*/
	
	
	
	/*
	res = fread(&aux, sizeof(MEDICO), 1,fp);
		printf("%i: %i - %s - %i - %s - %i - %s - Data de entrada: %s - \n",
		aux.numero,
		aux.n_ordem,
		aux.nome,
		aux.NIF,
		aux.morada, 
		aux.telefone, 
		aux.especialidade,
		aux.data_entrada);
 */
	/*	while(fread(&aux, sizeof(MEDICO), 1,fp)){
		res = fread(&aux, sizeof(MEDICO), 1,fp);
		printf("Nome: %s\n", aux.nome);	
		printf("numero da ordem: %i\n", aux.n_ordem);
		
	}*/
	/*while(fread(&aux, sizeof(MEDICO), 1,fp)){
		res = fread(&aux, sizeof(MEDICO), 1,fp);
		printf("%i: %i - %s - %i - %s - %i - %s - Data de entrada: %s - \n",
		aux.numero,
		aux.n_ordem,
		aux.nome,
		aux.NIF,
		aux.morada, 
		aux.telefone, 
		aux.especialidade,
		aux.data_entrada);		
	} */
	printf("Leu %i elementos com sucesso.\n", res); 
	system("pause");
	
	fclose(fp);
	return aux;
}

/*int lerMedicos(ELEM_MED *iniLista){
	
	ELEM_MED *aux=NULL;
	FILE *fp = NULL;
	
	int res=0;
	fp=fopen("medicos.dat", "rb");
	
	if(fp==NULL){
		printf("Erro ao ler ficheiro Medicos.dat!\n"); 
		return 0;
	}
	
	/*while(!feof(fp)){
        res=fread(&aux,sizeof(MEDICO),1,fp);
        if(res){
            inserirMedico(aux);
        }
    }*/
	
	/*for(aux = iniLista; aux != NULL; aux=aux->seguinte){
		res=fread(&aux, sizeof(MEDICO), 1, fp);
        inserirMedico();
		printf("%i: %i - %s - %i - %s - %i - %s - Data de entrada: %s - ",
		aux->info.numero,
		aux->info.n_ordem,
		aux->info.nome,
		aux->info.NIF,
		aux->info.morada, 
		aux->info.telefone, 
		aux->info.especialidade,
		aux->info.data_entrada); system("pause");
	}
	
	printf("Leu %i elementos com sucesso.\n", res); 
	sleep(1);
	
	fclose(fp);
	return 0;
}*/


//ZONA DE MENUS
int printMedMenu(int total){
	
	int opc;
	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE MEDICOS\n\n");
	printf("Introduza a opcao:\n\n");
	printf("1- Criar especialidades e preços das consultas\n"); //FEITO
	printf("2- Listar informação sobre as especialidades\n"); //FEITO
	printf("3- Alterar preços das consultas\n"); //FEITO
	printf("4- Acrescentar informação sobre um médico.\n"); //FEITO
	printf("5- Listar informação sobre todos os médicos da clínica por ordem alfabética do nome\n"); //FEITO tanto por array como por listas
	printf("6- Alterar a informação sobre o médico, nomeadamente a morada e nº telefone\n");//FEITO
	printf("7- Listar todos os médicos de uma determinada especialidade\n");//FEITO
	printf("8- Colocar um médico indisponível (por ex. doença) durante um período de tempo, deixando de ter possibilidade de marcar consultas para esse período\n");//FEITO
	printf("9- Criar um ficheiro de texto com as especialidades e o nome dos respetivos médicos. A informação deve estar ordenada pelo nome da especialidade\n");//FEITO
	printf("10- Atribuir especialidade a um medico\n");//FEITO
	printf("11- Listar todos os medicos //DEBUG\n");//DEBUG
	printf("12- Gravar/Ler Binario //DEBUG\n");//DEBUG
	printf("13- LerFicheiro //DEBUG\n");//DEBUG
	
	printf("0- voltar\n\n");
	printf(">"); 
	scanf("%i",&opc);
	return opc;
}

//menu de medicos
int menuMed(){
	setlocale(LC_ALL, "Portuguese");
	int opc=0, num=0, total=0;
	
	ELEM_MED *iniLista=NULL, *fimLista=NULL;
	ELEM_ESP *iniListaEsp=NULL, *fimListaEsp=NULL;
	
	MEDICO newMedico;
	ESP newEspecialidade;
	
	newMedico=lerFicheiroMed(newMedico);
	inserirFimLista(&iniLista, &fimLista, newMedico);
	
	do{
		opc=printMedMenu(total);
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
				ordemAlfabetica(iniLista);
				listaMedicos(iniLista);
			break;
			
			case 6: alteraMedico(iniLista); break;
			case 7: listaMedicoEsp(iniLista, iniListaEsp); break;		
			case 8: baixaMedico(iniLista); break;
			case 9: gravaEspecialidadesMedicos(iniLista); break;
			case 10: addEspecialidadeMedico(iniLista, iniListaEsp); break;
			case 11: listaMedicos(iniLista); break;
			case 12: gravaMedicos(iniLista); gravaFichEsp(); break;
			case 13: lerFicheiroMed(newMedico); break;
		}
	}while(opc != 0);
}



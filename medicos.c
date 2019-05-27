#include "medicos.h"

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
	novo->anterior=NULL;
	
	if(*iniLista == NULL){
		*iniLista = novo;
		*fimLista = novo;
		}else{
		novo->anterior = *fimLista;
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
	
	FILE *fp = NULL;
	ELEMENTO *aux=NULL;
	fp=fopen("Especialidades.txt", "w");
	
	if(fp==NULL){
		printf("Erro no ficheiro!\n");
		system("pause"); return -1;
	}
	
	for(aux = iniLista; aux != NULL; aux = aux->seguinte){
		printf("Nomes Gravados em ficheiro:\n");
		printf("%s\n", aux->info.nome);
	}
	
	for(aux = iniLista; aux != NULL; aux = aux->seguinte){
		fprintf(fp,"%s\n", aux->info.nome);
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

int getSize(ELEMENTO *iniLista){
	int total=0;
	ELEMENTO *aux=NULL;
	
	for(aux=iniLista; aux!=NULL; aux=aux->seguinte){
		total++;
	}
	printf("%i Entradas\n", total); 
	//system("pause");
	return total;
}

//sort em listas ligadas
//total = getTamanho
void listaAlfabetica(ELEMENTO *iniLista, int total){
	
	int j=0, x=0, max=0, min=0;
	MEDICO aux[45];
	
	if(iniLista == NULL){
		printf("Nao existem dados\n");
		system("pause"); return;
	}

	printf("%i", total);

	for(x=0;x<total;x++){
		printf("%i: %i - %s - %i - %s - %i - %s\n",
		aux[x].numero,
		aux[x].n_ordem,
		aux[x].nome,
		aux[x].NIF,
		aux[x].morada,
		aux[x].telefone,
		aux[x].data_entrada);
	}
	system("pause");
}

//menu de medicos
int menuMed(){
	setlocale(LC_ALL, "Portuguese");
	MEDICO newMedico;
	ELEMENTO *iniLista=NULL, *fimLista=NULL;
	int opc=0, num=0, total = 0;
	
	do{
		system("cls");
		printf("\t\t CLINICA MEDICA\n\n");
		printf("\tMENU DE MEDICOS\n\n");
		printf("Introduza a opcao:\n\n");
		printf("1- Criar especialidades e preços das consultas\n");
		printf("2- Listar informação sobre as especialidades\n");
		printf("3- Alterar preços das consultas\n");
		printf("4- Acrescentar informação sobre um médico.\n");
		printf("5- Listar informação sobre todos os médicos da clínica por ordem alfabética do nome\n");
		printf("6- Alterar a informação sobre o médico, nomeadamente a morada e nº telefone\n");
		printf("7- Listar todos os médicos de uma determinada especialidade\n");
		printf("8- Colocar um médico indisponível (por ex. doença) durante um período de tempo, deixando de ter possibilidade de marcar consultas para esse período\n");
		printf("9- Criar um ficheiro de texto com as especialidades e o nome dos respetivos médicos. A informação deve estar ordenada pelo nome da especialidade\n");
		printf("0- voltar\n\n");
		printf(">"); scanf("%i",&opc);
		
		switch(opc){
			default: printf("Opcao Errada\n");
			case 0: return -1; break;
			
			case 2:
				listaMedicos(iniLista); 
			break;
			
			case 4:
				newMedico = inserirMedico(&num);
				inserirFimLista(&iniLista, &fimLista, newMedico);
			break;
			
			case 5:
				getSize(iniLista);
				listaAlfabetica(iniLista, total);
			break;
			
			case 9:
				gravaMedicos(iniLista);
				lerMedicos(iniLista);
			break;
			
			case 10: lerMedicos(iniLista); break;
			case 11: gravaEspecialidadesMedicos(iniLista); break;
		}
	}while(opc != 0);	
}

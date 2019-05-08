#include "medicos.h"

MEDICO inserirMedico(int *num){
	
	MEDICO aux;
	
	/*if(num >= TOTAL_MED){
		printf("Nao aceita mais inscricoes!\n");
		//return -1;
	}*/
	
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

int listaMedicos(ELEMENTO *iniLista){
	
	ELEMENTO *aux=NULL;
	if(iniLista <= NULL){
		printf("Nao existem dados\n"); 
		return -1;
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

int gravaMedicos(MEDICO medicos[], int n_ordem){
	FILE *fp = NULL; int res=0;
	fp=fopen("Medicos.dat", "wb");
	
	if(fp==NULL){
		printf("Erro no ficheiro!\n");
		return -1;
	}
	
	fwrite(&n_ordem, sizeof(int), 1, fp);
	res = fwrite(&medicos[0], sizeof(MEDICO), n_ordem, fp);
	printf("Escreveu %i registos\n", res);
	fclose(fp);
	return res;
}

int lerMedicos(MEDICO medicos[]){
	
	FILE *fp = NULL; 
	int n_ordem=0; int res=0;
	fp=fopen("Medicos.dat", "rb");
	if(fp==NULL){
		printf("Erro no ficheiro!\n"); return -1;		
	}
	
	res = fread(&n_ordem, sizeof(int), 1, fp);
	
	if(n_ordem > 0){
		res = fread(&medicos[0], sizeof(MEDICO), n_ordem, fp);
	}
	
	printf("Leu %i registos \n", res);
	
	fclose(fp);
	return n_ordem;
}

//menu de medicos
int menuMed(){
	setlocale(LC_ALL, "Portuguese");
	MEDICO newMedico;
	ELEMENTO *iniLista = NULL, *fimLista=NULL;
	int opc=0, num=0;

	do{
		system("cls");
		printf("\t\t CLINICA MEDICA\n\n");
		printf("\tMENU DE MEDICOS\n\n");
		printf("Introduza a opcao:\n\n");
		printf("1- Criar especialidades e preços das consultas\n");
		printf("2- Listar informação sobre as especialidades\n");
		printf("3- Alterar preços das consultas\n");
		printf("4- Acrescentar informação sobre um médico. A cada médico deve ser atribuído um codigo interno a aplicacao (n sequencial)\n");
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
			
			case 1: 
				newMedico = inserirMedico(&num);
				inserirFimLista(&iniLista, &fimLista, newMedico);
			break;
			
			case 2:
				listaMedicos(iniLista); 
			break;
			
		}		
	}while(opc != 0);	
}

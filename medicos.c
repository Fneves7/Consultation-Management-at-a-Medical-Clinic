#include "medicos.h"

//menu de medicos
int menuMed(){
	setlocale(LC_ALL, "Portuguese");
	MEDICO medicos[TOTAL_MED];
	int opc=0;

	do{
		system("cls");
		printf("\t\t CLINICA MEDICA\n\n");
		printf("\tMENU DE MEDICOS\n\n");
		printf("Introduza a opcao:\n\n");
		printf("1- Criar especialidades e pre�os das consultas\n");
		printf("2- Listar informa��o sobre as especialidades\n");
		printf("3- Alterar pre�os das consultas\n");
		printf("4- Acrescentar informa��o sobre um m�dico. A cada m�dico deve ser atribu�do um codigo interno a aplicacao (n sequencial)\n");
		printf("5- Listar informa��o sobre todos os m�dicos da cl�nica por ordem alfab�tica do nome\n");
		printf("6- Alterar a informa��o sobre o m�dico, nomeadamente a morada e n� telefone\n");
		printf("7- Listar todos os m�dicos de uma determinada especialidade\n");
		printf("8- Colocar um m�dico indispon�vel (por ex. doen�a) durante um per�odo de tempo, deixando de ter possibilidade de marcar consultas para esse per�odo\n");
		printf("9- Criar um ficheiro de texto com as especialidades e o nome dos respetivos m�dicos. A informa��o deve estar ordenada pelo nome da especialidade\n");
		printf("0- voltar\n");
		printf(">"); scanf("%i",&opc);
		
		switch(opc){
			case 1: inserirMedico(MEDICO medicos[], num); break;
			case 2: listarMedico(MEDICO medicos[], num); break;
			case 0: return -1; break;
			default: printf("Opcao Errada\n");			
		}		
	}while(opc != 0);	
}


MEDICO inserirMedico(MEDICO medicos[], int num){
	
	MEDICO aux;
	
	if(num >= TOTAL_MED){
		printf("Nao aceita mais inscricoes!\n");
		return 0;
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
	scanf("%i", &medicos[num].telefone);
	
	fflush(stdin);
	printf("Introduza a data da sua entrada:\t (ex: 00-00-00)\n");
	gets(aux.data_entrada);
	
	return aux;
}

int inserirFimLista(ELEM **iniLista, MEDICO newMedico){
	
	ELEM *novo = NULL, *aux=NULL;
	novo = (ELEM *) calloc(1, sizeof(ELEM));
	
	if(novo == NULL){
		printf("OUT OF MEMORY!\n"); 
		return -1;
	}
	novo -> info = newMedico;
	novo -> seguinte = NULL;
	
	if(*iniLista == NULL){
		*iniLista = novo;
		}else{
			aux =*iniLista;
			while(aux->seguinte != NULL){ aux=aux->seguinte; }
			aux->seguinte=novo;
	}return 0;
}

void listaMedicos(MEDICO medicos[], int num){
	int i=0;
	
	if(num <=0){
		printf("Nao existem dados\n");
		return;		
	}
	
	for(i=0; i<num; i++){
		printf("%i: %i - %s - %i - %s - %i - %s",
		medicos[num].numero,
		medicos[num].n_ordem,
		medicos[num].nome,
		medicos[num].NIF,
		medicos[num].morada, 
		medicos[num].telefone, 
		medicos[num].data_entrada);
	}
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

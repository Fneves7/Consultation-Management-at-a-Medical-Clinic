#include "pacientes.h"

//menu de pacientes e consultas
int menuPac(){
	PACIENTE aux;
	setlocale(LC_ALL, "Portuguese");
	int opc=0, num=0;
	int total=0;
	
	do{	
	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE PACIENTES E CONSULTAS\n\n");
	printf("Introduza a opcao:\n\n");
	printf("1- Acrescentar informacao sobre um novo paciente.\n");
	printf("2- Alterar os dados nº telefone e morada de um paciente.\n");
	printf("3- Listar pacientes por ordem alfabetica.\n");
	printf("4- Apresentar os dados de um cliente.\n");
	printf("5- Listar todos os clientes que nasceram depois de uma determinada data.\n");
	printf("0- Sair\n");
	printf(">"); scanf("%i",&opc);
	
	switch(opc){
		case 1:
			inserirPaciente(aux, num, total);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
	}
	
	}while(opc!=0);
	
	return opc;
}

int inserirPaciente(PACIENTE paciente, int *num, int total){
	PACIENTE aux;
	int i=0;
	
	(*num)++;
	aux.num=(*num);
	
	
	printf("Introduza os dados do paciente!\n");
	printf("Introduza o nome do paciente:\n");
	fflush(stdin);
	gets(aux.nome);
	printf("Introduza o numero de telefone do paciente:\n");
	scanf("%i", &aux.telefone);
	printf("Introduza a morada do paciente:\n");
	fflush(stdin);
	gets(aux.morada);
	printf("Introduza o numero do Serviço Nacional de Saúde do paciente:\n");
	scanf("%i", aux.SNS);
	printf("Introduza o NIF do paciente:\n");
	scanf("%i", aux.NIF);
	printf("Introduza o Cartao de Cidadao do paciente:\n");
	fflush(stdin);
	gets(aux.CC);
	printf("Introduza a data de nascimento do paciente (ex: 20-02-2019)");
	fflush(stdin);
	gets(aux.data_nascimento);
	
	for(i=0; i<total; i++){
		if(paciente[i].NIF == aux.NIF || (strcmp(paciente[i].CC, aux.CC)) || paciente[i].SNS == aux.SNS){
			printf("Paciente já existe no sistema!\n");
			return;
		}
	}
	
	strcpy(paciente[num].nome, aux.nome);
	paciente[num].telefone = aux.telefone;
	strcpy(paciente[num].morada, aux.morada);
	paciente[num].SNS = aux.SNS;
	paciente[num].NIF = aux.NIF;
	strcpy(paciente[num].CC, aux.CC);
	strcpy(paciente[num].data_nascimento, aux.data_nascimento);
	paciente[num].num=aux.num;
	
	return 1;
}



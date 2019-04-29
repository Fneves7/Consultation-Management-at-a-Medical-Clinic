#include "pacientes.h"

//menu de pacientes e consultas
int menuPac(){
	setlocale(LC_ALL, "Portuguese");
	int opc=0;
	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE PACIENTES E CONSULTAS\n\n");
	printf("Introduza a opcao:\n\n");
		
	printf("10- Acrescentar a informacao sobre um novo paciente. A cada novo paciente deve ser atribuido um codigo (n sequencial). So deve permitir inserir um novo paciente se a informacao sobre este ainda nao existe (verificar NIF, nCC ou nSNS)\n");
	printf("11- Alterar os dados de um paciente, nomeadamente o nº telefone e morada\n");
	printf("0- Listar os pacientes por ordem alfabetica do nome\n");
	printf("0- Apresentar os dados de um cliente, dado o nSNS\n");
	printf("0- Listar todos os clientes que nasceram depois de uma determinada data\n");
	
	printf("0- Sair\n");
	printf(">"); scanf("%i",&opc);
	return opc;
}



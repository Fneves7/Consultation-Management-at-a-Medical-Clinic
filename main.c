//CABECALHOS DAS BIBILIOTECAS C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//CABECALHOS FEITOS POR N�S
#include "medicos.h"
#include "pacientes.h"
#include "fechos.h"
//DEFINES
#define TOTAL_MED 45


int menu(){
	int opc=0;
	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("Introduza a opcao:\n\n");	
	printf("1- Medicos\n");
	printf("2- Pacientes\n");
	printf("3- Consultas e Fechos\n\n");	
	printf("0- Sair\n\n");
	printf(">"); scanf("%i",&opc);
	return opc;
}

int main(int argc, char *argv[]) {
	int opcao=0;
	do{
		opcao = menu();
		switch (opcao){
			case 1: menuMed(); break;
			case 2: menuPac(); break;
			case 3: menuFecho(); break;
			case 0: system("cls"); printf("\n\t\tA ENCERRAR APLICACAO...\n"); break;
			default: printf("Opcao errada!\n");
		}
	}while(opcao !=0);
	return 0;
}

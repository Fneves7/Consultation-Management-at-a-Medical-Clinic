#include "fechos.h"



//MENU DOS FECHOS
int printFechoMenu(int opc){
	setlocale(LC_ALL, "Portuguese");

	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE FECHOS\n\n");
	printf("Introduza a opcao:\n");
	
	printf("1 - Marcar uma consulta para um medico para uma determinada data/hora\n");
	printf("2 - Listar todas as consultas marcada at� agora\n");
	printf("3 - Listar todas a consultas de um determinado m�dico\n");
	printf("4 - Listar todas a consultas de um determinado m�dico para um determinado dia\n");
	printf("5 - Listar todas as consultas de uma determinada especialidade\n");
	printf("6 - Simular o atendimento de um paciente: informar o cliente sobre o total a pagar, registar hora de realiza��o da consulta e receber o pagamento\n");
	printf("7 - Listar todas as consultas de um determinado paciente (n�), ao longo dos tempos\n");
	printf("8 - Listar nome e data de nascimento dos pacientes de um determinado m�dico\n");
	printf("9 - Listar todas as consultas marcadas, mas que n�o foram realizadas (por ex. porque o paciente faltou)\n");
	printf("10 - Saber, por cada especialidade, quanto foi recebido em consultas at� agora\n");
	printf("11 - Saber, qual o tempo m�dio de espera das consultas, partindo do princ�pio de que o paciente chega na hora marcada para a consulta\n");
	printf("12 - Fecho do dia: no final do dia deve ser elaborado um relat�rio com as consultas feitas no dia, valores pagos e somat�rio dos valores pagos. O relat�rio deve ser impresso para ficheiro de texto. O dia deve fazer parte do nome do ficheiro. Esta op��o est� tamb�m dispon�vel para qualquer dia � escolha do utilizador\n");
	printf("13 - Fecho do m�s: deve ser permitido elaborar um relat�rio mensal, onde devem ser listadas todas as consultas efetuados durante um m�s, valores recebidos e somat�rio dos valores. Esta op��o deve estar dispon�vel para qualquer m�s introduzido pelo utilizador. O relat�rio deve ser impresso para ficheiro de texto onde o ano e m�s deve fazer parte do nome do ficheiro\n");
	printf("14 - Fecho do ano: no fecho do ano, deve apresentar o somat�rio de valores pagos pelas consultas em cada m�s, assim como o somat�rio anual e o valor total de IVA a pagar, sabendo que as consultas pagam 6% de IVA\n");
	
	printf("0- Sair\n");
	printf(">"); scanf("%i",&opc);
	return opc;
}

int menuFecho(){
		int opc=0;
	
		do{
		opc=printFechoMenu(opc);
		switch(opc){
			default: printf("Opcao Errada\n");
			case 0:		return -1;	break;
			case 1: printf("batatas"); sleep(1);
				
		
		}
	}while(opc != 0);
}



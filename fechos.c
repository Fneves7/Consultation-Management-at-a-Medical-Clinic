#include "fechos.h"

//menu dos fechos
int menuFecho(){
	setlocale(LC_ALL, "Portuguese");
	int opc=0;
	system("cls");
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE FECHOS\n\n");
	printf("Introduza a opcao:\n");
	
	printf("0 - Marcar uma consulta para um medico para uma determinada data/hora\n");
	printf("1 - Listar todas as consultas marcada até agora\n");
	printf("2 - Listar todas a consultas de um determinado médico\n");
	printf("3 - Listar todas a consultas de um determinado médico para um determinado dia\n");
	printf("4 - Listar todas as consultas de uma determinada especialidade\n");
	printf("5 - Simular o atendimento de um paciente: informar o cliente sobre o total a pagar, registar hora de realização da consulta e receber o pagamento\n");
	printf("6 - Listar todas as consultas de um determinado paciente (nº), ao longo dos tempos\n");
	printf("7 - Listar nome e data de nascimento dos pacientes de um determinado médico\n");
	printf("8 - Listar todas as consultas marcadas, mas que não foram realizadas (por ex. porque o paciente faltou)\n");
	printf("9 - Saber, por cada especialidade, quanto foi recebido em consultas até agora\n");
	printf("10 - Saber, qual o tempo médio de espera das consultas, partindo do princípio de que o paciente chega na hora marcada para a consulta\n");
	printf("11 - Fecho do dia: no final do dia deve ser elaborado um relatório com as consultas feitas no dia, valores pagos e somatório dos valores pagos. O relatório deve ser impresso para ficheiro de texto. O dia deve fazer parte do nome do ficheiro. Esta opção está também disponível para qualquer dia à escolha do utilizador\n");
	printf("12 - Fecho do mês: deve ser permitido elaborar um relatório mensal, onde devem ser listadas todas as consultas efetuados durante um mês, valores recebidos e somatório dos valores. Esta opção deve estar disponível para qualquer mês introduzido pelo utilizador. O relatório deve ser impresso para ficheiro de texto onde o ano e mês deve fazer parte do nome do ficheiro\n");
	printf("13 - Fecho do ano: no fecho do ano, deve apresentar o somatório de valores pagos pelas consultas em cada mês, assim como o somatório anual e o valor total de IVA a pagar, sabendo que as consultas pagam 6% de IVA\n");
	
	printf("0- Sair\n");
	printf(">"); scanf("%i",&opc);
	return opc;
}



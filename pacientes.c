#include "pacientes.h"

int inserirPaciente(PACIENTE pacientes[], int total){
	
	PACIENTE aux;
	int i=0;
	int j=0;
	
	aux.num=total;
	
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
	scanf("%i", &aux.SNS);
		
	printf("Introduza o NIF do paciente:\n");
	scanf("%i", &aux.NIF);
		
	printf("Introduza o Cartao de Cidadao do paciente:\n");
	fflush(stdin);
	gets(aux.CC);
		
	printf("Introduza a data de nascimento do paciente (ddmmyyyy):\n");
	scanf("%i", &aux.data_nascimento);
	
	
	for(i=0; i<=total; i++){
		if(pacientes[i].NIF == aux.NIF || (strcmp(pacientes[i].CC, aux.CC))==0|| pacientes[i].SNS == aux.SNS){
			printf("%i, %i.\n", pacientes[i].NIF, aux.NIF);
			printf("Paciente já existe no sistema!\n");
			return;
		}
	}
	
	fflush(stdin);
	strcpy(pacientes[total].nome, aux.nome);
	pacientes[total].telefone = aux.telefone;
	fflush(stdin);
	strcpy(pacientes[total].morada, aux.morada);
	pacientes[total].SNS = aux.SNS;
	pacientes[total].NIF = aux.NIF;
	fflush(stdin);
	strcpy(pacientes[total].CC, aux.CC);
	pacientes[total].data_nascimento = aux.data_nascimento;
	pacientes[total].num=aux.num;
	
	for(i=0; i<=total; i++){
		printf("Nome: %s; CC: %s; SNS: %i; NIF: %i; Telefone: %i; Data de nascimento: %i; Morada: %s; Numero: %i\n",\
		pacientes[i].nome, pacientes[i].CC, pacientes[i].SNS, pacientes[i].NIF, pacientes[i].telefone, pacientes[i].data_nascimento, pacientes[i].morada, pacientes[i].num);
	}
	
	return 1;
}

int alteraNIF_Nome(PACIENTE pacientes[], int total){
	int SNS, telf;
	char morada[50];
	int i=0;
	bool a;
	
	printf("Introduza o SNS do paciente para o qual pretende alterar os dados:\n");
	scanf("%i", &SNS);
	printf("Introduza o novo numero de telefone:\n");
	scanf("%i", &telf);
	printf("Introduza a nova morada:\n");
	fflush(stdin);
	gets(morada);
	
	for(i=0; i<total; i++){
		if(SNS == pacientes[i].SNS){
			a = true;
			break;
		}
	}
	
	if(a == true){
		pacientes[i].telefone = telf;
		strcpy(pacientes[i].morada, morada);
	}else{
		printf("SNS nao encontrado!\n");
	}
}

void ordenaNome(PACIENTE pacientes[], int total){
	int i=0, j=0, k=0;
	PACIENTE aux;
	
	for(j=0; j<total; j++){
		for(i=0; i<total-1; i++){
			if((strcmp(pacientes[i].nome,pacientes[i+1].nome) > 0)){
				aux=pacientes[i];
				pacientes[i]=pacientes[i+1];
				pacientes[i+1]=aux;
			}
		}
	}
}

void listarPorNome(PACIENTE pacientes[], int total){
	int i=0;

	if(total == 0){
		printf("Nao existem pacientes no sistema!\n");
	}
	
	for(i=0; i< total; i++){
		printf("Nome: %s; CC: %s; SNS: %i; NIF: %i; Telefone: %i; Data de nascimento: %i; Morada: %s; Numero: %i\n",\
		pacientes[i].nome, pacientes[i].CC, pacientes[i].SNS, pacientes[i].NIF, pacientes[i].telefone, pacientes[i].data_nascimento, pacientes[i].morada, pacientes[i].num);
	}
	
}

int pesquisaPaciente(PACIENTE pacientes[], int total){
	int SNS, i=0;
	
	printf("Introduza o SNS do paciente que pretende procurar:\n");
	scanf("%i", &SNS);
	
	for(i=0; i<total; i++){
		if(SNS == pacientes[i].SNS){
			printf("Nome: %s; CC: %s; SNS: %i; NIF: %i; Telefone: %i; Data de nascimento: %i; Morada: %s; Numero: %i\n",\
			pacientes[i].nome, pacientes[i].CC, pacientes[i].SNS, pacientes[i].NIF, pacientes[i].telefone, pacientes[i].data_nascimento, pacientes[i].morada, pacientes[i].num);
		}
	}
	return 0;
}

int listarDepoisDeData(PACIENTE pacientes[], int total){
	int data, i=0;
	
	printf("Introduza a data (ddmmyyyy):\n");
	scanf("%i", &data);
	
	for(i=0; i<total; i++){
		if(data <= pacientes[i].data_nascimento){
			printf("Nome: %s; CC: %s; SNS: %i; NIF: %i; Telefone: %i; Data de nascimento: %i; Morada: %s; Numero: %i\n",\
			pacientes[i].nome, pacientes[i].CC, pacientes[i].SNS, pacientes[i].NIF, pacientes[i].telefone, pacientes[i].data_nascimento, pacientes[i].morada, pacientes[i].num);
		}
	}
}

int gravaFile(PACIENTE pacientes[], int total){	
	FILE *fp=NULL; 
	int res=0;
	
	fp=fopen("Pacientes.dat", "wb");
	
	if(fp==NULL){
		printf("ERRO ao abrir o ficheiro\n");
		return -1;
	}
	fwrite(&total,sizeof(int),1,fp);		//Escrever total de registos e dps escreve os registos, 1-um inteiro
	res=fwrite(&pacientes[0],sizeof(PACIENTE),total,fp);
	printf("Total registos escritos=%i\n", res);
	fclose(fp);
}

int lerFicheiro(PACIENTE pacientes[]){
	FILE *fp=NULL;
	int totReg=0, res=0;
	
	fp=fopen("Pacientes.dat","rb");
	if(fp==NULL){
		printf("Não existe ficheiro\n");
		return 0;
	}
	
	res=fread(&totReg,sizeof(int),1,fp);		//Lê primeiro um inteiro(nº de registos que vamos buscar)
	
	if(totReg>0){
		res=fread(&pacientes[0],sizeof(PACIENTE),totReg,fp);
		printf("Leu %i registos\n",totReg);
	}
	
	fclose(fp);
	return res;
}

int menuPacIni(int total){
	int opc;
	system("cls");
	printf("Total: %i\n", total);
	printf("\t\t CLINICA MEDICA\n\n");
	printf("\tMENU DE PACIENTES E CONSULTAS\n\n");
	printf("Introduza a opcao:\n\n");
	printf("1- Acrescentar informacao sobre um novo paciente.\n");
	printf("2- Alterar o nº telefone e morada de um paciente.\n");
	printf("3- Listar pacientes por ordem alfabetica.\n");
	printf("4- Apresentar os dados de um cliente.\n");
	printf("5- Listar todos os clientes que nasceram depois de uma determinada data.\n");
	printf("0- Sair\n");
	printf(">");
	scanf("%i",&opc);
	return opc;
}

int menuPac() {
	PACIENTE aux[100];
	setlocale(LC_ALL, "Portuguese");
	int opc=0;
	int total=0;
	
	total = lerFicheiro(aux);
	
	do{
		opc=menuPacIni(total);
		switch(opc){
			case 1:
				total+=inserirPaciente(aux, total);
				system("pause");
				break;
			case 2:
				alteraNIF_Nome(aux, total);
				break;
			case 3:
				ordenaNome(aux, total);
				listarPorNome(aux, total);
				system("pause");
				break;
			case 4:
				pesquisaPaciente(aux, total);				
				system("pause");
				break;
			case 5:
				listarDepoisDeData(aux, total);
				system("pause");
				break;
			case 0:
				printf("Saindo...\n");
				gravaFile(aux, total);
		}
	}while(opc!=0);
	
	return 0;
}



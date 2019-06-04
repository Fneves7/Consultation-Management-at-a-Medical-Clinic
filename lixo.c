//FUNCIONA NAO MEXER
/*MEDICO lerFicheiroMed(){
	
	MEDICO aux;
	int res=0;
	FILE *fp = fopen("medicos.dat", "rb");
	
	if(!fp){
		printf("Erro de ficheiro.\n"); return;
	}
	
	while(fread(&aux, sizeof(MEDICO), 1,fp)){
		printf("N. da ordem: %i - Nome: %s\n", aux.n_ordem, aux.nome);
		res++;
	}
	printf("leu %i dados\n",res);
	
	fclose(fp);
	return aux;
}*/

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


//LER FICHEIRO PESSOAS

	//totreg=getSize(iniLista);	
    //fread(&aux, sizeof(MEDICO), 1,fp);
    
    /*while(!feof(fp)){
		res = fread(&aux, sizeof(MEDICO), 1,fp);
		printf("numero da ordem: %i\n", aux.n_ordem);
		printf("Nome: %s\n", aux.nome);	
	}*/
	
	
	/*res = fread(&aux, sizeof(MEDICO), 1,fp);
		printf("%i: %i - %s - %i - %s - %i - %s - Data de entrada: %s - \n",
		aux.numero,
		aux.n_ordem,
		aux.nome,
		aux.NIF,
		aux.morada, 
		aux.telefone, 
		aux.especialidade,
		aux.data_entrada);*/
 
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
	
	/*
	int lerDadosFicheiro(){
	
	MEDICO aux;
	int res=0;
	FILE *fp = fopen("medicos.dat", "rb");
	
	if(!fp){
		printf("Erro de ficheiro.\n"); return -1;
	}
	
	while(fread(&aux, sizeof(MEDICO), 1,fp)){
		//res = fread(&aux, sizeof(MEDICO), 1,fp);
		printf("numero da ordem: %i\n", aux.n_ordem);
		printf("Nome: %s\n", aux.nome);
		res++;
	}
	printf("leu %i dados\n",res);
	
	fclose(fp);
	return res;
}*/

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

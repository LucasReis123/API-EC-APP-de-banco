#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>	
	

	struct Contas{
		char agencia[80];
		char ndaConta[80];
		char cliente[80];
		float saldo;
	};
	
	
	void bem_Vindo(){ // Inicia o código
		printf("============== Bem Vindo! ===============\n");
		printf("Digite um comando a seguir para iniciar:\n");
		printf("C - Gerenciar Clientes\n");
		printf("T - Gerenciar Contas\n");
		printf("S - Sair\n");
		printf("Observacao: Escreva em CAPS LOCK\n");
	}

	void gerenciarClientes(){
		printf("============== Gerenciar Clientes ===============\n");
		printf("Digite um comando para prosseguir:\n");
		printf("C - Cadastrar um cliente\n");
		printf("L - Listar todos os clientes cadastrados\n");
		printf("B - Buscar cliente ja cadrastrado\n");
		printf("A - Atualizar um cliente cadastrado\n");
		printf("E - Excluir um cliente cadastrado\n");
		printf("S - Sair\n");
		printf("Observacao: Escreva em CAPS LOCK\n");
	}
	
	void gerenciarContas(){
		printf("============== Gerenciar Contas ===============\n");
		printf("Digite um comando para prosseguir:\n");
		printf("R - Listagem de todas as contas cadastradas\n");
		printf("C - Cadastrar uma conta para um cliente\n");
		printf("L - Listar todas cas contas de um cliente\n");
		printf("W - Realizar um saque em uma conta\n");
		printf("D - Realizar um deposito em uma conta\n");
		printf("T - Realizar transferencia entre contas\n");
		printf("E - Exibir extrato de uma conta\n");
		printf("S - Sair\n");
		printf("Observacao: Escreva em CAPS LOCK\n");
	}
	
	void cadastraCliente(){
		FILE *leitura;
		char nome[50], endereco[100], codigo[20], cpf[20], telefone[15];
		int v = 0;
		char texto[1000], texto2[1000];
		
		printf("Informe seu NOME:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &nome);
		system("cls");
		
		printf("Informe seu CODIGO:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &codigo);
		system("cls");
		
		printf("Informe seu CPF/CNPJ:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &cpf);
		system("cls");
		
		printf("Informe seu TELEFONE:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &telefone);
		system("cls");
		
		printf("Informe seu ENDERECO:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &endereco);
		system("cls");
		
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			fscanf(leitura, "%[^'\n']s", texto2);
			if((strcmp(texto2, cpf) == 0) || (strcmp(texto2, codigo) == 0)){
				v = 1;
				break;
			}
		}
		
		fclose(leitura);
		
	
	
		if(v == 0){
			FILE *adicionar;
			adicionar = fopen("Clientes.txt", "a");
		
			fprintf(adicionar, "%s\n", nome);
			fprintf(adicionar, "%s\n", codigo);
			fprintf(adicionar, "%s\n", cpf);
			fprintf(adicionar, "%s\n", telefone);
			fprintf(adicionar, "%s\n", endereco);
			fclose(adicionar);
			
		}else if(v == 1){
			system("cls");
			printf("Cliente ja cadastrado!\n");
			system("pause");
			system("cls");
		}
		
	}
	
	void todosClientes(){
		FILE *leitura;
		int i = 5, cont = 0, x, y;
		char texto[1000], texto2[1000], ordem[100][80], aux[80];
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(i == 5){
				strcpy(ordem[cont], texto2);
				cont++;
				i = 0;
			}
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		
		if(ftell(leitura) != 0){
			for(x = 0; x < cont; x++){
				for(y = x+1; y < cont; y++){
					if(strcmp(ordem[x], ordem[y]) > 0){
						strcpy(aux, ordem[x]);
						strcpy(ordem[x], ordem[y]);
						strcpy(ordem[y], aux);
					}
				}
			}
			printf("Nome de todos os clientes cadastrados: \n");
			
			for(x = 0; x < cont; x++){
				printf("%s\n", ordem[x]);
			}
		}
		
		
		if(ftell(leitura) == 0){
			printf("Nenhum cliente cadastrado!\n");
		}
		fclose(leitura);
		system("pause");
	}
	
	void buscaNome(){
		char nome[80], texto[100000], texto2[100000], i = 0;
		FILE *leitura;
		leitura = fopen("Clientes.txt", "r");
		
		
		printf("Digite o NOME do Cliente:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &nome);
		system("cls");
		printf("Dados do cliente:\n");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 100000, leitura) != NULL){
			if(i == 1){
				printf("ENDERECO: %s\n", texto2);
				i--;
			}
			
			if(i == 2){
				printf("TELEFONE: %s\n", texto2);
				i--;
			}
			
			if(i == 3){
				printf("CPF/CNPJ: %s\n", texto2);
				i--;
			}
			
			if(i == 4){
				printf("CODIGO: %s\n", texto2);
				i--;
			}
			
			
			if(strcmp(nome, texto2) == 0){
				printf("NOME: %s\n", texto2);
				i = 4;
			}
		
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		
		fclose(leitura);
		
		system("pause");
		system("cls");
		
	}
	
	void buscaCodigo(){
		char codigo[80], texto[100000], texto2[100000], i = 0, r = 0;
		FILE *leitura, *leitura2;
		leitura = fopen("Clientes.txt", "r");
		
		
		printf("Digite o CODIGO do Cliente:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &codigo);
		system("cls");
	
		
		fscanf(leitura, "%[^'\n']s", texto2);
		
		while(fgets(texto, 100000, leitura) != NULL){
			if(strcmp(codigo, texto2) == 0){
				r = i;
			}
			
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
		r--;
		i = 0;
		leitura2 = fopen("Clientes.txt", "r");
		
		fscanf(leitura2, "%[^'\n']s", texto2);
		while(fgets(texto, 100000, leitura2) != NULL){
			if(r == i-4){
				printf("ENDERECO :%s\n", texto2);
			}
			if(r == i-3){
				printf("TELEFONE :%s\n", texto2);
			}
			if(r == i-2){
				printf("CPF/CNPJ :%s\n", texto2);
			}
			if(r == i-1){
				printf("CODIGO :%s\n", texto2);
			}
			
			if(r == i){
				printf("NOME :%s\n", texto2);
			}
			
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		
		fclose(leitura2);
		system("pause");
		system("cls");
		
		
	}
	
	void buscaCpf(){
		char cpf[80], texto[100000], texto2[100000], i = 0, r = 0;
		FILE *leitura, *leitura2;
		leitura = fopen("Clientes.txt", "r");
		
		
		printf("Digite o CPF/CNPJ do Cliente:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &cpf);
		system("cls");
	
		
		fscanf(leitura, "%[^'\n']s", texto2);
		
		while(fgets(texto, 100000, leitura) != NULL){
			if(strcmp(cpf, texto2) == 0){
				r = i;
			}
			
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
		r = r-2;
		i = 0;
		leitura2 = fopen("Clientes.txt", "r");
		
		fscanf(leitura2, "%[^'\n']s", texto2);
		while(fgets(texto, 100000, leitura2) != NULL){
			if(r == i-4){
				printf("ENDERECO :%s\n", texto2);
			}
			if(r == i-3){
				printf("TELEFONE :%s\n", texto2);
			}
			if(r == i-2){
				printf("CPF/CNPJ :%s\n", texto2);
			}
			if(r == i-1){
				printf("CODIGO :%s\n", texto2);
			}
			
			if(r == i){
				printf("NOME :%s\n", texto2);
			}
			
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		
		fclose(leitura2);
		system("pause");
		system("cls");
	}
	
	void buscaCliente(){
		int i;
		printf("Informe o modo no qual deseja achar o cliente:\n");
		printf("1 - Por NOME\n");
		printf("2 - Por CODIGO\n");
		printf("3 - Por CPF/CNPJ\n");
		scanf("%d", &i);
		if(i == 1){
			buscaNome();
		}else if(i == 2){
			buscaCodigo();
		}else if(i == 3){
			buscaCpf();
		}else{
			system("cls");
			printf("Valor nao existente!\n");
			buscaCliente();
		}
		
	}
	
	atualizapCodigo(){
		system("cls");
		FILE *leitura;
		FILE *arquivo2;
		char texto[1000], texto2[1000], codigo[80];
		char nome[80], codigo2[80], cpf[80], telefone[80], endereco[80];
		int cont = 0, k = 0, verdadeiro = 0;
		
		printf("Informe seu CODIGO:\n");
		scanf("%s", &codigo);
		
		leitura = fopen("Clientes.txt", "r");
		arquivo2 = fopen("Clientes2.txt", "w");
		
		while(fgets(texto, 1000, leitura) != NULL){
			fprintf(arquivo2, "%s", texto);
		}
		fclose(leitura);
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(codigo, texto2) == 0){
				verdadeiro = 1;
				break;
			}else{
				cont++;
			}
			
			fscanf(leitura, "%[^'\n']", texto2);
		}
		
		if(verdadeiro == 0){
			printf("Cliente nao encontrado!\n");
		}
		
		fclose(leitura);
		fclose(arquivo2);
		
		leitura = fopen("Clientes2.txt", "r");
		arquivo2 = fopen("Clientes.txt", "w");
		

		
		if(verdadeiro == 1){
			fscanf(leitura, "%[^'\n']", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				system("cls");
				k++;
				if(k == cont){
					printf("Digite o NOME do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &nome);
					fprintf(arquivo2, "%s\n", nome);
				}else if(k == (cont + 1)){
					printf("Digite o CODIGO do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &codigo2);
					fprintf(arquivo2, "%s\n", codigo2);
				}else if(k == (cont + 2)){
					printf("Digite o CPF/CNPJ do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &cpf);
					fprintf(arquivo2, "%s\n", cpf);
				}else if(k == (cont + 3)){
					printf("Digite o TELEFONE do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &telefone);
					fprintf(arquivo2, "%s\n", telefone);
				}else if(k == (cont + 4)){
					printf("Digite o ENDERECO do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &endereco);
					fprintf(arquivo2, "%s\n", endereco);
				}else{
					fprintf(arquivo2, "%s\n", texto2);
				}
			
				fscanf(leitura, "%[^'\n']", texto2);	
			}
		}else{
			fscanf(leitura, "%[^'\n']", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				fprintf(arquivo2, "%s\n", texto2);
				fscanf(leitura, "%[^'\n']", texto2);
			}
		}	
		
		
		fclose(arquivo2);
		fclose(leitura);
		
		
		system("pause");
		system("cls");	
	}
	
	atualizapCpf(){
		system("cls");
		FILE *leitura;
		FILE *arquivo2;
		char texto[1000], texto2[1000], cpf[80];
		char nome[80], codigo[80], cpf2[80], telefone[80], endereco[80];
		int cont = 0, k = 0, verdadeiro = 0;
		
		printf("Informe seu CPF/CNPJ:\n");
		scanf("%s", &cpf);
			
		leitura = fopen("Clientes.txt", "r");
		arquivo2 = fopen("Clientes2.txt", "w");
		
		while(fgets(texto, 1000, leitura) != NULL){
			fprintf(arquivo2, "%s", texto);
		}
		fclose(leitura);
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(cpf, texto2) == 0){
				verdadeiro = 1;
				break;
			}else{
				cont++;
			}
			
			fscanf(leitura, "%[^'\n']", texto2);
		}
		cont--;
		if(verdadeiro == 0){
			printf("Cliente nao encontrado!\n");
		}
		
		fclose(leitura);
		fclose(arquivo2);
		
		leitura = fopen("Clientes2.txt", "r");
		arquivo2 = fopen("Clientes.txt", "w");
		
				
		if(verdadeiro == 1){
			fscanf(leitura, "%[^'\n']", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				system("cls");
				k++;
				if(k == cont){
					printf("Digite o NOME do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &nome);
					fprintf(arquivo2, "%s\n", nome);
				}else if(k == (cont + 1)){
					printf("Digite o CODIGO do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &codigo);
					fprintf(arquivo2, "%s\n", codigo);
				}else if(k == (cont + 2)){
					printf("Digite o CPF/CNPJ do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &cpf2);
					fprintf(arquivo2, "%s\n", cpf2);
				}else if(k == (cont + 3)){
					printf("Digite o TELEFONE do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &telefone);
					fprintf(arquivo2, "%s\n", telefone);
				}else if(k == (cont + 4)){
					printf("Digite o ENDERECO do cliente a ser atualizado:\n");
					fflush(stdin);
					scanf("%[^'\n']s", &endereco);
					fprintf(arquivo2, "%s\n", endereco);
				}else{
					fprintf(arquivo2, "%s\n", texto2);
				}
			
				fscanf(leitura, "%[^'\n']", texto2);	
			}
		}else{
			fscanf(leitura, "%[^'\n']", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				fprintf(arquivo2, "%s\n", texto2);
				fscanf(leitura, "%[^'\n']", texto2);
			}
		}	
		
		
		fclose(arquivo2);
		fclose(leitura);
		
		system("pause");
		system("cls");
	}
	
	void atualizaCliente(){
		int i = 0;
		
		printf("Deseja ATUALIZAR o cliente atraves de:\n");
		printf("1 - CODIGO\n");
		printf("2 - CPF/CNPJ\n");
		scanf("%d", &i);
		
		if(i == 1){
			atualizapCodigo();
		}else if(i == 2){
			atualizapCpf();
		}else{
			system("cls");
			printf("Valor indicado errado!\n");
			atualizaCliente();
		}
	}
	
	int excluiCodigo(){
		system("cls");
		FILE *leitura;
		FILE *arquivo2;
		char texto[1000], texto2[1000], codigo[80];
		int cont = 0, k = 0, verdadeiro = 0, confirmacao, exclui = 0;
		
		printf("Informe o CODIGO:\n");
		scanf("%s", &codigo);
		
		leitura = fopen("Clientes.txt", "r");
		arquivo2 = fopen("Clientes2.txt", "w");
		
		while(fgets(texto, 1000, leitura) != NULL){
			fprintf(arquivo2, "%s", texto);
		}
		fclose(leitura);
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(codigo, texto2) == 0){
				verdadeiro = 1;
				break;
			}else{
				cont++;
			}
			
			fscanf(leitura, "%[^'\n']", texto2);
		}
		
		if(verdadeiro == 0){
			printf("Cliente nao encontrado!\n");
		}
		
		fclose(leitura);
		fclose(arquivo2);
		
		leitura = fopen("Clientes2.txt", "r");
		
		
		if(verdadeiro == 1){
			system("cls");
			fscanf(leitura, "%[^'\n']", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				k++;
				if(k == cont){
					printf("NOME: %s\n", texto2);
				}else if(k == (cont + 1)){
					printf("CODIGO: %s\n", texto2);
				}else if(k == (cont + 2)){
					printf("CPF/CNPJ: %s\n", texto2);
				}else if(k == (cont + 3)){
					printf("TELEFONE: %s\n", texto2);
				}else if(k == (cont + 4)){
					printf("ENDERECO: %s\n", texto2);
				}
			
				fscanf(leitura, "%[^'\n']", texto2);	
			}
			printf("Tem certeza que deseja excluir esse cliente?\n");
			printf("1 - Sim\n");
			printf("2 - Nao\n");
			fflush(stdin);
			scanf("%d", &confirmacao);
			if(confirmacao == 1){
				exclui = 1;
				system("cls");
				k = 0;
				fclose(leitura);
				leitura = fopen("Clientes2.txt", "r");
				arquivo2 = fopen("Clientes.txt", "w");
				fscanf(leitura, "%[^'\n']", texto2);
				while(fgets(texto, 1000, leitura) != NULL){
					k++;
					if(k == cont){
					}else if(k == (cont + 1)){
					}else if(k == (cont + 2)){
					}else if(k == (cont + 3)){
					}else if(k == (cont + 4)){
					}else{
						fprintf(arquivo2, "%s\n", texto2);
					}
				
					fscanf(leitura, "%[^'\n']", texto2);	
				}
				fclose(arquivo2);
			}
		}
				
		
		
		fclose(leitura);
		
		
		system("pause");
		system("cls");	
		return exclui;
	}
	
	
	int excluiCpf(){
		system("cls");
		FILE *leitura;
		FILE *arquivo2;
		char texto[1000], texto2[1000], cpf[80];
		int cont = 0, k = 0, verdadeiro = 0, confirmacao, exclui = 0;
		
		printf("Informe o CPF/CNPJ:\n");
		scanf("%s", &cpf);
		
		leitura = fopen("Clientes.txt", "r");
		arquivo2 = fopen("Clientes2.txt", "w");
		
		while(fgets(texto, 1000, leitura) != NULL){
			fprintf(arquivo2, "%s", texto);
		}
		fclose(leitura);
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(cpf, texto2) == 0){
				verdadeiro = 1;
				break;
			}else{
				cont++;
			}
			
			fscanf(leitura, "%[^'\n']", texto2);
		}
		cont--;
		
		if(verdadeiro == 0){
			printf("Cliente nao encontrado!\n");
		}
		
		fclose(leitura);
		fclose(arquivo2);
		
		leitura = fopen("Clientes2.txt", "r");
		
		
		if(verdadeiro == 1){
			system("cls");
			fscanf(leitura, "%[^'\n']", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				k++;
				if(k == cont){
					printf("NOME: %s\n", texto2);
				}else if(k == (cont + 1)){
					printf("CODIGO: %s\n", texto2);
				}else if(k == (cont + 2)){
					printf("CPF/CNPJ: %s\n", texto2);
				}else if(k == (cont + 3)){
					printf("TELEFONE: %s\n", texto2);
				}else if(k == (cont + 4)){
					printf("ENDERECO: %s\n", texto2);
				}
			
				fscanf(leitura, "%[^'\n']", texto2);	
			}
			printf("Tem certeza que deseja excluir esse cliente?\n");
			printf("1 - Sim\n");
			printf("2 - Nao\n");
			fflush(stdin);
			scanf("%d", &confirmacao);
			if(confirmacao == 1){
				exclui = 1;
				system("cls");
				k = 0;
				fclose(leitura);
				leitura = fopen("Clientes2.txt", "r");
				arquivo2 = fopen("Clientes.txt", "w");
				fscanf(leitura, "%[^'\n']", texto2);
				while(fgets(texto, 1000, leitura) != NULL){
					k++;
					if(k == cont){
					}else if(k == (cont + 1)){
					}else if(k == (cont + 2)){
					}else if(k == (cont + 3)){
					}else if(k == (cont + 4)){
					}else{
						fprintf(arquivo2, "%s\n", texto2);
					}
				
					fscanf(leitura, "%[^'\n']", texto2);	
				}
				fclose(arquivo2);
			}
		}
				
		
		
		fclose(leitura);
		
		
		system("pause");
		system("cls");
		return exclui;
	}
	
	
	int excluiCliente(){
		int i = 0, exclui = 0;
		
		printf("Deseja EXCLUIR o cliente atraves de:\n");
		printf("1 - CODIGO\n");
		printf("2 - CPF/CNPJ\n");
		scanf("%d", &i);
		
		if(i == 1){
			exclui = excluiCodigo();
		}else if(i == 2){
			exclui = excluiCpf();
		}else{
			system("cls");
			printf("Valor indicado errado!\n");
			excluiCliente();
		}
		return exclui;
	}
	
	void contapCodigo(){
		char codigo[80], texto[1000], texto2[1000], nome[80], res[50];
		FILE *leitura;
		FILE *arquivo;
		int r = -1, i = 0, v = 0, v2 = 0, v3 = 0, v4 = 0, k = 0, cont = 0, a = 0, b[200];
		
		
		system("cls");
		printf("Por favor, digite o CODIGO do cliente:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &codigo);
		
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(codigo, texto2) == 0){                           //COPIA A POSICAO DO NOME DO CLIENTE
				r = i;
				v = 1;
			}
			
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
		r--;
		i = 0;
		leitura = fopen("Clientes.txt", "r");
		
		if(v != 0){
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				if(r == i){
					fflush(stdin);
					strcpy(nome, texto2);                             //DESCOBRE O NOME DO CLIENTE
				}
				
				fscanf(leitura, "%[^'\n']s", texto2);
				i++;
			}
		}
		
		fclose(leitura);
		system("cls");
		
		leitura = fopen("Contas.txt", "r");
	
	
		struct Contas conta;
		
		if(v == 0){
			printf("Cliente ainda nao cadastrado!\n");
		}else if(v == 1){
			printf("Por favor, %s, digite sua AGENCIA:\n", nome);
			fflush(stdin);
			scanf("%[^'\n']s", &conta.agencia);
			
			printf("Por favor, %s, digite o NUMERO DA CONTA:\n", nome);
			fflush(stdin);
			scanf("%[^'\n']s", &conta.ndaConta);
	//		itoa(conta.ndaConta, res, 10);
			
			conta.saldo = 0;			
		}
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			k++;
			
			if(k%4 == 2){
				if(strcmp(texto2, conta.agencia) == 0){
					v2 = 1;
					b[a] = cont + 1;
					a++;
				}
				k = -2;
			}
			cont++;
			
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
	
		
		for(i = 0; i <= a; i++){
			leitura = fopen("Contas.txt", "r");
			k = 0;
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
			
				if(k == b[i]){
					if(strcmp(texto2, res) == 0){
						v3 = 1;
					}
				}
				k++;
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
		}
		
		
		
		if((v2 == 1) && (v3 == 1)){
			v4 = 1;
		}
		
	
		if(v4 == 1){
			printf("Conta ja existente!\n");
		}else if((v == 1) && (v4 == 0)){
			arquivo = fopen("Contas.txt", "a");
			fprintf(arquivo, "%s\n", nome);
			fprintf(arquivo, "%s\n", conta.agencia);
			fprintf(arquivo, "%s\n", conta.ndaConta);
			fprintf(arquivo, "%f\n", conta.saldo);
			fclose(arquivo);
		}
		fclose(leitura);
		system("pause");
		
	}
	
	void contapCpf(){
		char cpf[80], texto[1000], texto2[1000], nome[80], res[50];
		FILE *leitura;
		FILE *arquivo;
		int r = -1, i = 0, v = 0, v2 = 0, v3 = 0, v4 = 0, k = 0, cont = 0, a = 0, b[200];
		
		
		system("cls");
		printf("Por favor, digite o CPF/CNPJ do cliente:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &cpf);
		
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(cpf, texto2) == 0){                           //COPIA A POSICAO DO NOME DO CLIENTE
				r = i;
				v = 1;
			}
			
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
		r = r-2;
		i = 0;
		leitura = fopen("Clientes.txt", "r");
		
		if(v != 0){
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				if(r == i){
					fflush(stdin);
					strcpy(nome, texto2);                             //DESCOBRE O NOME DO CLIENTE
				}
				
				fscanf(leitura, "%[^'\n']s", texto2);
				i++;
			}
		}
		
		fclose(leitura);
		system("cls");
		
		leitura = fopen("Contas.txt", "r");
	
	
		struct Contas conta;
		
		if(v == 0){
			printf("Cliente ainda nao cadastrado!\n");
		}else if(v == 1){
			printf("Por favor, %s, digite sua AGENCIA:\n", nome);
			fflush(stdin);
			scanf("%[^'\n']s", &conta.agencia);
			
			printf("Por favor, %s, digite o NUMERO DA CONTA:\n", nome);
			fflush(stdin);
			scanf("%[^'\n']s", &conta.ndaConta);
	//		itoa(conta.ndaConta, res, 10);
			
			conta.saldo = 0;			
		}
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			k++;
			
			if(k%4 == 2){
				if(strcmp(texto2, conta.agencia) == 0){
					v2 = 1;
					b[a] = cont + 1;
					a++;
				}
				k = -2;
			}
			cont++;
			
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
	
		
		for(i = 0; i <= a; i++){
			leitura = fopen("Contas.txt", "r");
			k = 0;
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
			
				if(k == b[i]){
					if(strcmp(texto2, res) == 0){
						v3 = 1;
					}
				}
				k++;
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
		}
		
		
		
		if((v2 == 1) && (v3 == 1)){
			v4 = 1;
		}
		
	
		if(v4 == 1){
			printf("Conta ja existente!\n");
		}else if((v == 1) && (v4 == 0)){
			arquivo = fopen("Contas.txt", "a");
			fprintf(arquivo, "%s\n", nome);
			fprintf(arquivo, "%s\n", conta.agencia);
			fprintf(arquivo, "%s\n", conta.ndaConta);
			fprintf(arquivo, "%f\n", conta.saldo);
			fclose(arquivo);
		}
		fclose(leitura);
		system("pause");
		
	}
	
	void cadastraConta(){
		int i;
		
		printf("Deseja buscar o cliente atraves de:\n");
		printf("1 - CODIGO\n");
		printf("2 - CPF/CNPJ\n");
		fflush(stdin);
		scanf("%d", &i);
		if(i == 1){
			contapCodigo();
		}else if(i == 2){
			contapCpf();
		}else{
			system("cls");
			printf("Numero nao compreendido\n");
			cadastraConta();
		}
	}
	
	void listarContas(){
		FILE *leitura;
		FILE *arquivo;
		FILE *arquivoteste;
		int i = 4, cont = 0, x, y, k = 0;
		char texto[1000], texto2[1000], ordem[200][80], aux[80];
		float saldo1, saldo2;
		leitura = fopen("Contas.txt", "r");
		arquivo = fopen("Contas2.txt", "w");
		fclose(arquivo);
		arquivoteste = fopen("Contateste.txt", "w");
		fclose(arquivoteste);
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(i == 4){
				strcpy(ordem[cont], texto2);
				cont++;
				i = 0;
			}
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		
		if(ftell(leitura) != 0){
			for(x = 0; x < cont; x++){
				for(y = x+1; y < cont; y++){
					if(strcmp(ordem[x], ordem[y]) > 0){
						strcpy(aux, ordem[x]);
						strcpy(ordem[x], ordem[y]);         // COLOCA OS NOMES DOS CLIENTES TEM ORDEM ALFABETICA
						strcpy(ordem[y], aux);
					}
				}
			}
	/*		printf("Nome de todos os clientes cadastrados: \n");
			
			for(x = 0; x < cont; x++){
				printf("%s\n", ordem[x]);
			}
	*/	}
		
		
		if(ftell(leitura) == 0){
			printf("Nenhuma conta cadastrada!\n");
		}
		fclose(leitura);
		
		i = 0;
		
	/*	for(x = 0; i < cont; i++){
			for(y = x+1; y < cont; y++){
				if(strcmp(ordem[x], ordem[y]) == 0){
					leitura = fopen("Contas.txt", "r");
					fscanf(leitura, "%[^'\n']s", texto2);
					while(fgets(texto, 1000, leitura) != NULL){
						if(k == 1){
							fprintf(arquivoteste, "%f\n", saldo1);
							k--;
							break;
						}
						
						if(k == 2){
							fprintf(arquivoteste, "%s\n", texto2);
							fscanf(leitura, "%f", saldo1);
							k--;
						}
						if(k == 3){
							fprintf(arquivoteste, "%s\n", texto2);
							k--;
						
						}
						if(strcmp(ordem[i], texto2) == 0){
							fprintf(arquivoteste, "%s\n", texto2);
							k = 3;
						}
						fscanf(leitura, "%[^'\n']s", texto2);
					}
					
					while(fgets(texto, 1000, leitura) != NULL){
						if(k == 1){
							fprintf(arquivoteste, "%f\n", saldo2);
							k--;
							break;
						}
						
						if(k == 2){
							fprintf(arquivoteste, "%s\n", texto2);
							fscanf(leitura, "%f", saldo2);
							k--;
						}
						if(k == 3){
							fprintf(arquivoteste, "%s\n", texto2);
							k--;
						
						}
						if(strcmp(ordem[i], texto2) == 0){
							fprintf(arquivoteste, "%s\n", texto2);
							k = 3;
						}
						fscanf(leitura, "%[^'\n']s", texto2);
					}
					fclose(leitura);
					if(saldo2 > saldo1){
						k = 7;
						leitura = fopen("Contateste.txt", "r");
						arquivo = fopen("Contas2.txt", "a");
						fscanf(leitura, "%[^'\n']s", texto2);
						while(fgets(texto, 1000, leitura) != NULL){
							if(k == 0){
								fprintf(arquivo, "%f\n", saldo2);
								break;
							}
							
							if(k == 1){
								fprintf(arquivo, "%s\n", texto2);
							}
							if(k == 2){
								fprintf(arquivo, "%s\n", texto2);
							
							}
							if(k == 3){
								fprintf(arquivo, "%s\n", texto2);
							}
							fscanf(leitura, "%[^'\n']s", texto2);
							k--;
						}
						k = 0;
						fclose(arquivo);
						fclose(leitura);
					}else{
						k = 3;
						leitura = fopen("Contateste.txt", "r");
						arquivo = fopen("Contas2.txt", "a");
						fscanf(leitura, "%[^'\n']s", texto2);
						while(fgets(texto, 1000, leitura) != NULL){
							if(k == 0){
								fprintf(arquivo, "%f\n", saldo1);
								break;
							}
							
							if(k == 1){
								fprintf(arquivo, "%s\n", texto2);
							}
							if(k == 2){
								fprintf(arquivo, "%s\n", texto2);
							
							}
							if(k == 3){
								fprintf(arquivo, "%s\n", texto2);
							}
							fscanf(leitura, "%[^'\n']s", texto2);
							k--;
						}
						k = 0;
						fclose(arquivo);
						fclose(leitura);
					}
					
				}else{
					arquivo = fopen("Contas2.txt", "a");
					fscanf(leitura, "%[^'\n']s", texto2);
					while(fgets(texto, 1000, leitura) != NULL){
						if(k == 1){
							fprintf(arquivo, "%s\n", texto2);
							k--;
						}
						
						if(k == 2){
							fprintf(arquivo, "%s\n", texto2);
							k--;
						}
						if(k == 3){
							fprintf(arquivo, "%s\n", texto2);
							k--;
						
						}
						if(strcmp(ordem[i], texto2) == 0){
							fprintf(arquivo, "%s\n", texto2);
							k = 3;
						}
						fscanf(leitura, "%[^'\n']s", texto2);
					}
					fclose(leitura);
					fclose(arquivo);
				}
			
			}
		}
*/		
		
		for(i = 0; i < cont; i){
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				
				
				if(k == 1){
					printf("Saldo do cliente: RS%s\n\n", texto2);
					k--;
				}
				
				if(k == 2){
					printf("NUMERO DA CONTA do cliente: %s\n", texto2);
					k--;
				}
				if(k == 3){
					printf("AGENCIA do cliente: %s\n", texto2);
					k--;
				
				}
				if(strcmp(ordem[i], texto2) == 0){
					printf("NOME do cliente: %s\n", texto2);
					k = 3;
					i++;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
		}
		system("pause");
	}
	
	void buscapCodigo(){
		char codigo[80], texto[1000], texto2[1000], nome[80];
		FILE *leitura;
		FILE *arquivo;
		int i = 0, v = 0, v2 = 0, cont = 0, k = 0;
		float saldo;
		float vet[cont], auxf;
		int vet2[cont], auxi, j;
		
		system("cls");
		printf("Por favor, digite o CODIGO do cliente:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &codigo);
		
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(codigo, texto2) == 0){
				
				v = 1;                                          // ACHA A POSICAO DO "NOME"
				break;
			}
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
		if(v == 0){
			system("cls");
			printf("Cliente nao cadastrado!\n");
			system("pause");
		}else if(v == 1){
			leitura = fopen("Clientes.txt", "r");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				i--;
				if(i == 0){
					strcpy(nome, texto2);                       // COLOCA O NOME DO CLIENTE EM "NOME"
					v2 = 1;
					break;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
		}
		
		if((v == 1) && (v2 == 0)){
			system("cls");
			printf("Conta nao cadastrada!\n");
			system("pause");
		}else if((v == 1) && (v2 == 1)){ //COLOCANDO OS DADOS DAS CONTAS DO CLIENTE EM CONTAS2
			i = 0;
			leitura = fopen("Contas.txt", "r");
			arquivo = fopen("Contas2.txt", "w");
			fclose(arquivo);
			arquivo = fopen("Contas2.txt", "a");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				if(i == 1){
					fscanf(leitura, "%f", &saldo);
					fprintf(arquivo, "%f\n", saldo);
					i--;
				}
				
				if(i == 2){
					fprintf(arquivo, "%s\n", texto2);
					i--;
				}
				
				if(i == 3){
					fprintf(arquivo, "%s\n", texto2);
					i--;
				}
				
				if(strcmp(nome, texto2) == 0){
					fprintf(arquivo, "%s\n", texto2);
					i = 3;
					cont++;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
			fclose(arquivo);
		}
		
		if((v == 1) && (v2 == 1)){
			
			leitura = fopen("Contas2.txt", "r");
			
			i = 1;
			while(fgets(texto, 1000, leitura) != NULL){
				if(i%4 == 0){
					fscanf(leitura, "%f", vet[k]);           //SALVA OS SALDOS NO VET[K]
					vet2[k] = i-1;                          //SALVA AS POSICOES DO SALDO NO VET2[K]
					k++;
				}
				i++;
			}
			fclose(leitura);
			
		}
		
		if((v == 1) && (v2 == 1)){ // COLOCA OS VETORES EM ORDEM DECRESCETE
			for(k = 0; k < cont; k++){
				for(i = k+1; i < cont; i++){
					if(vet[k] < vet[i]){
						auxf = vet[i];
						vet[i] = vet[k];
						vet[k] = auxf;
						
						auxi = vet2[i];
						vet2[i] = vet2[k];
						vet2[k] = auxi;
					}  
				}
			}	
		}
		
		
		if((v == 1) && (v2 == 1)){// SALVA NO ARQUIVOS CONTAS3 EM ORDEM DECRESCENTE DE SALDO
			arquivo = fopen("Contas3.txt", "w");
			fclose(arquivo);
			k = 0;
			for(i = 0; i < cont; i++){
				j = 0;
				arquivo = fopen("Contas3.txt", "a");
				leitura = fopen("Contas2.txt", "r");
				
				fscanf(leitura, "%[^'\n']s", texto2);
				
				while(fgets(texto, 1000, leitura) != NULL){
					if(vet2[k] - j == 0){
						fprintf(arquivo, "%s\n", texto2);
						break;
					}
					
					if(vet2[k] - j == 1){
						fprintf(arquivo, "%s\n", texto2);
					}
					
					if(vet2[k] - j == 2){
						fprintf(arquivo, "%s\n", texto2);
					}
					
					if(vet2[k] - j == 3){
						fprintf(arquivo, "%s\n", texto2);
					}
					
					fscanf(leitura, "%[^'\n']s", texto2);
					j++;
				}
				
				k++;
				fclose(leitura);
				fclose(arquivo);
			}
			
		}
		system("cls");
		if((v == 1) && (v2 == 1)){ //IMPRIME AS CONTAS DO CLIENTE
			i = 0;
			leitura = fopen("Contas3.txt", "r");
			printf("Conta(s) do cliente %s em ordem decrescente de saldo:\n", nome);
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				
				if(i == 3){
					printf("SALDO do cliente: %s\n\n", texto2);
					i = -1;
				}
				
				if(i == 2){
					printf("NUMERO DA CONTA do cliente: %s\n", texto2);
				}
				
				if(i == 1){
					printf("AGENCIA do cliente: %s\n", texto2);
				}
				
				if(i == 0){
					printf("NOME do cliente: %s\n", texto2);
				}
				
				i++;
				
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);

		}
		system("pause");
	}
	
	void buscapCpf(){
		char cpf[80], texto[1000], texto2[1000], nome[80];
		FILE *leitura;
		FILE *arquivo;
		int i = 0, v = 0, v2 = 0, cont = 0, k = 0;
		float saldo;
		float vet[cont], auxf;
		int vet2[cont], auxi, j;
		
		system("cls");
		printf("Por favor, digite o CPF/CNPJ do cliente:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &cpf);
		
		leitura = fopen("Clientes.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			if(strcmp(cpf, texto2) == 0){
				
				v = 1;                                          // ACHA A POSICAO DO "NOME"
				break;
			}
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		i--;
		
		if(v == 0){
			system("cls");
			printf("Cliente nao cadastrado!\n");
			system("pause");
		}else if(v == 1){
			leitura = fopen("Clientes.txt", "r");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				i--;
				if(i == 0){
					strcpy(nome, texto2);                       // COLOCA O NOME DO CLIENTE EM "NOME"
					v2 = 1;
					break;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
		}
		
		if((v == 1) && (v2 == 0)){
			system("cls");
			printf("Conta nao cadastrada!\n");
			system("pause");
		}else if((v == 1) && (v2 == 1)){ //COLOCANDO OS DADOS DAS CONTAS DO CLIENTE EM CONTAS2
			i = 0;
			leitura = fopen("Contas.txt", "r");
			arquivo = fopen("Contas2.txt", "w");
			fclose(arquivo);
			arquivo = fopen("Contas2.txt", "a");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				if(i == 1){
					fscanf(leitura, "%f", &saldo);
					fprintf(arquivo, "%f\n", saldo);
					i--;
				}
				
				if(i == 2){
					fprintf(arquivo, "%s\n", texto2);
					i--;
				}
				
				if(i == 3){
					fprintf(arquivo, "%s\n", texto2);
					i--;
				}
				
				if(strcmp(nome, texto2) == 0){
					fprintf(arquivo, "%s\n", texto2);
					i = 3;
					cont++;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
			fclose(arquivo);
		}
		
		if((v == 1) && (v2 == 1)){
			
			leitura = fopen("Contas2.txt", "r");
			
			i = 1;
			while(fgets(texto, 1000, leitura) != NULL){
				if(i%4 == 0){
					fscanf(leitura, "%f", vet[k]);           //SALVA OS SALDOS NO VET[K]
					vet2[k] = i-1;                          //SALVA AS POSICOES DO SALDO NO VET2[K]
					k++;
				}
				i++;
			}
			fclose(leitura);
			
		}
		
		if((v == 1) && (v2 == 1)){ // COLOCA OS VETORES EM ORDEM DECRESCETE
			for(k = 0; k < cont; k++){
				for(i = k+1; i < cont; i++){
					if(vet[k] < vet[i]){
						auxf = vet[i];
						vet[i] = vet[k];
						vet[k] = auxf;
						
						auxi = vet2[i];
						vet2[i] = vet2[k];
						vet2[k] = auxi;
					}  
				}
			}	
		}
		
		
		if((v == 1) && (v2 == 1)){// SALVA NO ARQUIVOS CONTAS3 EM ORDEM DECRESCENTE DE SALDO
			arquivo = fopen("Contas3.txt", "w");
			fclose(arquivo);
			k = 0;
			for(i = 0; i < cont; i++){
				j = 0;
				arquivo = fopen("Contas3.txt", "a");
				leitura = fopen("Contas2.txt", "r");
				
				fscanf(leitura, "%[^'\n']s", texto2);
				
				while(fgets(texto, 1000, leitura) != NULL){
					if(vet2[k] - j == 0){
						fprintf(arquivo, "%s\n", texto2);
						break;
					}
					
					if(vet2[k] - j == 1){
						fprintf(arquivo, "%s\n", texto2);
					}
					
					if(vet2[k] - j == 2){
						fprintf(arquivo, "%s\n", texto2);
					}
					
					if(vet2[k] - j == 3){
						fprintf(arquivo, "%s\n", texto2);
					}
					
					fscanf(leitura, "%[^'\n']s", texto2);
					j++;
				}
				
				k++;
				fclose(leitura);
				fclose(arquivo);
			}
			
		}
		system("cls");
		if((v == 1) && (v2 == 1)){ //IMPRIME AS CONTAS DO CLIENTE
			i = 0;
			leitura = fopen("Contas3.txt", "r");
			printf("Conta(s) do cliente %s em ordem decrescente de saldo:\n", nome);
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				
				if(i == 3){
					printf("SALDO do cliente: %s\n\n", texto2);
					i = -1;
				}
				
				if(i == 2){
					printf("NUMERO DA CONTA do cliente: %s\n", texto2);
				}
				
				if(i == 1){
					printf("AGENCIA do cliente: %s\n", texto2);
				}
				
				if(i == 0){
					printf("NOME do cliente: %s\n", texto2);
				}
				
				i++;
				
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);

		}
		system("pause");
	}
	
	void listarConta(){
		int i;
		
		printf("Deseja buscar o cliente atraves de:\n");
		printf("1 - CODIGO\n");
		printf("2 - CPF/CNPJ\n");
		fflush(stdin);
		scanf("%d", &i);
		if(i == 1){
			buscapCodigo();
		}else if(i == 2){
			buscapCpf();
		}else{
			system("cls");
			printf("Numero nao compreendido\n");
			cadastraConta();
		}
	}
	
	void depositaConta(){
		time_t data_tempo;
		time(&data_tempo);
		FILE *leitura;
		FILE *arquivo;
		char texto[1000], texto2[1000], descricao[100];
		int i = 0, v = 0, d, a;
		float valor, saldoa, saldof;
		struct Contas conta;
		struct tm *data = localtime(&data_tempo);
		
		printf("Por favor, digite a AGENCIA da conta:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &conta.agencia);
		system("cls");
		printf("Por favor, digite o NUMERO DA CONTA:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &conta.ndaConta);
		system("cls");
		
		leitura = fopen("Contas.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE A POSICAO DO NOME DO CLIENTE
			if(strcmp(conta.agencia, texto2) == 0){
				fscanf(leitura, "%[^'\n']s", texto2);
				if(strcmp(conta.ndaConta, texto2) == 0){
					v = 1;
					break;
				}
			}
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		d = i;
		i--;
		fclose(leitura);
		
		if(v == 0){
			printf("Conta nao cadastrada!\n");
		}else if(v == 1){
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE O NOME DO CLIENTE E SALVA EM CONTA.CLIENTE
				if(i == 0){
					strcpy(conta.cliente, texto2);
					printf("NOME: %s\n", conta.cliente);
					printf("AGENCIA: %s\n", conta.agencia);
					printf("NUMERO DA CONTA: %s\n", conta.ndaConta);
				}
				if(i == -3){
					fflush(stdin);
					fscanf(leitura, "%[^'\n']s", texto2);	          //DESCOBRE O SALDO ATUAL DO CLIENTE
					saldoa = atof(texto2);
					printf("SALDO atual: R$%0.2f\n", saldoa);
					break;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i--;
			}
			fclose(leitura);
		}
		
		if(v == 1){
			i = 1;
			printf("Qual valor que deseja depositar?\n");
			fflush(stdin);
			scanf("%f", &valor);
			system("cls");
			printf("Informe a DESCRICAO do deposito:\n");
			fflush(stdin);
			scanf("%[^'\n']s", &descricao);
			system("cls");
			
			saldof = (valor + saldoa);
			
			leitura = fopen("Contas.txt", "r");
			arquivo = fopen("Contas2.txt", "w");
			fclose(arquivo);
			arquivo = fopen("Contas2.txt", "a");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){            //COPIA OS DADOS DE CONTAS.TXT PARA CONTAS2.TXT
				if(i%4 == 1){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i%4 == 2){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i%4 == 3){
					fprintf(arquivo, "%s\n", texto2);
				
				}else if(i%4 == 0){
					fscanf(leitura, "%[^'\n']s", texto2);
					fprintf(arquivo, "%s\n", texto2);	
					i = 0;
				}
				
				
				fscanf(leitura, "%[^'\n']s", texto2);
				i++;
			}
			
			fclose(leitura);
			fclose(arquivo);
			
		}
		
		if(v == 1){
			i = 1;
			arquivo = fopen("Contas.txt", "w");
			leitura = fopen("Contas2.txt", "r");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){ //COPIA OS DAODS DO CONTAS2.TXT PARA CONTAS.TXT FAZENDO AS ALTERAÇÕES NO SALDO
				if(i == d){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i == d + 1){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i == d + 2){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i == d + 3){
					fprintf(arquivo, "%f\n", saldof);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i%4 == 1){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i%4 == 2){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i%4 == 3){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%f", &saldoa);	
				}else if(i%4 == 0){
					fprintf(arquivo, "%f\n", saldoa);
					fscanf(leitura, "%[^'\n']s", texto2);
				}
				i++;
			}
			fclose(arquivo);
			fclose(leitura);
		}
		
		if(v == 1){
			arquivo = fopen("Transacao.txt", "a");
			
			fprintf(arquivo, "%s\n", conta.agencia);
			fprintf(arquivo, "%s\n", conta.ndaConta);
			fprintf(arquivo, "%d/%d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);
			fprintf(arquivo, "+%f\n", valor);
			fprintf(arquivo, "%s\n", descricao);
			fclose(arquivo);
		}
		system("pause");
		
	}
	
	void saqueConta(){
		time_t data_tempo;
		time(&data_tempo);
		FILE *leitura;
		FILE *arquivo;
		char texto[1000], texto2[1000], descricao[100];
		int i = 0, v = 0, d, v2 = 0;
		float valor, saldoa, saldof;
		struct Contas conta;
		struct tm *data = localtime(&data_tempo);
		
		printf("Por favor, digite a AGENCIA da conta:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &conta.agencia);
		system("cls");
		printf("Por favor, digite o NUMERO DA CONTA:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &conta.ndaConta);
		system("cls");
		
		leitura = fopen("Contas.txt", "r");
		
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE A POSICAO DO NOME DO CLIENTE
			if(strcmp(conta.agencia, texto2) == 0){
				fscanf(leitura, "%[^'\n']s", texto2);
				if(strcmp(conta.ndaConta, texto2) == 0){
					v = 1;
					break;
				}
			}
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		d = i;
		i--;
		fclose(leitura);
		
		if(v == 0){
			printf("Conta nao cadastrada!\n");
		}else if(v == 1){
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE O NOME DO CLIENTE E SALVA EM CONTA.CLIENTE
				if(i == 0){
					strcpy(conta.cliente, texto2);
					printf("NOME: %s\n", conta.cliente);
					printf("AGENCIA: %s\n", conta.agencia);
					printf("NUMERO DA CONTA: %s\n", conta.ndaConta); //IMPRIME AS INFORMACOES DA CONTA
				}
				if(i == -3){
					fflush(stdin);
					fscanf(leitura, "%[^'\n']s", texto2);            //DESCOBRE O SALDO ATUAL DO CLIENTE
					saldoa = atof(texto2);
					printf("SALDO atual: R$%0.2f\n", saldoa);
					break;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i--;
			}
			fclose(leitura);
		}
		
		if(v == 1){
			i = 1;
			printf("Qual valor que deseja realizar o saque?\n");
			fflush(stdin);
			scanf("%f", &valor);
			system("cls");
		
		}
		
		saldof = saldoa - valor;
		if(saldof < 0){ // VERIFICA SE É POSSIVEL FAZER O SAQUE
			printf("Saldo insuficiente para essa saque!\n");
			v2 = 1;
		}
		
		if((v == 1) && (v2 == 0)){
			printf("Informe a DESCRICAO do deposito:\n");
			fflush(stdin);
			scanf("%[^'\n']s", &descricao);
			system("cls");
			
			leitura = fopen("Contas.txt", "r");
			arquivo = fopen("Contas2.txt", "w");
			fclose(arquivo);
			arquivo = fopen("Contas2.txt", "a");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){            //COPIA OS DADOS DE CONTAS.TXT PARA CONTAS2.TXT
				if(i%4 == 1){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i%4 == 2){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i%4 == 3){
					fprintf(arquivo, "%s\n", texto2);
				
				}else if(i%4 == 0){
					fscanf(leitura, "%[^'\n']s", texto2);
					fprintf(arquivo, "%s\n", texto2);
					i = 0;
				}
				
				
				fscanf(leitura, "%[^'\n']s", texto2);
				i++;
			}
			
			fclose(leitura);
			fclose(arquivo);
			
		}
		
		if((v == 1) && (v2 == 0)){
			i = 1;
			arquivo = fopen("Contas.txt", "w");
			leitura = fopen("Contas2.txt", "r");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){ //COPIA OS DAODS DO CONTAS2.TXT PARA CONTAS.TXT FAZENDO AS ALTERAÇÕES NO SALDO
				if(i == d){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i == d + 1){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i == d + 2){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i == d + 3){
					fprintf(arquivo, "%f\n", saldof);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i%4 == 1){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i%4 == 2){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i%4 == 3){
					fprintf(arquivo, "%s\n", texto2);
					fscanf(leitura, "%f", &saldoa);	
				}else if(i%4 == 0){
					fprintf(arquivo, "%f\n", saldoa);
					fscanf(leitura, "%[^'\n']s", texto2);
				}
				i++;
			}
			fclose(arquivo);
			fclose(leitura);
		}
		
		if((v == 1) && (v2 == 0)){
			arquivo = fopen("Transacao.txt", "a");
			
			fprintf(arquivo, "%s\n", conta.agencia);
			fprintf(arquivo, "%s\n", conta.ndaConta);
			fprintf(arquivo, "%d/%d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);
			fprintf(arquivo, "-%f\n", valor);
			fprintf(arquivo, "%s\n", descricao);
			fclose(arquivo);
		}
		system("pause");
	}

//-------------------------------------------------------------------------------------------------------------------------------------
int main(){
	char leitor;
	int contClientes = 0, contContas = 0, contTransacoes = 0, i;
	FILE *arquivo;
	arquivo = fopen("Clientes.txt", "w");
	fclose(arquivo);
	arquivo = fopen("Contas.txt", "w");
	fclose(arquivo);
	arquivo = fopen("Transacao.txt", "w");
	fclose(arquivo);
	 
	 
	for(i = 0; leitor != 'S'; i++){
		system("cls");
		fflush(stdin);
		bem_Vindo();                           // Início da execução

		scanf("%c", &leitor);                 // lê as opções de acesso
		system("cls");                        // Limpa tela
	
	
		if(leitor == 'S'){
			break;                            // Finalisa o código
		
		}else if(leitor == 'C'){
			gerenciarClientes();              //Chama a função 
			fflush(stdin);
			scanf("%c", &leitor);
			system("cls");
			if(leitor == 'S'){
				break;                           // Finalisa o código
				
			}else if(leitor == 'C'){
				contClientes++;
				cadastraCliente();                 //Chama a função 
				
			}else if(leitor == 'L'){
				todosClientes();              //Chama a função
			}else if(leitor == 'B'){
				buscaCliente();               //Chama a função
			}else if(leitor == 'A'){
				atualizaCliente();
			}else if(leitor == 'E'){
				excluiCliente();	
			}
			
		}else if (leitor == 'T'){
			gerenciarContas();
			fflush(stdin);
			scanf("%c", &leitor);
			system("cls");
			if(leitor == 'S'){
				break;                            // Finalisa o código
			}else if(leitor == 'C'){
				cadastraConta();
			}else if(leitor == 'R'){
				listarContas();
			}else if(leitor == 'L'){
				listarConta();
			}else if(leitor == 'D'){
				depositaConta();
			}else if(leitor == 'W'){
				saqueConta();
			}
		}
		

	}


}

//LUCAS REIS DAS CHAGAS
//202104991

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
	
	
	void bem_Vindo(){ // Inicia o c�digo
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
		printf("L - Listar todas as contas de um cliente\n");
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
			
			conta.saldo = 0;			
		}
		
		leitura = fopen("Contas.txt", "r");
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){	// VERIFICA SE A CONTA JA EXISTE
			if(strcmp(conta.agencia, texto2) == 0){
				fscanf(leitura, "%[^'\n']s", texto2);
				if(strcmp(texto2, conta.ndaConta) == 0){
					v4 = 1;
				}
			}
			
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		fclose(leitura);
		
	

		if(v4 == 1){
			system("cls");
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
		int i = 4, cont = 0, x, y, k = 0, v = 0, v2 = 0, v3 = 0, posicao[200];
		char texto[1000], texto2[1000], ordem[200][80], aux[80];
		float saldo1, saldo2, ordemS[200], auxf;
	
		leitura = fopen("Contas.txt", "r");	
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){ // COLOCA OS NOME DE TODOS CLIENTES NO VETOR ORDEM
			if(i == 4){
				strcpy(ordem[cont], texto2);
				cont++;
				i = 0;
				v = 1;
			}
			if(i == 3){
				auxf = atof(texto2);
				ordemS[cont - 1] = auxf;
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
						
						auxf = ordemS[x];
						ordemS[x] = ordemS[y];
						ordemS[y] = auxf;
					}
				}
			}
		}else if(ftell(leitura) == 0){
			printf("Nenhuma conta cadastrada!\n");
		}
		fclose(leitura);
		
		
		if(v == 1){
			for(i = 0; i < cont; i++){
				for(x = 0; x < cont; x++){
					for(y = x + 1; y < x + 2; y++){
						if((strcmp(ordem[x], ordem[y]) == 0) && (ordemS[x] < ordemS[y])){ // COLOCA OS VETORES EM ORDEM DECRESCENTE
							auxf = ordemS[x];
							ordemS[x] = ordemS[y];
							ordemS[y] = auxf;
						}
					}
				}
			}
		}
			
		i = 4;
		
		for(i = 0; i < cont; i++){
			x = 0;
			y = 0;
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){ // COLOCA OS NOME DE TODOS CLIENTES NO VETOR ORDEM
				if(x == 0){
					if(strcmp(ordem[i], texto2) == 0){
						v2 = 1;
					}

				}
				if(x == 3){
					if((v2 == 1) && (ordemS[i] == atof(texto2))){
						posicao[i] = y - 3;
						v2 = 0;
						break;
					}
					v2 = 0;
					x = -1;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				x++;
				y++;
			}
			fclose(leitura);
		}
				
		for(i = 0; i < cont; i++){
			x = 0;
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				if(x == posicao[i]){
					printf("NOME: %s\n", texto2);
				}else if(x == posicao[i] + 1){
					printf("AGENCIA: %s\n", texto2);
				}else if(x == posicao[i] + 2){
					printf("NUMERO DA CONTA: %s\n", texto2);
				}else if(x == posicao[i] + 3){
					auxf = atof(texto2);
					printf("SALDO: R$%0.2f\n\n", auxf);
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				x++;
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
					saldo = atof(texto2);
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
					vet[k] = atof(texto2);
					vet2[k] = i-1;                          //SALVA AS POSICOES DO SALDO NO VET2[K]
					k++;
				}
				i++;
				fscanf(leitura, "%[^'\n']s", texto2);
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
						saldo = atof(texto2);
						fprintf(arquivo, "%f\n", saldo);
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
					saldo = atof(texto2);
					printf("SALDO do cliente: R$%0.2f\n\n", saldo);
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
					saldo = atof(texto2);
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
					fscanf(leitura, "%['\n']s", texto2);           //SALVA OS SALDOS NO VET[K]
					saldo = atof(texto2);
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
		
		
		if((v == 1) && (v2 == 1)){                     // SALVA NO ARQUIVO CONTAS3 EM ORDEM DECRESCENTE DE SALDO
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
					saldo = atof(texto2);
					printf("SALDO do cliente: R$%0.2f\n\n", saldo);
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
				fprintf(arquivo, "%s\n", texto2);			
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
			while(fgets(texto, 1000, leitura) != NULL){ //COPIA OS DAODS DO CONTAS2.TXT PARA CONTAS.TXT FAZENDO AS ALTERA��ES NO SALDO
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
					fscanf(leitura, "%[^'\n']s", texto2);
				}else if(i%4 == 0){
					saldoa = atof(texto2);
					fprintf(arquivo, "%f\n", saldoa);
					fscanf(leitura, "%[^'\n']s", texto2);
				}
				i++;
			}
			fclose(arquivo);
			fclose(leitura);
		}
		
		if(v == 1){
			long long int tempdias;
			tempdias = data->tm_mday + 30*(data->tm_mon + 1) + 365*(data->tm_year + 1900);
			arquivo = fopen("Transacao.txt", "a");
			
			fprintf(arquivo, "%lld\n", tempdias);
			fprintf(arquivo, "%s\n", conta.agencia);
			fprintf(arquivo, "%s\n", conta.ndaConta);
			fprintf(arquivo, "%d/%d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);
			fprintf(arquivo, "+R$%0.2f\n", valor);
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
		int i = 0, v = 0, d, v2 = 0, saldoint, vet[7];
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
					saldoa = atof(texto2);           //DESCOBRE O SALDO ATUAL DO CLIENTE
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
		saldoint = (int)valor;
		saldof = saldoa - valor;
		if(saldof < 0){ // VERIFICA SE � POSSIVEL FAZER O SAQUE
			printf("Saldo insuficiente para esse saque!\n");
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
				fprintf(arquivo, "%s\n", texto2);
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			
			fclose(leitura);
			fclose(arquivo);
			
		}
		
		if((v == 1) && (v2 == 0)){
			i = 1;
			arquivo = fopen("Contas.txt", "w");
			leitura = fopen("Contas2.txt", "r");
			
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){ //COPIA OS DAODS DO CONTAS2.TXT PARA CONTAS.TXT FAZENDO AS ALTERA��ES NO SALDO
				if(i == d){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i == d + 1){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i == d + 2){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i == d + 3){
					fprintf(arquivo, "%f\n", saldof);
				}else if(i%4 == 1){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i%4 == 2){
					fprintf(arquivo, "%s\n", texto2);
				}else if(i%4 == 3){
					fprintf(arquivo, "%s\n", texto2);	
				}else if(i%4 == 0){
					saldoa = atof(texto2);
					fprintf(arquivo, "%f\n", saldoa);
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i++;
			}
			fclose(arquivo);
			fclose(leitura);
		}
		
		if((v == 1) && (v2 == 0)){
			long long int tempdias;
			tempdias = data->tm_mday + 30*(data->tm_mon + 1) + 365*(data->tm_year + 1900);
			arquivo = fopen("Transacao.txt", "a");
			
			fprintf(arquivo, "%lld\n", tempdias);
			fprintf(arquivo, "%s\n", conta.agencia);
			fprintf(arquivo, "%s\n", conta.ndaConta);
			fprintf(arquivo, "%d/%d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);
			fprintf(arquivo, "-R$%0.2f\n", valor);
			fprintf(arquivo, "%s\n", descricao);
			fclose(arquivo);
		}
		
		for(i = 0; i < 7; i++){
			vet[i] = 0;
		}
	
	
		while(saldoint >= 200){
			vet[0] ++;
			saldoint = saldoint - 200;
		}
		while(saldoint >= 100){
			vet[1] ++;
			saldoint = saldoint - 100;
		}
		while(saldoint >= 50){
			vet[2] ++;
			saldoint = saldoint - 50;
		}
		while(saldoint >= 20){
			vet[3] ++;
			saldoint = saldoint - 20;
		}
		while(saldoint >= 10){
			vet[4] ++;
			saldoint = saldoint - 10;
		}
		while(saldoint >= 5){
			vet[5] ++;
			saldoint = saldoint - 5;
		}
		while(saldoint > 2){
			vet[6] ++;
			saldoint = saldoint - 2;
		}

		if (v2 == 0){
			printf("Quantidade de NOTAS SACADAS:\n");
			printf("%d -- R$200\n", vet[0]);
			printf("%d -- R$100\n", vet[1]);
			printf("%d -- R$50\n", vet[2]);
			printf("%d -- R$20\n", vet[3]);
			printf("%d -- R$10\n", vet[4]);
			printf("%d -- R$5\n", vet[5]);
			printf("%d -- R$2\n", vet[6]);
		}

		
		system("pause");
	}

	void transferenciaContas(){
		time_t data_tempo;
		time(&data_tempo);
		FILE *leitura;
		FILE *arquivo;
		char texto[1000], texto2[1000];
		int v = 0, v1 = 0, i = 0, d = 0, d1 = 0;
		float transferencia;
		
		struct Contas contasaq;
		struct Contas contadep;
		struct tm *data = localtime(&data_tempo);
		
		printf("Informe a AGENCIA da conta que realizara o SAQUE:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &contasaq.agencia);
		system("cls");
		printf("Informe o NUMERO DA CONTA que realizara o SAQUE:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &contasaq.ndaConta);
		system("cls");
		
		leitura = fopen("Contas.txt", "r");
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE A POSICAO DO NOME DO CLIENTE
			if(strcmp(contasaq.agencia, texto2) == 0){
				fscanf(leitura, "%[^'\n']s", texto2);
				if(strcmp(contasaq.ndaConta, texto2) == 0){
					v = 1;
					break;
				}
			}
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		fclose(leitura);
		
		i--;
		d = i;
		
		if(v == 0){
			printf("Conta nao cadastrada!\n");
		}else if(v == 1){
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){                 //DESCOBRE O NOME DO CLIENTE E SALVA EM CONTASAQ.CLIENTE
				if(i == 0){
					strcpy(contasaq.cliente, texto2);
					printf("NOME: %s\n", contasaq.cliente);
					printf("AGENCIA: %s\n", contasaq.agencia);
					printf("NUMERO DA CONTA: %s\n", contasaq.ndaConta); //IMPRIME AS INFORMACOES DA CONTA
				}
				if(i == -3){
					contasaq.saldo = atof(texto2);                       //DESCOBRE O SALDO ATUAL DO CLIENTE
					printf("SALDO atual: R$%0.2f\n", contasaq.saldo);
					break;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i--;
			}
			fclose(leitura);
			printf("Conta que realizara o SAQUE!\n");
			system("pause");
		}
		
		system("cls");
		printf("Informe a AGENCIA da conta que realizara o DEPOSITO:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &contadep.agencia);
		system("cls");
		printf("Informe o NUMERO DA CONTA que realizara o DEPOSITO:\n");
		fflush(stdin);
		scanf("%[^'\n']s", &contadep.ndaConta);
		system("cls");
		
		i = 0;
		v = 0;
		
		leitura = fopen("Contas.txt", "r");
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE A POSICAO DO NOME DO CLIENTE
			if(strcmp(contadep.agencia, texto2) == 0){
				fscanf(leitura, "%[^'\n']s", texto2);
				if(strcmp(contadep.ndaConta, texto2) == 0){
					v = 1;
					break;
				}
			}
			fscanf(leitura, "%[^'\n']s", texto2);
			i++;
		}
		fclose(leitura);
		
		i--;
		d1 = i;
		
		if(v == 0){
			printf("Conta nao cadastrada!\n");
		}else if(v == 1){
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE O NOME DO CLIENTE E SALVA EM CONTADEP.CLIENTE
				if(i == 0){
					strcpy(contadep.cliente, texto2);
					printf("NOME: %s\n", contadep.cliente);
					printf("AGENCIA: %s\n", contadep.agencia);
					printf("NUMERO DA CONTA: %s\n", contadep.ndaConta); //IMPRIME AS INFORMACOES DA CONTA
				}
				if(i == -3){
					contadep.saldo = atof(texto2);             //DESCOBRE O SALDO ATUAL DO CLIENTE
					printf("SALDO atual: R$%0.2f\n", contadep.saldo);
					break;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i--;
			}
			fclose(leitura);
			printf("Conta que realizara o DEPOSITO!\n");
			system("pause");
		}
		
		if(v == 1){
			system("cls");
			printf("Informe o valor da transferencia:\n");
			scanf("%f", &transferencia);
			
			if((contasaq.saldo - transferencia) >= 0){
				v1 = 1;
			}else{
				v = 0;
			}
			
			if(v1 == 0){
				printf("Valor para saque indisponivel!\n");
			}
		}
		
		if((v == 1) && (v1 == 1)){
			i = 0;
			contasaq.saldo = contasaq.saldo - transferencia;
			contadep.saldo = contadep.saldo + transferencia;
			
			leitura = fopen("Contas.txt", "r");
			arquivo = fopen("Contas2.txt", "w");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				if(d+3 == i){
					fprintf(arquivo,"%f\n", contasaq.saldo);
				}else if(d1+3 == i){
					fprintf(arquivo,"%f\n", contadep.saldo);
				}else{
					fprintf(arquivo,"%s\n", texto2);
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i++;
			}
			fclose(leitura);
			fclose(arquivo);
			
			leitura = fopen("Contas2.txt", "r");
			arquivo = fopen("Contas.txt", "w");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){
				
				fprintf(arquivo,"%s\n", texto2);
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(arquivo);
			fclose(leitura);
			
			long long int tempdias;
			tempdias = data->tm_mday + 30*(data->tm_mon + 1) + 365*(data->tm_year + 1900);
			
			arquivo = fopen("transacao.txt","a");
			fprintf(arquivo, "%lld\n", tempdias);
			fprintf(arquivo,"%s\n", contasaq.agencia);
			fprintf(arquivo,"%s\n", contasaq.ndaConta);
			fprintf(arquivo, "%d/%d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);
			fprintf(arquivo,"-R$%0.2f\n", transferencia);
			fprintf(arquivo,"Transferencia para conta:%s-%s\n", contadep.agencia, contadep.ndaConta);
			
			fprintf(arquivo, "%lld\n", tempdias);
			fprintf(arquivo,"%s\n", contadep.agencia);
			fprintf(arquivo,"%s\n", contadep.ndaConta);
			fprintf(arquivo, "%d/%d/%d\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);
			fprintf(arquivo,"+R$%0.2f\n", transferencia);
			fprintf(arquivo,"Transferencia de conta:%s-%s\n", contasaq.agencia, contasaq.ndaConta);
			fclose(arquivo);
		}
		
		system("pause");
	}
	
	void extratoConta(){
		time_t data_tempo;
		time(&data_tempo);
		FILE *leitura;
		FILE *arquivo;
		int i = 0, v = 0, ndias = 0, d = 0, cont = 0, cont1 = 0, pos[1000], v1 = 0, v2 = 0, k = 0, j;
		int dia, mes, ano;
		long long int diaatual, diasContas[1000];
		char texto[1000], texto2[1000];
		
		
		struct tm *data = localtime(&data_tempo);
		struct Contas conta;
		printf("Informe a AGENCIA da conta:\n");
		fflush(stdin);
		scanf("%[^'\n']s", conta.agencia);
		system("cls");
		printf("Informe O NUMERO DA CONTA:\n");
		fflush(stdin);
		scanf("%[^'\n']s", conta.ndaConta);
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
		fclose(leitura);
		
		i--;
		d = i;
		
		if(v == 0){
			printf("Conta nao cadastrada!\n");
		}else if(v == 1){
			leitura = fopen("Contas.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){                 //DESCOBRE O NOME DO CLIENTE E SALVA EM CONTASAQ.CLIENTE
				if(i == 0){
					strcpy(conta.cliente, texto2);
					printf("NOME: %s\n", conta.cliente);
					printf("AGENCIA: %s\n", conta.agencia);
					printf("NUMERO DA CONTA: %s\n", conta.ndaConta); //IMPRIME AS INFORMACOES DA CONTA
				}
				if(i == -3){
					conta.saldo = atof(texto2);                       //DESCOBRE O SALDO ATUAL DO CLIENTE
					printf("SALDO atual: R$%0.2f\n", conta.saldo);
					break;
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i--;
			}
			fclose(leitura);
			printf("Por favor, informe o NUMERO DE DIAS que deseja exibir no extrato!\n");
			scanf("%d", &ndias);
			system("cls");
			
			dia = data->tm_mday;
			mes = data->tm_mon +1;
			ano = data->tm_year + 1900;
			diaatual = dia + (mes*30) + (ano*365);
		
			i = 0;	
			leitura = fopen("Transacao.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			while(fgets(texto, 1000, leitura) != NULL){            //DESCOBRE A POSICAO DAS TRANSACOES FEITAS NA CONTA
				if(strcmp(conta.agencia, texto2) == 0){
					fscanf(leitura, "%[^'\n']s", texto2);
					if(strcmp(conta.ndaConta, texto2) == 0){
						pos[cont] = i-1;
						cont++;
						v1 = 1;
					}
				}
				fscanf(leitura, "%[^'\n']s", texto2);
				i++;
			}
			fclose(leitura);
		}
		
		if((v == 1) && v1 == 0){
			printf("Nenhuma transacao feita na conta!\n");
		}else if((v == 1) && (v1 == 1)){
			arquivo = fopen("Contas2.txt", "w");
			for(i = 0; i < cont; i++){
				leitura = fopen("Transacao.txt", "r");
				k = 0;
				
				fscanf(leitura, "%[^'\n']s", texto2);
				while(fgets(texto, 1000, leitura) != NULL){            //SALVA TODAS AS CONTAS DO CLIENTE EM CONTAS2.TXT
					if(k == pos[i]){
						fprintf(arquivo, "%s\n", texto2);
					}else if(k == pos[i] + 1){
						fprintf(arquivo, "%s\n", texto2);
					}else if(k == pos[i] + 2){
						fprintf(arquivo, "%s\n", texto2);
					}else if(k == pos[i] + 3){
						fprintf(arquivo, "%s\n", texto2);
					}else if(k == pos[i] + 4){
						fprintf(arquivo, "%s\n", texto2);
					}else if(k == pos[i] + 5){
						fprintf(arquivo, "%s\n", texto2);
					}
					fscanf(leitura, "%[^'\n']s", texto2);
					k++;
				}
				fclose(leitura);
			}
			fclose(arquivo);
			
			arquivo = fopen("Contas3.txt", "w");
			for(i = 0; i < cont; i++){
				
				k = 1;
				leitura = fopen("Contas2.txt", "r");
				fscanf(leitura, "%[^'\n']s", texto2);
				while(fgets(texto, 1000, leitura) != NULL){
					if(k == 6*i + 1){
						diasContas[cont1] = atoi(texto2);
						if((diaatual - diasContas[cont1]) <= ndias){
							v2 = 1;
						}
						cont1++;
						break;
					}
					k++;
					fscanf(leitura, "%[^'\n']s", texto2);
				}
				fclose(leitura);
				
				if(v2 == 1){
					v2 = 0;
					leitura = fopen("Contas2.txt", "r");
					j = 1;
					
					fscanf(leitura, "%[^'\n']s", texto2);
					while(fgets(texto, 1000, leitura) != NULL){ // SALVA NO ARQUIVO CONTAS3.TXT AS TRANSACOES FEITAS DESDE nDIAS PEDIDOS
						if(j == k+1){
							fprintf(arquivo, "%s\n", texto2);
						}else if(j == k+2){
							fprintf(arquivo, "%s\n", texto2);
						}else if(j == k+3){
							fprintf(arquivo, "%s\n", texto2);
						}else if(j == k+4){
							fprintf(arquivo, "%s\n", texto2);
						}else if(j == k+5){
							fprintf(arquivo, "%s\n", texto2);
						}
						j++;
						fscanf(leitura, "%[^'\n']s", texto2);
					}
					fclose(leitura);
					
				} 
			}
			fclose(arquivo);
			
			printf("Essas sao as transacoes realizadas em %d dia(s):\n", ndias);
			leitura = fopen("Contas3.txt", "r");
			fscanf(leitura, "%[^'\n']s", texto2);
			i = 1; 
			while(fgets(texto, 1000, leitura) != NULL){     // SALVA NO ARQUIVO CONTAS3.TXT AS TRANSACOES FEITAS DESDE nDIAS PEDIDOS
				if(i%5 == 1){
					printf("AGENCIA: %s\n", texto2);
				}else if(i%5 == 2){
					printf("NUMERO DA CONTA: %s\n", texto2);
				}else if(i%5 == 3){
					printf("DATA DA TRANSACAO: %s\n", texto2);
				}else if(i%5 == 4){
					printf("VALOR DA TRANSACAO: %s\n", texto2);
				}else if(i%5 == 0){
					printf("DESCRICAO: %s\n\n", texto2);
					i = 0;
				}
				i++;
				fscanf(leitura, "%[^'\n']s", texto2);
			}
			fclose(leitura);
			
		}
		system("pause");
	}
	
	int verificaClientes(){
		FILE *leitura;
		char texto[1000], texto2[1000];
		int i = 0, retorno = 0;
		
		leitura = fopen("Clientes.txt", "r");
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		retorno = i/5;
		
		fclose(leitura);
		return(retorno);
	}
	
	int verificaContas(){
		FILE *leitura;
		char texto[1000], texto2[1000];
		int i = 0, retorno = 0;
		
		leitura = fopen("Contas.txt", "r");
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		retorno = i/4;
		
		fclose(leitura);
		return(retorno);
	}
	
	int verificaTransacoes(){
		FILE *leitura;
		char texto[1000], texto2[1000];
		long int i = 0;
		int retorno = 0;
		
		leitura = fopen("Transacao.txt", "r");
		fscanf(leitura, "%[^'\n']s", texto2);
		while(fgets(texto, 1000, leitura) != NULL){
			i++;
			fscanf(leitura, "%[^'\n']s", texto2);
		}
		retorno = i/6;
		
		fclose(leitura);
		return(retorno);
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
		bem_Vindo();                           // In�cio da execu��o

		scanf("%c", &leitor);                 // l� as op��es de acesso
		system("cls");                        // Limpa tela
	
	
		if((leitor == 'S') || (leitor == 's')){
			break;                            // Finalisa o c�digo
		
		}else if((leitor == 'C') || (leitor == 'c')){
			gerenciarClientes();              //Chama a fun��o 
			fflush(stdin);
			scanf("%c", &leitor);
			system("cls");
			if((leitor == 'S') || (leitor == 's')){
				break;                           // Finalisa o c�digo
				
			}else if((leitor == 'C') || (leitor == 'c')){
				if(contClientes == 100){
					printf("Numero de CLIENTES chegou ao limite!\n");
					system("pause");
				}else {
					cadastraCliente();                 //Chama a fun��o 
				}
				
			}else if((leitor == 'L') || (leitor == 'l')){
				todosClientes();              //Chama a fun��o
			}else if((leitor == 'B') || (leitor == 'b')){
				buscaCliente();               //Chama a fun��o
			}else if((leitor == 'A') || (leitor == 'a')){
				atualizaCliente();
			}else if((leitor == 'E') || (leitor == 'e')){
				excluiCliente();	
			}
			
		}else if ((leitor == 'T') || (leitor == 't')){
			gerenciarContas();
			fflush(stdin);
			scanf("%c", &leitor);
			system("cls");
			if((leitor == 'S') || (leitor == 's')){
				break;                            // Finalisa o c�digo
			}else if((leitor == 'C') || (leitor == 'c')){
				if(contContas == 200){
					printf("Numero de CONTAS chegou ao limite!\n");
					system("pause");
				}else{
					cadastraConta();
				}
			}else if((leitor == 'R') || (leitor == 'r')){
				listarContas();
			}else if((leitor == 'L') || (leitor == 'l')){
				listarConta();
			}else if((leitor == 'D') || (leitor == 'd')){
				if(contTransacoes == 1000){
					printf("Numero de TRANSACOES chegou ao limite!\n");
					system("pause");
				}else{
					depositaConta();
				}
			}else if((leitor == 'W') || (leitor == 'w')){
				if(contTransacoes == 1000){
					printf("Numero de TRANSACOES chegou ao limite!\n");
					system("pause");
				}else{
					saqueConta();
				}
			}else if((leitor == 'T') || (leitor == 't')){
				if(contTransacoes == 1000){
					printf("Numero de TRANSACOES chegou ao limite!\n");
					system("pause");
				}else{
					transferenciaContas();
				}
			}else if((leitor == 'E') || (leitor == 'e')){
				extratoConta();
			}
		}
		contClientes = verificaClientes();
		contContas = verificaContas();
		contTransacoes = verificaTransacoes();

	}


}

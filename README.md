#include <stdio.h>
#include <string.h>
	
	

	
	
	
	void bem_Vindo(){ // Inicia o código
		printf("============== Bem Vindo! ===============\n");
		printf("Digite um comando a seguir para iniciar:\n");
		printf("C - Gerenciar Clientes\n");
		printf("T - Gerenciar Contas\n");
		printf("S - Sair\n");
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
	}
	
	void cadastraCliente(){
		FILE *leitura;
		char nome[50], endereco[100], codigo[20], cpf[20], telefone[15];
		int v = 0;
		char texto[100000];
		
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
		
		while(!feof(leitura)){
			fscanf(leitura, "%s", texto);
			if((strcmp(texto, cpf) == 0) || (strcmp(texto, codigo) == 0)){
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
		char texto[100000], ordem[100][80], aux[80];
		leitura = fopen("Clientes.txt", "r");
		
		while(fgets(texto, 100000, leitura) != NULL){
			if(i == 5){
				//printf("%s", texto);
				strcpy(ordem[cont], texto);
				cont++;
				i = 0;
			}
			
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
	

//-------------------------------------------------------------------------------------------------------------------------------------
int main(){
	char *leitor;
	int contClientes = 0, contContas = 0, contTransacoes = 0, i;
	FILE *arquivo;
	arquivo = fopen("Clientes.txt", "w");
	fclose(arquivo);
	 
	 
	for(i = 0; (contClientes < 100) || (contContas < 200) || (contTransacoes < 1000); i++){
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
			}
		}
		

	}


}

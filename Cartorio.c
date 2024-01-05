#include <stdio.h> // biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // bibliotecade aloca��o de texto por regi�o
#include <string.h> // bliblioteca respons�vel por cuidar das strings 

int registro () // Fun��o responsavel por cadastrar os usu�rios no sistema
{
	// inicio da cria��o de vari�veis/string 
	char arquivo[40];
	char cpf[40];	
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis/string 
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // resonsavel por copiar os valores das string
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w"); // criando o arquivo onde savamos o sistema 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); // a = inclui informa��o no aquivo ja criado / abre o arquivo para incluir
	fprintf(file,","); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");			
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,nome); 
	fclose(file); 
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o sobrenome a ser cadastrado: ");			
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome); 
	fclose(file); 

	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file); 
	
	printf("Digite o cargo a ser cadastrado: ");			
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,cargo); 
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,","); 
	fclose(file); 
	
	system("pause");		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); 
	
	// inicio da cria��o de vari�veis/string 
	char cpf[40];	
	char conteudo[200];
	// fim da cria��o de vari�veis/string 
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%S",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r = faz a leitura de arquivo j� criado
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, nao localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	 	printf("\nEssas s�o as informa�oes do usu�rio: ");
	 	printf("%s", conteudo);
		printf("\n\n");	 
	}
	 
	system("pause");
}


int deletar() // Fun��o de deletar
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
		
	FILE *file;
	file = fopen(cpf,"r"); 
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	if(file != NULL)
	{
		printf("Usu�rio deletado com sucesso!.\n");
		system("pause");
	}
}

int main()
{	//  Definindo vari�veis
	int opcao=0; 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	
		setlocale(LC_ALL, "Portuguese"); // Define que pode usar caracteres como acento // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");	
		//inicio do menu
		printf("Escolha a op��o desejada do menu: \n\n"); // \n: para pular linha
		printf("\t1 - Registrar nomes\n");		// \t : dar um espa�o tipo TAB
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); // Fim do menu
		//printf("Esse Software � de livre uso dos alunos\n");
	
		scanf("%d", &opcao); // amarzenando escolha do usu�rio
	
		system("cls"); // limpa tela
		
		switch(opcao)
		{
			case 1: 
			registro(); //chamada de func�es
			break;
			
			case 2:
			consulta(); //chamada de func�es
			break;	
			
			case 3:
			deletar(); //chamada de func�es
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistena!\n");
			return 0;
			break;
				
			default:	
			printf("Essa op��o nao est� disponivel!\n");
			system("pause");
			break;
		}
		
	}
}
 

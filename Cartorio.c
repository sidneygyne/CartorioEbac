#include <stdio.h> // biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // bibliotecade alocação de texto por região
#include <string.h> // bliblioteca responsável por cuidar das strings 

int registro () // Função responsavel por cadastrar os usuários no sistema
{
	// inicio da criação de variáveis/string 
	char arquivo[40];
	char cpf[40];	
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string 
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // resonsavel por copiar os valores das string
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w"); // criando o arquivo onde savamos o sistema 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); // a = inclui informação no aquivo ja criado / abre o arquivo para incluir
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
	
	// inicio da criação de variáveis/string 
	char cpf[40];	
	char conteudo[200];
	// fim da criação de variáveis/string 
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%S",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // r = faz a leitura de arquivo já criado
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, nao localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	 	printf("\nEssas são as informaçoes do usuário: ");
	 	printf("%s", conteudo);
		printf("\n\n");	 
	}
	 
	system("pause");
}


int deletar() // Função de deletar
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
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	if(file != NULL)
	{
		printf("Usuário deletado com sucesso!.\n");
		system("pause");
	}
}

int main()
{	//  Definindo variáveis
	int opcao=0; 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
	
		setlocale(LC_ALL, "Portuguese"); // Define que pode usar caracteres como acento // Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");	
		//inicio do menu
		printf("Escolha a opção desejada do menu: \n\n"); // \n: para pular linha
		printf("\t1 - Registrar nomes\n");		// \t : dar um espaço tipo TAB
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); // Fim do menu
		//printf("Esse Software é de livre uso dos alunos\n");
	
		scanf("%d", &opcao); // amarzenando escolha do usuário
	
		system("cls"); // limpa tela
		
		switch(opcao)
		{
			case 1: 
			registro(); //chamada de funcões
			break;
			
			case 2:
			consulta(); //chamada de funcões
			break;	
			
			case 3:
			deletar(); //chamada de funcões
			break;
			
			case 4:
			printf("Obrigado por ultilizar o sistena!\n");
			return 0;
			break;
				
			default:	
			printf("Essa opção nao está disponivel!\n");
			system("pause");
			break;
		}
		
	}
}
 

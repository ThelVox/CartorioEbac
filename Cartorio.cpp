#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>  // blibioteca de aloca��es de texto por regi�o
#include <string.h>  // blibioteca respons�vel por cuidar das string

int registro()// fun�ao respons�vel por cadastrar usu�rios no sistema
{
    setlocale(LC_ALL,"portuguese");// Definindo a linguagem
    
    //inicio cria��o de vari�vies/strings
	char arquivo[40];//characters Char
	char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�vies/strings
	
	printf("Digite o CPF a ser cadastrado: ");//fornece a op�ao de digita��o ao usus�rio
	scanf("%s", cpf); //%s refere se a String "salvar a string"
	
	strcpy(arquivo,cpf); //respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo o "w" write = escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a");//atualiza o arquivo
	fprintf(file,",");//acrescenta virgula ao arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
					
//  printf("Voc� escolheu o registro de nomes!\n");
//  system("pause");	
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");// Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE*file;
	file = fopen(cpf,"r");// (r) read para ler o arquivo
	
	if(file==NULL)// cria uma condicional do tipo se para erro de info n�o encontrada
    {
	    printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
    }
	
	while(fgets(conteudo,200,file)!=NULL)// cira um la�o para obter conteudo do arquivo com o alcance de 200
	{
		printf("Essas s�o as informa��es do usu�rio: "); //info textuais
		printf("%s", conteudo);// info do arquivo salvo correspondente a digita��o
		printf("\n\n");// espa�o
	}
	system("pause");
	
//	printf("Voc� escolheu consultar de nomes!\n");
//  system("pause");
}

int deletar() 
{
	setlocale(LC_ALL,"portuguese");// Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r");//trazendo a info para validar delete ou NUll
	
	if(file == NULL)//condicional para se arquivo N�o encontrado trazer texto do PrintF
	{
		fclose(file);
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else if (file !=NULL)//se arquivo for encontrado traga a msg do printf e remova o cpf indicado
	{
		fclose(file);//fun��o fecha o arquivo
		printf("Registro apagado com sucesso!.\n");
		system("pause");
		remove(cpf);//Fun��o remove o cadastro
	}
	
//	printf("Voc� escolheu deletar nomes!\n");
//	system("pause");
} 

int main()
    {  
	int opcao = 0; //Definindo a vari�veis
	int laco = 1;
	
	for(laco=1;laco=1;)
	{ 
		system("cls");//respons�vel por limpar "cls" clean
		
    	setlocale(LC_ALL,"portuguese");// Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n");// Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes:\n");
	    printf("\t2 - Consultar os nomes:\n");
	    printf("\t3 - Deletar os nomes:\n\n");
	    printf("Op��o: "); // fim do menu
	
	    scanf("%d",&opcao); //armazenadno as escolhas do usu�rio
	
    	system("cls");//respons�vel por limpar "cls" clean
    	
    	switch(opcao)//inicio da sele��o do menu
    	{
    		case 1:
    		registro();//chamaada de fun��es
		    break;
		    
		    case 2:
		    consulta();//chamaada de fun��es	
		    break;
			
			case 3:
			deletar();//chamaada de fun��es
			break;
			
			default:
			printf("Voc� escolheu op��o n�o disponivel!\n");//exibe texto se as condi��es n�o for encontrada 
		    system("pause");
			break;	
		}     // fim da sele��o		
			//printf("Esse software � de livre uso dos alunos\n");
        }
}

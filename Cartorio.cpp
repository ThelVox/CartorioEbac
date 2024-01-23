#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h>  // blibioteca de alocações de texto por região
#include <string.h>  // blibioteca responsável por cuidar das string

int registro()// funçao responsável por cadastrar usuários no sistema
{
    setlocale(LC_ALL,"portuguese");// Definindo a linguagem
    
    //inicio criação de variávies/strings
	char arquivo[40];//characters Char
	char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variávies/strings
	
	printf("Digite o CPF a ser cadastrado: ");//fornece a opçao de digitação ao ususário
	scanf("%s", cpf); //%s refere se a String "salvar a string"
	
	strcpy(arquivo,cpf); //responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo o "w" write = escrever
	fprintf(file, cpf); //salva o valor da variável
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
					
//  printf("Você escolheu o registro de nomes!\n");
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
	
	if(file==NULL)// cria uma condicional do tipo se para erro de info não encontrada
    {
	    printf("Não foi possível abrir o arquivo, não localizado!.\n");
    }
	
	while(fgets(conteudo,200,file)!=NULL)// cira um laço para obter conteudo do arquivo com o alcance de 200
	{
		printf("Essas são as informações do usuário: "); //info textuais
		printf("%s", conteudo);// info do arquivo salvo correspondente a digitação
		printf("\n\n");// espaço
	}
	system("pause");
	
//	printf("Você escolheu consultar de nomes!\n");
//  system("pause");
}

int deletar() 
{
	setlocale(LC_ALL,"portuguese");// Definindo a linguagem
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r");//trazendo a info para validar delete ou NUll
	
	if(file == NULL)//condicional para se arquivo Não encontrado trazer texto do PrintF
	{
		fclose(file);
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	else if (file !=NULL)//se arquivo for encontrado traga a msg do printf e remova o cpf indicado
	{
		fclose(file);//função fecha o arquivo
		printf("Registro apagado com sucesso!.\n");
		system("pause");
		remove(cpf);//Função remove o cadastro
	}
	
//	printf("Você escolheu deletar nomes!\n");
//	system("pause");
} 

int main()
    {  
	int opcao = 0; //Definindo a variáveis
	int laco = 1;
	
	for(laco=1;laco=1;)
	{ 
		system("cls");//responsável por limpar "cls" clean
		
    	setlocale(LC_ALL,"portuguese");// Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n");// Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes:\n");
	    printf("\t2 - Consultar os nomes:\n");
	    printf("\t3 - Deletar os nomes:\n\n");
	    printf("Opção: "); // fim do menu
	
	    scanf("%d",&opcao); //armazenadno as escolhas do usuário
	
    	system("cls");//responsável por limpar "cls" clean
    	
    	switch(opcao)//inicio da seleção do menu
    	{
    		case 1:
    		registro();//chamaada de funções
		    break;
		    
		    case 2:
		    consulta();//chamaada de funções	
		    break;
			
			case 3:
			deletar();//chamaada de funções
			break;
			
			default:
			printf("Você escolheu opção não disponivel!\n");//exibe texto se as condições não for encontrada 
		    system("pause");
			break;	
		}     // fim da seleção		
			//printf("Esse software é de livre uso dos alunos\n");
        }
}

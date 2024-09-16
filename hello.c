#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // BIBLIOTECA RESONSAVEL POR CUIDADAR DAS STRING


int registro ()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf); //responsavel por copiar os valores da string

    FILE *file;// cria o arquivo
    file = fopen(arquivo, "w");// "w" write on the file
    fprintf(file,cpf);// valor salvo na variavel nesse caso o cpf
    fclose(file);// fecha o arquivo

    file = fopen(arquivo, "a");// "a" atualizar o arquivo
    fprintf(file,", \nNome: "); // pra colocar um virgula la dentro
    fclose(file);

    printf("Digite O Nome A Ser cadastrado: ");
    scanf("%s", nome);

    file =fopen(arquivo, "a");
    fprintf (file, nome);
    fclose (file);

    file = fopen(arquivo, "a");
    fprintf(file,", \nSobrenome: ");
    fclose(file);

    printf("Digite o Sobrenome A ser Cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose (file);

    file = fopen(arquivo, "a");
    fprintf(file,", \nCargo: ");
    fclose(file);

    printf("Digite o cargo do cliente: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file ,cargo);
    fclose(file);

    system("read");

}

int consulta ()
{
    setlocale (LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[40];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file; // abre os arquivos
    file =fopen(cpf,"r");// "r" para read as info

    if(file == NULL)
{
    printf("Não foi possivel abrir arquivo, não localizado!\n");
}
    printf("\nEssas são as informações do usuário:\n ");
    while(fgets(conteudo,200,file)!= NULL)
{

    printf("%s",conteudo);
    printf("\n\n");
}


    system("read");
}

int deletar ()
{
    char cpf[40];
    printf("Digite o Cpf a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");//"R" for read

    if (file == NULL)
    {
        printf("Não foram encontradas informaçoes Sistema! \n");
        system("read");
    }


}


int main ()
{

    int opcao=0;//Definindo variaveis

    int looping=1;
    for(looping=1;looping==1;)//repeticao looping
    {
    system("clear");
    setlocale (LC_ALL, "Portuguese"); //Lingua que Estamos usando no Code
    printf ("*_* Cartório da EBAC *_*\n\n");//inicio do menu
    printf ("Escolha a opção desejada do menu\n\n");
    printf ("\t1 - Registrar Nomes\n");
    printf ("\t2 - Consultar Nomes\n");
    printf ("\t3 - Deletar Nomes\n\n");
    printf ("\t4 - sair do sistema\n\n");
    printf("Opção: ");//fim do menu

        scanf("%d" , &opcao );// escolha do usuario
        system("clear");

        switch (opcao)
        {
        case 1:
        registro ();
        break;

        case 2:
        consulta ();
        break;

        case 3:
        deletar ();
        break;

        case 4:
        printf("Obrigado por utilizar esse sistema!\n");
        return 0;
        break;


        default:
        printf("Essa opcão não está Disponivel\n\n");
        system("read");
        }

     }
}

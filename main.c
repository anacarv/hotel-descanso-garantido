#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int cadastroFuncionario(void);
int codigoFuncionario();
int nomeFuncionario();
int telefoneFuncionario();
int cargoFuncionario();
int salarioFuncionario();

int main()
{
    cadastroFuncionario ();
    return 0;
}

int cadastroFuncionario(void)
{
    setlocale(LC_ALL,"portuguese");
    codigoFuncionario();
    nomeFuncionario();
    telefoneFuncionario();
    cargoFuncionario();
    salarioFuncionario();
}
int codigoFuncionario()
{
    int codigoFuncionario=0;
    codigoFuncionario++;
    printf("\nCÓDIGO %i\n",codigoFuncionario);
    return (codigoFuncionario);
}
int nomeFuncionario()
{
    int x=0;
    char nomeFuncionario[101];
    printf("\nCADASTRO DE NOME\n");
    printf("\nFuncionário:\n");
    fflush(stdin);
    gets(nomeFuncionario);

    //O nome deve ser uma letra do alfabeto ou um caractere espaço, enquanto ele não for assim, não é possível prosseguir

    for(x=0; x<strlen(nomeFuncionario); x++)
    {
        while(!((nomeFuncionario[x]>='a' && nomeFuncionario[x]<='z') || (nomeFuncionario[x]>='A' && nomeFuncionario[x]<='Z') || (nomeFuncionario[x]==' ')))
        {
            printf("\nPor favor insira um nome válido.\n");
            printf("\nFuncionário:\n");
            fflush(stdin);
            gets(nomeFuncionario);
        }
    }
    printf("O nome %s foi cadastrado com sucesso!\n",nomeFuncionario);
    return nomeFuncionario;
}

int telefoneFuncionario()
{
    int celularFuncionario=0, fixoFuncionario=0, dddFuncionarioCelular=0, dddFuncionarioFixo=0, numInteiro=0;
    printf("\nCADASTRO DE CONTATO\n");
    //Telefone fixo
    printf("\nTelefone Fixo\n");
    do
    {
        printf("DDD \t");
        scanf("%d",&dddFuncionarioFixo);
    }
    while(dddFuncionarioFixo>100 || dddFuncionarioFixo<=10);
    do
    {
        printf("Número de telefone fixo: \t");
        scanf("%d",&fixoFuncionario);
    }
    while(fixoFuncionario<10000000 || fixoFuncionario>99999999);
    //Telefone celular
    printf("Celular\n");
    do
    {
        printf("DDD \t");
        scanf("%d",&dddFuncionarioCelular);
    }
    while(dddFuncionarioCelular>100 || dddFuncionarioCelular<=10);
    do
    {
        printf("Número: \t");
        scanf("%d",&celularFuncionario);
        //ver se o primeiro dígito é 9
        numInteiro=celularFuncionario/100000000;
    }
    while(celularFuncionario<100000000 || celularFuncionario>999999999 || numInteiro!=9);
    printf("O telefone fixo %i-%i, e o telefone celular %i-%i foram cadastrados com sucesso!\n",dddFuncionarioFixo,fixoFuncionario,dddFuncionarioCelular,celularFuncionario);

    return(dddFuncionarioFixo,fixoFuncionario,dddFuncionarioCelular,celularFuncionario);
}
int cargoFuncionario()
{
    char tipoCargo[20];
    printf("\nCADASTRO DE CARGO\n");
    printf("\nQual o cargo do funcionário?\nRecepcionista\nAuxiliar de limpeza\nGarçom\nGerente\n");
    fflush(stdin);
    gets(tipoCargo);

    return(tipoCargo);
}
int salarioFuncionario()
{

}

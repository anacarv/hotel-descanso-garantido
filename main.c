#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int cadastroClientes(void);
int codigoCliente();
int nomeCliente();
int enderecoCliente();
int telefoneCliente();

int main()
{
    cadastroClientes ();
    return 0;
}

int cadastroClientes(void)
{
    setlocale(LC_ALL,"portuguese");
    codigoCliente();
    nomeCliente();
    enderecoCliente();
    telefoneCliente();
}
int codigoCliente()
{
    int codigoCliente=0;
    codigoCliente++;
    printf("\nCÓDIGO %i\n",codigoCliente);
    return (codigoCliente);
}
int nomeCliente()
{
    int x=0;
    char nomeCliente[101];
    printf("\nCADASTRO DE NOME\n");
    printf("\nCliente:\n");
    fflush(stdin);
    gets(nomeCliente);

    //O nome deve ser uma letra do alfabeto ou um caractere espaço, enquanto ele não for assim, não é possível prosseguir

    for(x=0; x<strlen(nomeCliente); x++)
    {
        while(!((nomeCliente[x]>='a' && nomeCliente[x]<='z') || (nomeCliente[x]>='A' && nomeCliente[x]<='Z') || (nomeCliente[x]==' ')))
        {
            printf("\nPor favor insira um nome válido.\n");
            printf("\nCliente:\n");
            fflush(stdin);
            gets(nomeCliente);
        }
    }
    printf("O nome %s foi cadastrado com sucesso!\n",nomeCliente);
    return nomeCliente;
}
int enderecoCliente()
{
    int numeroEndereco=0, apartamentoEndereco=0, tipoDeEndereco=0;
    char bairroEndereco[36], ruaEndereco[51];
    printf("\nCADASTRO DE ENDEREÇO\n");

    //Apartamento ou casa
    printf("\n1- Apartamento\n2-Casa\n");
    scanf("%d",&tipoDeEndereco);
    //Apartamento
    if(tipoDeEndereco==1)
    {
        //Rua do cliente
        printf("Rua\t");
        fflush(stdin);
        gets(ruaEndereco);
        //Bairro do cliente
        printf("Bairro\t");
        fflush(stdin);
        gets(bairroEndereco);
        //Número do endereço do cliente
        printf("Número\t");
        scanf("%d",&numeroEndereco);
        //Número do apartamento
        printf("Número do apartamento\t");
        scanf("%d",&apartamentoEndereco);
        printf("O endereço rua %s, número %i, apto %i, no bairro %s, foi cadastrado com sucesso!\n",ruaEndereco,numeroEndereco,apartamentoEndereco,bairroEndereco);
        return(ruaEndereco,numeroEndereco,apartamentoEndereco,bairroEndereco);
    }
    else
    {
        //Casa
        if(tipoDeEndereco==2)
        {
            //Rua do cliente
            printf("Rua\t");
            fflush(stdin);
            gets(ruaEndereco);
            //Bairro do cliente
            printf("Bairro\t");
            fflush(stdin);
            gets(bairroEndereco);
            //Número do endereço do cliente
            printf("Número\t");
            scanf("%d",&numeroEndereco);
            printf("O endereço rua %s, número %i, no bairro %s, foi cadastrado com sucesso!\n",ruaEndereco,numeroEndereco,bairroEndereco);
            return(ruaEndereco,numeroEndereco,bairroEndereco);
        }
        //Entrada incorreta
        else
        {
            printf("Por favor insire um número válido (1 ou 2)\n");
        }
    }
}
int telefoneCliente()
{
    int celularCliente=0, fixoCliente=0, dddClienteCelular=0, dddClienteFixo=0, numInteiro=0;
    printf("\nCADASTRO DE CONTATO\n");
    //Telefone fixo
    printf("\nTelefone Fixo\n");
    do
    {
        printf("DDD \t");
        scanf("%d",&dddClienteFixo);
    }
    while(dddClienteFixo>100 || dddClienteFixo<=10);
    do
    {
        printf("Número de telefone fixo: \t");
        scanf("%d",&fixoCliente);
    }
    while(fixoCliente<10000000 || fixoCliente>99999999);
    //Telefone celular
    printf("Celular\n");
    do
    {
        printf("DDD \t");
        scanf("%d",&dddClienteCelular);
    }
    while(dddClienteCelular>100 || dddClienteCelular<=10);
    do
    {
        printf("Número: \t");
        scanf("%d",&celularCliente);
        //ver se o primeiro dígito é 9
        numInteiro=celularCliente/100000000;
    }
    while(celularCliente<100000000 || celularCliente>999999999 || numInteiro!=9);
    printf("O telefone fixo %i-%i, e o telefone celular %i-%i foram cadastrados com sucesso!\n",dddClienteFixo,fixoCliente,dddClienteCelular,celularCliente);
    return(dddClienteFixo,fixoCliente,dddClienteCelular,celularCliente);
}








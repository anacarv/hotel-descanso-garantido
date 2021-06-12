#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 
ESTADIA= 
    código da estadia,
    data de entrada, 
    data de saída, 
    quantidade de diárias, 
    código do cliente, 
    número do quarto
*/


int main(){
    char nomeCliente[50],entrada[11],saida[11];
    int hospedes,confirmarDados,loopData=0;
    printf("CADASTRO DE ESTADIA\n\n");
    printf("Por favor, digite o nome do cliente que deseja se hospedar:");
    scanf("%s",&nomeCliente);
    printf("Quantidade de hóspedes:");
    scanf("%d",&hospedes);
    while(loopData == 0){
        printf("Data de entrada: (dd/mm/aaaa)\n");
        scanf("%s",&entrada);
        loopData = verificaFormatoData(entrada);
        printf("Data de saída: (dd/mm/aaaa)\n");
        scanf("%s",&saida);
        loopData = verificaFormatoData(saida);
    }
    
    printf("Por favor, confirme os dados do cliente!\n\n");
    printf("Cliente => %s\nN° de hóspedes => %d\n",nomeCliente,hospedes);
    printf("Data de Entrada => %s\nData de Saída => %s\n",entrada,saida);
    return 0;
}

int verificaFormatoData(char data[11]){
    printf("%s",data);
    //Verificar se a data possui mais de 11 caracteres
    if(strlen(data) != 10){
        printf("Data inválida,deve possuir 10 carateres e seguir o formato (dd/mm/aaaa)\n");
        return 0;

    }

    //Verificar se existe as barras no formato de data
    // Barras = data[2] && data[5] 


    for(int i = 0; i < strlen(data); i++){
        if (data[2] != '/' || data[5] != '/'){
            printf("Data inválida,deve conter o caractere '/' como formato\n",data);
            return 0;
        }

        if(data[i] <= '0' && data[i] >= '9'){
            printf("Data inválida,deve possuir somente números\n",data);
            return 0;
        }

    }

    return 1;

    
}
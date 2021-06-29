#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


int cadastroEstadia();
int diarias();
int verificaFormatoData(char []);


struct TEstadia{
  int codigo;
  char entrada[11],saida[11];
  int hospedes,numeroDoQuarto;
};

typedef struct TEstadia estadia;

int hospedes;
char entrada[11],saida[11];


int main(){
    setlocale(LC_ALL, "portuguese");
    cadastroEstadia();
    diarias();
}

int cadastroEstadia(){
    char nomeCliente[50];
    int confirmarDados=0,loopData=0;
    while(confirmarDados == 0){
        printf("CADASTRO DE ESTADIA\n\n");
        printf("Por favor, digite o nome do cliente que deseja se hospedar:");
        scanf("%s",&nomeCliente);
        printf("Quantidade de hóspedes:");
        scanf("%d",&hospedes);
        while(loopData == 0){
            printf("Data de entrada: (dd/mm/aaaa)\n");
            scanf("%s",&entrada);
            loopData = verificaFormatoData(entrada);
            if(loopData == 0) continue;
            printf("Data de saída: (dd/mm/aaaa)\n");
            scanf("%s",&saida);
            loopData = verificaFormatoData(saida);
        }
        
        printf("Por favor, confirme os dados do cliente!\n\n");
        printf("Cliente => %s\nN° de hóspedes => %d\n",nomeCliente,hospedes);
        printf("Data de Entrada => %s\nData de Saída => %s\n",entrada,saida);
        while(confirmarDados != 1 && confirmarDados != 2){
            printf("\nOs dados estão corretos?\n");
            printf("[1]Sim\n[2]Não\n");
            scanf("%d",&confirmarDados);
            if(confirmarDados == 1)
                break;
            else if(confirmarDados == 2){
                confirmarDados = 0;
                loopData = 0;
                break;
            }
            else 
                printf("\nPor favor insira um número válido\n\n");
        }

    }

    return 0;
}


int verificaFormatoData(char data[11]){
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

int diarias(){
    char anoEntrada[5],mesEntrada[5],diaEntrada[5];
    char anoSaida[5],mesSaida[5],diaSaida[5];

    int anoTotal,mesTotal,diaTotal,totalDiarias;

    for(int i = 0;i < strlen(entrada);i++){
        switch(i){
          case 0:
            diaEntrada[0] = entrada[i];
            diaSaida[0] = saida[i];
            break;
          case 1:
            diaEntrada[1] = entrada[i];
            diaSaida[1] = saida[i];
            break;
          case 3:
            mesEntrada[0] = entrada[i];
            mesSaida[0] = saida[i];
            break;
          case 4:
            mesEntrada[1] = entrada[i];
            mesSaida[1] = saida[i];
            break;
          case 6:
            anoEntrada[0] = entrada[i];
            anoSaida[0] = saida[i];
            break; 
          case 7: 
            anoEntrada[1] = entrada[i];
            anoSaida[1] = saida[i];
            break;
          case 8:
            anoEntrada[2] = entrada[i];
            anoSaida[2] = saida[i];
            break;
          case 9: 
            anoEntrada[3] = entrada[i];
            anoSaida[3] = saida[i];
            break;
          default:
            break;
        }
    }

    mesEntrada[2] = '\0';
    mesSaida[2] = '\0';
    anoEntrada[4] = '\0';
    anoSaida[4] = '\0';

    // printf("Dia De entrada => %s\nDia de saída => %s\nMês E => %s\nMês Saída =>%s\nAno E => %s\nAnoS => %s",
        // diaEntrada,diaSaida,mesEntrada,mesSaida,anoEntrada,anoSaida
    // );

    anoTotal = (atoi(anoSaida) - atoi(anoEntrada));
    mesTotal = atoi(mesSaida) - atoi(mesEntrada);
    diaTotal = atoi(diaSaida) - atoi(diaEntrada);


    printf("%d",anoTotal);
}


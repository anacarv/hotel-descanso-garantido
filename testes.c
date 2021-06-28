#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int cadastroEstadia();
int diarias();
int verificaFormatoData(char[]);
int quartos(char[], char[]);

typedef struct {
  int numero, hospedes, status;
  float valorDiaria;

} Tquarto;

typedef struct {
  int codigo, totalDiarias, hospedes;
  char entrada[11], saida[11];
  char nomeCliente[50];
} Testadia;

Testadia estadia;

int main(){
  setlocale(LC_ALL, "portuguese");
  cadastroEstadia();
}

int cadastroEstadia(){
  int confirmarDados = 0, loopData = 0;
  while (confirmarDados == 0){

    printf("CADASTRO DE ESTADIA\n\n");
    printf("Por favor, digite o nome do cliente que deseja se hospedar:");
    scanf("%s", &estadia.nomeCliente);
    printf("Quantidade de hóspedes:");
    scanf("%d", &estadia.hospedes);

    while (loopData == 0){

      printf("Data de entrada: (dd/mm/aaaa)\n");
      scanf("%s", &estadia.entrada);
      loopData = verificaFormatoData(estadia.entrada);
      if (loopData == 0)
        continue;
      printf("Data de saída: (dd/mm/aaaa)\n");
      scanf("%s", &estadia.saida);
      loopData = verificaFormatoData(estadia.saida);

    }

    printf("Por favor, confirme os dados do cliente!\n\n");
    printf("Cliente => %s\nN° de hóspedes => %d\n", estadia.nomeCliente, estadia.hospedes);
    printf("Data de Entrada => %s\nData de Saída => %s\n", estadia.entrada, estadia.saida);

    while (confirmarDados != 1 && confirmarDados != 2){

      printf("\nOs dados estão corretos?\n");
      printf("[1]Sim\n[2]Não\n");
      scanf("%d", &confirmarDados);
      if (confirmarDados == 1)
        break;
      else if (confirmarDados == 2)
      {
        confirmarDados = 0;
        loopData = 0;
        break;
      }
      else
        printf("\nPor favor insira um número válido\n\n");

    }

    estadia.totalDiarias = diarias();
    quartos(estadia.entrada, estadia.saida);


  }

  return 0;
}

int quartos(char entrada[11], char saida[11]){
  FILE *quartosFile;
  if(quartosFile = fopen("quartos.txt","r") == NULL)
    printf("Erro na abertura do arquivo\n");
  else{
    
  }
}

int localizaQuartos(FILE *quartosFile,char entrada[11],char saida[11]){
  int posicao=-1, achou =0;
  fseek(quartosFile,0,SEEK_SET);
  fread(&estadia,sizeof(estadia),1,quartosFile);
  while(!feof(quartosFile) && !achou){
    posicao++;  
  }
}



int verificaFormatoData(char data[11])
{
  //Verificar se a data possui mais de 11 caracteres
  if (strlen(data) != 10)
  {
    printf("Data inválida,deve possuir 10 carateres e seguir o formato (dd/mm/aaaa)\n");
    return 0;
  }

  //Verificar se existe as barras no formato de data
  // Barras = data[2] && data[5]

  for (int i = 0; i < strlen(data); i++)
  {
    if (data[2] != '/' || data[5] != '/')
    {
      printf("Data inválida,deve conter o caractere '/' como formato\n", data);
      return 0;
    }

    if (data[i] <= '0' && data[i] >= '9')
    {
      printf("Data inválida,deve possuir somente números\n", data);
      return 0;
    }
  }
  return 1;
}

int diarias()
{
  char anoEntrada[5], mesEntrada[5], diaEntrada[5];
  char anoSaida[5], mesSaida[5], diaSaida[5];

  int anoTotal, mesTotal, diaTotal, totalDiarias;

  for (int i = 0; i < strlen(estadia.entrada); i++)
  {
    switch (i)
    {
    case 0:
      diaEntrada[0] = estadia.entrada[i];
      diaSaida[0] = estadia.saida[i];
      break;
    case 1:
      diaEntrada[1] = estadia.entrada[i];
      diaSaida[1] = estadia.saida[i];
      break;
    case 3:
      mesEntrada[0] = estadia.entrada[i];
      mesSaida[0] = estadia.saida[i];
      break;
    case 4:
      mesEntrada[1] = estadia.entrada[i];
      mesSaida[1] = estadia.saida[i];
      break;
    case 6:
      anoEntrada[0] = estadia.entrada[i];
      anoSaida[0] = estadia.saida[i];
      break;
    case 7:
      anoEntrada[1] = estadia.entrada[i];
      anoSaida[1] = estadia.saida[i];
      break;
    case 8:
      anoEntrada[2] = estadia.entrada[i];
      anoSaida[2] = estadia.saida[i];
      break;
    case 9:
      anoEntrada[3] = estadia.entrada[i];
      anoSaida[3] = estadia.saida[i];
      break;
    default:
      break;
    }
  }

  mesEntrada[2] = '\0';
  mesSaida[2] = '\0';
  anoEntrada[4] = '\0';
  anoSaida[4] = '\0';

  anoTotal = (atoi(anoSaida) - atoi(anoEntrada)) * 365;
  mesTotal = (atoi(mesSaida) - atoi(mesEntrada)) * 30;
  diaTotal = atoi(diaSaida) - atoi(diaEntrada);

  totalDiarias = diaTotal + anoTotal + mesTotal;

  return totalDiarias;
}



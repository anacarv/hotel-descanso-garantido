#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
  int numero, hospedes, status;
  float valorDiaria;

} Tquarto;

Tquarto quarto;

int cadastraQuarto();
int cadastraDadosQuarto(FILE *);


int main(){
    cadastraQuarto();
}

int cadastraQuarto(){

    FILE *fp;

    if((fp = fopen("quartos.txt","r+b")) == NULL){
        printf("Arquivo não existe...\n");
    }
    if((fp = fopen("quartos.txt","a+b")) == NULL){
        printf("Erro na criação do arquivo...\n");
    }

    cadastraDadosQuarto(fp);

    fclose(fp);

}


int cadastraDadosQuarto(FILE *fp){
    int confirmarDados=0, loopData=0;

    fseek(fp,0,SEEK_SET);
    fread(&quarto,sizeof(quarto),1,fp);

    quarto.numero = contaQuartos(fp);
    quarto.status = 1;

    while(confirmarDados == 0){
        printf("Digite o número de hóspedes para o quarto:");
        scanf("%d",&quarto.hospedes);
        printf("Digite o valor da diária do quarto:");
        scanf("%f",&quarto.valorDiaria);
        
        printf("Por favor, confirme os dados do quarto!\n\n");
        printf("Número do Quarto => %d\nN° de hóspedes => %d\n",quarto.numero,quarto.hospedes);
        printf("Valor da diária do quarto => %.2f\n",quarto.valorDiaria);
        printf("Status do quarto => %s\n",quarto.status == 1 ? "Disponível" : "Indisponível");

        while(confirmarDados != 1 && confirmarDados != 2){
            printf("\nOs dados estão corretos?\n");
            printf("[1]Sim\n[2]Não\n");
            scanf("%d",&confirmarDados);
            if(confirmarDados == 1)
                break;
            else if(confirmarDados == 2){
                confirmarDados = 0;
                break;
            }
            else 
                printf("\nPor favor insira um número válido\n\n");
        }
    }

    fseek(fp,0,SEEK_END);
    fwrite(&quarto,sizeof(quarto),1,fp);
}


int contaQuartos(FILE *fp){
    int i = 1;
    while(!feof(fp)){
        fread(&quarto,sizeof(quarto),1,fp);
        i++;
    }
}


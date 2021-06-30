#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "quarto.h"
#include "estadia.h"

int main(){
    setlocale(LC_ALL, "portuguese");
    int escolha = 0;
    while(escolha == 0){
        limparTerminal();
        printf("*** HOTEL DESCANSO GARANTIDO ***\n\n");
        printf("[1] Cadastrar Cliente\n[2] Cadastrar Funcionário\n[3] Cadastrar Estadia\n[4] Cadastrar Quarto\n\n> ");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                //cadastrar cliente
                break;
            case 2:
                //cadastrar funcionário
                break;
            case 3:
                cadastroEstadia();
                break;
            case 4:
                cadastraQuarto();
                break;
            default:
                printf("\n\nNúmero inválido. Por favor, insira um número entre 1 e 4.\n");
                escolha = 0;
                break;
        }

        escolha = continuar();   
    }
    return 0;
}

void limparTerminal(){
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int continuar(){
    int escolha,loop = 0;
    while(loop == 0){
        printf("\n\nDeseja continuar?\n");
        printf("[1] Sim\n[2] Não\n\n> ");
        scanf("%d",&escolha);
        if(escolha == 1){
            escolha = 0;
            loop = 1;
            break;
        }
        else if(escolha == 2){
            escolha = 1;
            loop = 1;
            break;
        }
        else
            printf("Número inválido. Por favor, insira um número entre 1 e 2.\n");
            loop = 0;
    }
    return escolha;
}
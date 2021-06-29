#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#include "quarto.h"
#include "estadia.h"

int main(){
    setlocale(LC_ALL, "portuguese");
    limparTerminal();
    int escolha = 0;
    while(escolha == 0){
        printf("***HOTEL DESCANSO GARANTIDO***\n\n");
        printf("[1] Cadastrar Cliente\n[2] Cadastrar Funcionário\n[3] Cadastrar Estadia\n[4] Cadastrar Quarto\n\n>");
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
                printf("Número inválido. Por favor, insira um número entre 1 e 4.\n");
                break;
        }
    }
    
}

void limparTerminal(){
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
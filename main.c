//
// TP Programação - Jogo do Semáforo - Realizado por Nuno Gabriel Tavares Honório a2019126457
//
#include <stdio.h>
#include "jogo.h"
#include "utils.h"

void menu(int escolha){
    switch (escolha){
        case 1:
            printf("1 - Iniciar jogo\n");
            printf("2 - Regras\n");
            printf("3 - Sair\n");
            printf("Opcao: ");
            break;
        default:
            break;
    }
}

int main() {
    int escolha=1, sair=1;
    char comando;
    initRandom();
    printf("=== TP de Programação ISEC 20-21 ===\n");
    printf("=== Jogo do Semáforo ===\n");
    do{
        menu(escolha);
        scanf("%c", &comando);
        while (getchar() != '\n');
        switch(comando) {
            case '1':
                printf("Vou iniciar o jogo...\n");
                sair=jogo();
                break;
            case '2':
                printf("=== Alternadamente os jogadores vão colocando peças de cor Verde (G), Amarela (Y) ou Vermelha (R) ===\n");
                printf("=== Ganha o jogador que coloque uma peça que permita formar uma linha, coluna ou diagonal completa com peças da mesma cor ===\n");
                break;
            case '3':
                return 0;
            default:
                printf("Comando invalido!\n");
        }
    }while(sair!=0);
}


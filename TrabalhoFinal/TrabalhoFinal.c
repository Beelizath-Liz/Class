#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define True 1

int menu();

int main(){
    while(True){ // Loop infinito para exibir o menu até que o usuário escolha sair
        int menuResult;
        menuResult = menu();
        printf("\nOpcao selecionada: %d\n", menuResult); // Exibe a opção selecionada pelo usuário, APAGAR

        if(menuResult == 4){ //jogador seleciona a opção de sair do programa
            printf("Saindo do programa...\n");
            break;
        }

    }
    printf("\nPrograma encerrado.\n");
    return 0;
}

int menu(){
    int opcao;
    printf("\n\t!!Bem vindo!!\n\n");
    printf("Selecione:\n");
    printf("1-Iniciar jogo\t\t2-Sobre o jogo\n3-Sobre a criadora\t4-Sair\n\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

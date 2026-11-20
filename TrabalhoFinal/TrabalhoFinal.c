#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define True 1

int menu();
void sobreJogo();
void sobreCriadora();

int main(){
    while(True){ // Loop infinito para exibir o menu até que o usuário escolha sair
        int menuResult;
        menuResult = menu();
        printf("\nOpcao selecionada: %d\n", menuResult); // Exibe a opção selecionada pelo usuário, APAGAR

        switch(menuResult) {
            case 1:
                // Lógica para iniciar o jogo
                break;
            case 2:
                sobreJogo();
                continue;
            case 3:
                sobreCriadora();
                continue;
            case 4:
                printf("\n\nSaindo do programa...\n"); //Unica forma correta de sair do jogo, indo pro menu
                return 0;
            default:
                printf("Opção inválida!\n");
                continue;
        }

    }
}

int menu(){
    int opcao;
    printf("\t!!Bem vindo!!\n\n");
    printf("Selecione:\n");
    printf("1-Iniciar jogo\t\t2-Sobre o jogo\n3-Sobre a criadora\t4-Sair\n\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

void sobreJogo(){
    printf("\n\t!!Sobre o jogo!!\n\n");
    printf("Boa sorte!\n\n");
}

void sobreCriadora(){
    printf("\n\t!!Sobre a criadora!!\n\n");
    printf("Meu nome e Elizabeth Ferreira, tenho 19 anos e sou estudante de Ciencia da Computacao na UFOP.\n");
    printf("Este jogo foi desenvolvido como parte do meu Trabalho Final da disciplina de introducao a programacao.\n");
}

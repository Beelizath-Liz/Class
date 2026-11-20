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

        switch(menuResult) { //Switch da seleção do menu;
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

        printf("Teste para ver se o jogo inicia corretamente\n"); //Teste testar a opção 1 do menu, APAGAR

        while(True){ //Loop infinito para o jogo, até que o usuário vença ou saia do jogo
            int opcaoJogo;
            printf("\nDigite 1 para jogar ou 2 para sair: "); //Menu subistituto para jogo, APAGAR
            scanf("%d", &opcaoJogo);
            if(opcaoJogo == 1){
                printf("Iniciando o jogo...\n");
                // Lógica do jogo aqui
            } else {
                printf("Saindo do jogo...\n");
                break; // Sai do loop do jogo e volta para o menu
            }
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
    printf("O jogo consiste em organizar os liquidos de diferentes cores em frascos, de forma que cada frasco contenha apenas uma cor.\n");
    printf("\t=== COMO JOGAR ===\nObjetivo: Organize os liquidos ate que cada frasco contenha apenas UMA cor.");
    printf("\n\tRegras:\n");
    printf("1. Escolha o frasco de origem e o frasco de destino.\n");
    printf("2. Voce so pode despejar um liquido se o frasco de destino estiver VAZIO\n   ou se a cor do topo for IGUAL a cor que voce esta movendo.\n");
    printf("3. O frasco de destino precisa ter espaco disponivel.\n");
    printf("4. Vence quando todos os frascos com liquido estiverem completos e de uma so cor!\n");
    printf("\tBoa sorte!\n\n");
}

void sobreCriadora(){
    printf("\n\t!!Sobre a criadora!!\n\n");
    printf("Meu nome e Elizabeth Ferreira, tenho 19 anos e sou estudante de Ciencia da Computacao na UFOP.\n");
    printf("Este jogo foi desenvolvido como parte do meu Trabalho Final da disciplina de introducao a programacao.\n");
}

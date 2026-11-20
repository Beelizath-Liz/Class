#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define True 1

char menu();
void sobreJogo();
void sobreCriadora();
void limpar_buffer();

int main(){
    int dificuldade;
    char menuResult;
    while(True){ // Loop infinito para exibir o menu até que o usuário escolha sair
        menuResult = menu();
        printf("\nOpcao selecionada: %c\n", menuResult); // Exibe a opção selecionada pelo usuário, APAGAR

        switch(menuResult) { //Switch da seleção do menu;
            case '1':
                // Lógica para iniciar o jogo
                break;
            case '2':
                sobreJogo();
                continue;
            case '3':
                sobreCriadora();
                continue;
            case '4':
                printf("\n\nSaindo do programa...\n"); //Unica forma correta de sair do jogo, indo pro menu
                return 0;
            default:
                printf("Opcao invalida!\n");
                continue;
        }

        printf("Teste para ver se o jogo inicia corretamente\n"); //Teste testar a opção 1 do menu, APAGAR

        while(True){ //Loop infinito para o jogo, até que o usuário vença ou saia do jogo
            
            printf("\nSelecione a dificuldade: "); //Menu subistituto para jogo, APAGAR
            printf("\n1-Facil\t\t2-Medio\t\t3-Dificil\t4-Sair\n");
            scanf("%d", &dificuldade);
            if(dificuldade == 4){
                printf("Saindo do jogo...\n");
                break; // Sai do loop do jogo e volta para o menu
            } else {
                printf("Iniciando o jogo...\n");
                // Lógica do jogo aqui
            }
        }

    }
}

void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

char menu(){
    char opcao;
    printf("\t!!Bem vindo!!\n\n");
    printf("Selecione:\n");
    printf("1-Iniciar jogo\t\t2-Sobre o jogo\n3-Sobre a criadora\t4-Sair\n\n");
    printf("Digite a opcao desejada: ");
    scanf("%c", &opcao);
    limpar_buffer();
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
    printf("No momento eu estou estudando a linguagem C na faculdade, entao este projeto foi uma excelente oportunidade\npara aplicar os conceitos aprendidos nas aulas.\n");

}


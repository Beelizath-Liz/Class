#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define True 1
#define MAX_RANKING 10
#define ARQUIVO_RANKING "ranking.rnk"
#define MAX_NOME 51
#define CAPACIDADE_FRASCO 4
#define ARQUIVO_SAVE "save.potion"

typedef struct { //estrutura reduzida usada apenas para o ranking
    char nome[51];
    int nivel;
    int movimentos;
} Ranking;

typedef struct { //estrutura usada para criar o perfil, e salvar o estado do jogo
    char nome[MAX_NOME];
    int nivel;           /* 1 = Facil, 2 = Medio, 3 = Dificil */
    int numCores;        /* 3, 5 ou 7 */
    int numFrascos;      /* 5, 7 ou 9 */
    int movimentos;      /* Comeca em 0 */
    int jogoAtivo;       /* 1 se ha partida em andamento, 0 caso contrario */
    int **frascos;       /* Matriz alocada dinamicamente: [numFrascos][CAPACIDADE_FRASCO] */
} Partida;

char menu();
void sobreJogo();
void sobreCriadora();
void limpar_buffer();
void exibirRankingSeExistir();
void criarRankingTeste();
void criarperfil(Partida *jogador);
int continuarJogo(void);

int main(){
    char menuResult;
    Partida jogador;
    while(True){ // Loop infinito para exibir o menu até que o usuário escolha sair
        menuResult = menu();
        printf("\nOpcao selecionada: %c\n", menuResult); // Exibe a opção selecionada pelo usuário, APAGAR

        switch(menuResult) { //Switch da seleção do menu;
            case 'n':
            case 'N':
                //criar perfil de jogador e iniciar o jogo
                criarperfil(&jogador);
                break;
            case 'a':
            case 'A':
                sobreJogo(); //ajuda e reinicia o menu
                continue;
            case 'r':
            case 'R':
                //criarRankingTeste(); //Cria ranking de teste, APAGAR
                exibirRankingSeExistir(); //Visualizar ranking
                continue;
            case '3':
                sobreCriadora(); //ajustar botão
                continue;
            case 'c':
            case 'C':
                if (continuarJogo() == 0) { //se nao tiver jogo salvo
                    continue;
                }
                break;
            case 'x':
            case 'X':
                printf("\n\nSaindo do programa...\n"); //Unica forma correta de sair do jogo, indo pro menu
                return 0;
            default:
                printf("Opcao invalida!\n"); //qualquer opção nao no menu, apagar
                continue;
        }

        printf("Teste para ver se o jogo inicia corretamente\n"); //Teste testar a opção 1 do menu, APAGAR
        printf("Iniciando o jogo...\n");
        // Lógica do jogo aqui

    }
}

void limpar_buffer(void) { //limpar buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

char menu() { //texto do menu, que retorna a opção selecionada
    char opcao;
    printf("\t!!Bem vindo!!\n\n");
    printf("Selecione:\n");
    printf("N -Iniciar jogo\t\t\tC -Continuar jogo\nR -Visualizar ranking\t\tA -Sobre o jogo\n3 -Sobre a criadora\t\tX -Sair\n\n");
    printf("Digite a opcao desejada: ");
    scanf("%c", &opcao);
    limpar_buffer();
    return opcao;
}

void sobreJogo(){ //sobre o jogo, corrijir o guia do sobre, tem muitas informações incompletas
    printf("\n\t!!Sobre o jogo!!\n\n");
    printf("O jogo consiste em organizar os liquidos de diferentes cores em frascos, de forma que cada frasco contenha apenas uma cor.\n");
    printf("\t=== COMO JOGAR ===\nObjetivo: Organize os liquidos ate que cada frasco contenha apenas UMA cor.");
    printf("\n\tRegras:\n");
    printf("1. Escolha o frasco de origem e o frasco de destino.\n");
    printf("2. Voce so pode despejar um liquido se o frasco de destino estiver com um espaço vazio\n Só se pode mover UMA cor por vez\n");
    printf("3. O frasco de destino precisa ter espaco disponivel.\n");
    printf("4. Vence quando todos os frascos com liquido estiverem completos e com uma so cor cada!\n");
    printf("\tBoa sorte!\n\n");
}

void sobreCriadora(){ //texto de resumo sobre mim, tenho que implementar um botão pra isso
    printf("\n\t!!Sobre a criadora!!\n\n");
    printf("Meu nome e Elizabeth Ferreira, tenho 19 anos e sou estudante de Ciencia da Computacao na UFOP.\n");
    printf("Este jogo foi desenvolvido como parte do meu Trabalho Final da disciplina de introducao a programacao.\n");
    printf("No momento eu estou estudando a linguagem C na faculdade, entao este projeto foi uma excelente oportunidade\npara aplicar os conceitos aprendidos nas aulas.\n");

}

void exibirRankingSeExistir(void) { //botão do menu que procura arquivo de save de rankings
    FILE *fp = fopen(ARQUIVO_RANKING, "rb");
    if (fp == NULL) {
        printf("\nAinda nao ha registros no ranking.\n");
        return;
    }

    Ranking tab[MAX_RANKING];
    int qtd = (int)fread(tab, sizeof(Ranking), MAX_RANKING, fp);
    fclose(fp);

    if (qtd <= 0) {
        printf("\nAinda nao ha registros no ranking.\n");
        return;
    }

    printf("\n=== RANKING ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. %s | Nivel: %d | Movimentos: %d\n",
               i + 1, tab[i].nome, tab[i].nivel, tab[i].movimentos);
    }
}

/*void criarRankingTeste(void) { cria um ranking de teste, isso DEVE ser apagado depois
    FILE *fp = fopen(ARQUIVO_RANKING, "wb");
    if (fp == NULL) {
        printf("Erro ao criar arquivo de teste.\n");
        return;
    }

    Ranking teste[2] = {
        {"Elizabeth", 3, 12},
        {"Ana", 1, 15}
    };

    fwrite(teste, sizeof(Ranking), 2, fp);
    fclose(fp);
}
*/

void criarperfil(Partida *jogador) { //cria perfil
    int valido = 0;

    printf("\nDigite o nome do jogador: "); //nome do jogador
    scanf(" %50[^\n]", jogador->nome);
    limpar_buffer();

    while (!valido) {
        printf("\nSelecione a dificuldade:\n");  //dificuldade
        printf("1 - Facil\n2 - Medio\n3 - Dificil\n");
        printf("Opcao: ");
        scanf("%d", &jogador->nivel);
        limpar_buffer();

        if (jogador->nivel >= 1 && jogador->nivel <= 3) {
            valido = 1;
        } else {
            printf("Opcao invalida! Digite 1, 2 ou 3.\n");
        }
    }

    switch (jogador->nivel) {  //com a dificuldade ja pega e separa os outros dados relevantes
        case 1:
            jogador->numCores = 3;
            jogador->numFrascos = 5;
            break;
        case 2:
            jogador->numCores = 5;
            jogador->numFrascos = 7;
            break;
        case 3:
            jogador->numCores = 7;
            jogador->numFrascos = 9;
            break;
    }

    jogador->movimentos = 0; //acabou de criar, entao movimentos 0
    jogador->jogoAtivo = 1; //nao sei pra que isso
    jogador->frascos = NULL; //nao sei tbm
}

int continuarJogo(void) { //função que continua jogo, no momento ela nao faz nada se achar o save
    FILE *fp = fopen(ARQUIVO_SAVE, "rb");
    if (fp == NULL) {
        printf("\nNao ha jogos salvos no momento.\n");
        return 0;
    }

    fclose(fp);
    printf("\nArquivo de save encontrado! (Carregamento ainda sera implementado)\n");
    return 1;
}

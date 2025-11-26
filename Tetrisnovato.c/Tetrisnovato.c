#include <stdio.h>
#include <stdlib.h>

/* Struct que representa uma peça do Tetris Stack */
struct Peca {
    char nome;   /* tipo da peça ('I', 'O', 'T', 'L') */
    int id;      /* identificador único */
};

/* Tamanho máximo da fila */
#define TAM 10

/* Variáveis da fila circular */
struct Peca fila[TAM];
int inicio = 0;
int fim = 0;
int quantidade = 0;

/* Letras usadas para gerar peças */
char tipos[4] = {'I', 'O', 'T', 'L'};
int proximoID = 0;

/* Função que gera automaticamente uma nova peça */
struct Peca gerarPeca() {
    struct Peca nova;
    nova.nome = tipos[proximoID % 4];
    nova.id = proximoID;
    proximoID++;
    return nova;
}

/* Insere peça no final da fila (enqueue) */
void enqueue() {
    if (quantidade == TAM) {
        printf("Fila cheia. Nao e possivel adicionar nova peca.\n");
        return;
    }

    fila[fim] = gerarPeca();
    fim = (fim + 1) % TAM;
    quantidade++;
}

/* Remove peça da frente da fila (dequeue) */
void dequeue() {
    if (quantidade == 0) {
        printf("Fila vazia. Nao ha peca para jogar.\n");
        return;
    }

    inicio = (inicio + 1) % TAM;
    quantidade--;
}

/* Exibe o estado atual da fila */
void exibirFila() {
    printf("\nFila de pecas:\n");

    if (quantidade == 0) {
        printf("[vazia]\n");
        return;
    }

    int i = inicio;
    for (int c = 0; c < quantidade; c++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAM;
    }

    printf("\n");
}

/* Programa principal */
int main() {
    int opcao;

    /* Inicializa a fila com 5 peças */
    for (int i = 0; i < 5; i++) {
        enqueue();
    }

    /* Loop do menu */
    do {
        exibirFila();

        printf("\nOpcoes:\n");
        printf("1 - Jogar peca (dequeue)\n");
        printf("2 - Inserir nova peca (enqueue)\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            dequeue();
        } else if (opcao == 2) {
            enqueue();
        }

    } while (opcao != 0);

    return 0;
}

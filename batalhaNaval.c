#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * direcaoLinha;
        int novaColuna = coluna + i * direcaoColuna;

        if (novaLinha < 0 || novaLinha >= TAM || novaColuna < 0 || novaColuna >= TAM)
            return 0;
        if (tabuleiro[novaLinha][novaColuna] != AGUA)
            return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i * direcaoLinha][coluna + i * direcaoColuna] = NAVIO;
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("===== TABULEIRO BATALHA NAVAL =====\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Navio horizontal
    if (podePosicionar(tabuleiro, 0, 0, 0, 1))
        posicionarNavio(tabuleiro, 0, 0, 0, 1);

    // Navio vertical
    if (podePosicionar(tabuleiro, 2, 5, 1, 0))
        posicionarNavio(tabuleiro, 2, 5, 1, 0);

    // Navio diagonal (principal)
    if (podePosicionar(tabuleiro, 5, 5, 1, 1))
        posicionarNavio(tabuleiro, 5, 5, 1, 1);

    // Navio diagonal (secundária)
    if (podePosicionar(tabuleiro, 2, 7, 1, -1))
        posicionarNavio(tabuleiro, 2, 7, 1, -1);

    exibirTabuleiro(tabuleiro);

    return 0;
}


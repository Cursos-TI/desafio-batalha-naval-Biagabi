#include <stdio.h>

#define TAM 10          // Tamanho do tabuleiro
#define TAM_NAVIO 3     // Tamanho de cada navio
#define NAVIO 3         // Valor para representar navio
#define AGUA 0          // Valor para representar água

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Define os dois navios com valor 3
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // Coordenadas iniciais dos navios
    int linhaHorizontal = 1;
    int colunaHorizontal = 2;

    int linhaVertical = 4;
    int colunaVertical = 6;

    // Posiciona o navio horizontal na matriz
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
    }

    // Posiciona o navio vertical na matriz
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
    }

    // Imprime o tabuleiro
    printf("===== TABULEIRO BATALHA NAVAL =====\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

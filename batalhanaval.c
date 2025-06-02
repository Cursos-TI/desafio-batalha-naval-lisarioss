#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração e inicialização da matriz do tabuleiro com água (valor 0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Navios representados por vetores de tamanho 3 com valor 3 (representando parte do navio)
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas de início do navio horizontal (linha, coluna)
    int linha_h = 2;
    int coluna_h = 4;

    // Coordenadas de início do navio vertical (linha, coluna)
    int linha_v = 5;
    int coluna_v = 1;

    // Verifica se os navios cabem no tabuleiro e não se sobrepõem
    int valido_horizontal = (coluna_h + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);
    int valido_vertical = (linha_v + TAMANHO_NAVIO <= TAMANHO_TABULEIRO);

    // Checagem de sobreposição (simples)
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (linha_v + i == linha_h && coluna_v == coluna_h + i) {
            sobreposicao = 1;
            break;
        }
    }

    if (valido_horizontal && valido_vertical && !sobreposicao) {
        // Posiciona navio horizontal na matriz
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
        }

        // Posiciona navio vertical na matriz
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
        }

        // Impressão do tabuleiro
        printf("Tabuleiro Batalha Naval:\n");
        for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
            for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("Erro ao posicionar os navios:\n");
        if (!valido_horizontal) printf(" - O navio horizontal ultrapassa o limite do tabuleiro.\n");
        if (!valido_vertical) printf(" - O navio vertical ultrapassa o limite do tabuleiro.\n");
        if (sobreposicao) printf(" - Os navios estão sobrepostos.\n");
    }

    return 0;
}
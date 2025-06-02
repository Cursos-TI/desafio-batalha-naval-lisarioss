#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3

// Função para verificar se uma posição está ocupada
int esta_ocupado(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return tabuleiro[linha][coluna] == NAVIO;
}

// Função para verificar se o navio cabe e não sobrepõe outro
int pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        // Direção: 0 = horizontal, 1 = vertical
        // Diagonal: 1 = diagonal principal, -1 = diagonal secundária
        if (diagonal == 0) {
            if (direcao == 0) c += i;         // horizontal
            else if (direcao == 1) l += i;    // vertical
        } else if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == -1) {
            l += i;
            c -= i;
        }

        // Verifica limites e sobreposição
        if (l < 0 || l >= TAM || c < 0 || c >= TAM || esta_ocupado(tabuleiro, l, c)) {
            return 0; // inválido
        }
    }
    return 1; // válido
}

// Função para posicionar o navio
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 0) {
            if (direcao == 0) c += i;       // horizontal
            else if (direcao == 1) l += i;  // vertical
        } else if (diagonal == 1) {
            l += i;
            c += i;
        } else if (diagonal == -1) {
            l += i;
            c -= i;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // inicializa com água (0)

    // Definindo posições dos navios
    // Navio 1: horizontal
    int l1 = 1, c1 = 2;
    if (pode_posicionar(tabuleiro, l1, c1, 0, 0)) {
        posicionar_navio(tabuleiro, l1, c1, 0, 0);
    }

    // Navio 2: vertical
    int l2 = 5, c2 = 6;
    if (pode_posicionar(tabuleiro, l2, c2, 1, 0)) {
        posicionar_navio(tabuleiro, l2, c2, 1, 0);
    }

    // Navio 3: diagonal principal (↘)
    int l3 = 0, c3 = 0;
    if (pode_posicionar(tabuleiro, l3, c3, 0, 1)) {
        posicionar_navio(tabuleiro, l3, c3, 0, 1);
    }

    // Navio 4: diagonal secundária (↙)
    int l4 = 0, c4 = 9;
    if (pode_posicionar(tabuleiro, l4, c4, 0, -1)) {
        posicionar_navio(tabuleiro, l4, c4, 0, -1);
    }

    exibir_tabuleiro(tabuleiro);

    return 0;
}
#include <stdio.h>
#include <string.h>

#define TAM 10
#define HAB 5  // Tamanho fixo das matrizes de habilidade (5x5)

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("=== TABULEIRO ===\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Cria matriz de habilidade CONE (ponta para baixo)
void criarCone(int cone[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            cone[i][j] = (j >= HAB/2 - i && j <= HAB/2 + i) ? 1 : 0;
        }
    }
}

// Cria matriz de habilidade CRUZ
void criarCruz(int cruz[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            cruz[i][j] = (i == HAB/2 || j == HAB/2) ? 1 : 0;
        }
    }
}

// Cria matriz de habilidade OCTAEDRO (losango)
void criarOctaedro(int oct[HAB][HAB]) {
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int dist = abs(HAB/2 - i) + abs(HAB/2 - j);
            oct[i][j] = (dist <= HAB/2) ? 1 : 0;
        }
    }
}

// Aplica a habilidade no tabuleiro a partir do ponto central
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HAB][HAB], int origemX, int origemY) {
    int offset = HAB / 2;

    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            int x = origemX - offset + i;
            int y = origemY - offset + j;

            // Verifica se está dentro dos limites do tabuleiro
            if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[x][y] != 3) {
                    tabuleiro[x][y] = 5; // Marca área afetada pela habilidade (sem sobrescrever navio)
                }
            }
        }
    }
}

// Exemplo de posicionamento de navios para visualização
void posicionarNaviosExemplo(int tabuleiro[TAM][TAM]) {
    // Navio horizontal
    tabuleiro[1][1] = 3;
    tabuleiro[1][2] = 3;
    tabuleiro[1][3] = 3;

    // Navio vertical
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;
    tabuleiro[7][5] = 3;
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[HAB][HAB], cruz[HAB][HAB], octaedro[HAB][HAB];

    inicializarTabuleiro(tabuleiro);
    posicionarNaviosExemplo(tabuleiro);

    // Cria matrizes de habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Cone no topo esquerdo
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Cruz no centro
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Octaedro no canto inferior direito

    imprimirTabuleiro(tabuleiro);

    return 0;
}
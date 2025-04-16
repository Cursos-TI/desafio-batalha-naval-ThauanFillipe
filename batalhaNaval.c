#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    int tamanho_navio = 3;
    if (direcao == 0 && coluna + tamanho_navio <= TAMANHO_TABULEIRO) { // Horizontal
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 1 && linha + tamanho_navio <= TAMANHO_TABULEIRO) { // Vertical
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = -i; j <= i; j++) {
            int x = linha + i;
            int y = coluna + j;
            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO) {
                tabuleiro[x][y] = AREA_AFETADA;
            }
        }
    }
}

void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = -TAMANHO_HABILIDADE / 2; i <= TAMANHO_HABILIDADE / 2; i++) {
        int x = linha + i;
        int y = coluna + i;
        if (x >= 0 && x < TAMANHO_TABULEIRO) {
            tabuleiro[x][coluna] = AREA_AFETADA;
        }
        if (y >= 0 && y < TAMANHO_TABULEIRO) {
            tabuleiro[linha][y] = AREA_AFETADA;
        }
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = -i; j <= i; j++) {
            int x = linha + i;
            int y1 = coluna + j;
            int y2 = coluna - j;
            if (x < TAMANHO_TABULEIRO && y1 >= 0 && y1 < TAMANHO_TABULEIRO) {
                tabuleiro[x][y1] = AREA_AFETADA;
            }
            if (x < TAMANHO_TABULEIRO && y2 >= 0 && y2 < TAMANHO_TABULEIRO) {
                tabuleiro[x][y2] = AREA_AFETADA;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    posicionarNavio(tabuleiro, 2, 4, 0);
    posicionarNavio(tabuleiro, 6, 1, 1);

    // Aplicar habilidades especiais
    aplicarHabilidadeCone(tabuleiro, 3, 3);
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);

    // Exibir tabuleiro com habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
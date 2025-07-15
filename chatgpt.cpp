#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Função para acessar a matriz unidimensional usando índices 2D
int index(int x, int y, int tamanho) {
    return y * tamanho + x;  // Calcula o índice de uma matriz 2D armazenada em uma unidimensional
}

// Função Diamond - Calcula a média de 4 pontos e aplica a rugosidade
void Diamond(int matriz[], int tamanho, double rug) {
    int step = tamanho - 1;  // O passo inicial é o tamanho da matriz menos 1

    // Inicializa os pontos nos 4 cantos
    matriz[index(0, 0, tamanho)] = 10;   // Canto superior esquerdo
    matriz[index(0, step, tamanho)] = 10; // Canto superior direito
    matriz[index(step, 0, tamanho)] = 10; // Canto inferior esquerdo
    matriz[index(step, step, tamanho)] = 10; // Canto inferior direito

    // Função recursiva Diamond-Square
    while (step > 1) {
        int halfStep = step / 2;

        // Diamond Step
        for (int y = halfStep; y < tamanho; y += step) {
            for (int x = halfStep; x < tamanho; x += step) {
                // Calcular a média dos 4 pontos adjacentes
                double avg = (matriz[index(x - halfStep, y - halfStep, tamanho)] +
                              matriz[index(x + halfStep, y - halfStep, tamanho)] +
                              matriz[index(x - halfStep, y + halfStep, tamanho)] +
                              matriz[index(x + halfStep, y + halfStep, tamanho)]) / 4.0;

                // Aplicar a perturbação de rugosidade
                matriz[index(x, y, tamanho)] = avg + ((rand() / (double)RAND_MAX) * 2.0 - 1.0) * rug;
            }
        }

        // Square Step
        for (int y = 0; y < tamanho; y += halfStep) {
            for (int x = (y + halfStep) % step; x < tamanho; x += step) {
                // Calcular a média dos pontos adjacentes ao lado
                double avg = (matriz[index((x - halfStep + tamanho) % tamanho, y, tamanho)] +
                              matriz[index((x + halfStep) % tamanho, y, tamanho)] +
                              matriz[index(x, (y + halfStep) % tamanho, tamanho)] +
                              matriz[index(x, (y - halfStep + tamanho) % tamanho, tamanho)]) / 4.0;

                // Aplicar a perturbação de rugosidade
                matriz[index(x, y, tamanho)] = avg + ((rand() / (double)RAND_MAX) * 2.0 - 1.0) * rug;
            }
        }

        // Reduz o passo (step) pela metade a cada iteração
        step = halfStep;

        // Diminui a rugosidade a cada iteração
        rug *= 0.5;
    }
}

// Função para exibir a matriz
void printMatriz(int matriz[], int tamanho) {
    for (int y = 0; y < tamanho; ++y) {
        for (int x = 0; x < tamanho; ++x) {
            cout << matriz[index(x, y, tamanho)] << " ";
        }
        cout << endl;
    }
}

class Terreno {
public:
    void Gerar_terreno(int n, double rug);
};

void Terreno::Gerar_terreno(int n, double rug) {
    // Determina o tamanho da matriz
    int tamanho = pow(2, n) + 1;
    int* point_tam = &tamanho;

    // Cria a matriz (de tamanho tamanho * tamanho)
    int matriz[tamanho * tamanho];
    int direito_sup, direito_inf, esquerdo_sup, esquerdo_inf;
    int i = 0;
}

int main() {
    srand(time(0));

    // Defina o tamanho da matriz (deve ser 2^n + 1)
    int n = 3; // Exemplo: n = 3 => tamanho = 2^3 + 1 = 9
    int tamanho = pow(2, n) + 1; // Cálculo do tamanho da matriz
    int* matriz = new int[tamanho * tamanho]; // Alocação dinâmica da matriz

    // Inicialize a matriz com zeros
    for (int i = 0; i < tamanho * tamanho; ++i) {
        matriz[i] = 0;
    }

    // Chama a função Diamond-Square
    double rug = 0.5; // Define o valor de rugosidade
    Diamond(matriz, tamanho, rug);

    // Exibe a matriz gerada
    printMatriz(matriz, tamanho);

    // Libera a memória alocada
    delete[] matriz;

    return 0;
}

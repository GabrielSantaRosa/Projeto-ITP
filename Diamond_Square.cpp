#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int Array_uni(int lin, int col, int tamanho){
    return lin * tamanho + col;
}

void Diamond(int matriz[],const int tamanho, int des, double rug){

    int metade_des = des/2;
    for(int i = metade_des; i < tamanho-1; i += des){
        for (int j = metade_des; j < tamanho-1; j += des)
        {
            int soma =
                matriz[Array_uni(i - metade_des, j - metade_des, tamanho)] +
                matriz[Array_uni(i - metade_des, j + metade_des, tamanho)] +
                matriz[Array_uni(i + metade_des, j - metade_des, tamanho)] +
                matriz[Array_uni(i + metade_des, j + metade_des, tamanho)];

            matriz[Array_uni(i, j, tamanho)] = (soma / 4) + (rand()%61-30)*rug;


        }
    }
}

void Square(int matriz[], const int tamanho, int des, double rug){
    int metade_des = des/2;
    int soma = 0;
    for(int i = 0; i < tamanho; i += metade_des){

        for (int j = (i+metade_des)%des; j < tamanho; j += des)
        {
            int count = 0;
            int soma = 0;
            // Vizinho esquerdo (se existir)
            if (j - metade_des >= 0) {
                soma += matriz[Array_uni(i, j - metade_des, tamanho)];
                count++;
            }
            // Vizinho direito (se existir)
            if (j + metade_des < tamanho) {
                soma += matriz[Array_uni(i, j + metade_des, tamanho)];
                count++;
            }
            // Vizinho superior (se existir)
            if (i - metade_des >= 0) {
                soma += matriz[Array_uni(i - metade_des, j, tamanho)];
                count++;
            }
            // Vizinho inferior (se existir)
            if (i + metade_des < tamanho) {
                soma += matriz[Array_uni(i + metade_des, j, tamanho)];
                count++;
            }
            // Só calcula a média se houver vizinhos válidos
            if (count > 0) {
                matriz[Array_uni(i, j, tamanho)] = soma / count + (rand()%61-30)*rug;
            }
        }
    }
}

void Diamond_Square(int dimensao, int matriz[], int tamanho, double rug)
{
    srand(time(0));
    matriz[0] = rand() % 101;
    matriz[tamanho-1] = rand() % 101;
    matriz[tamanho*tamanho - tamanho] = rand() % 101;
    matriz[tamanho*tamanho - 1] = rand() % 101;

    while(dimensao > 1){
        Diamond(matriz,tamanho,dimensao, rug);
        Square(matriz,tamanho, dimensao, rug);
        dimensao /= 2;
        rug /= pow(2,(double)(rand()) / RAND_MAX);
    }
}

void printMatriz(int matriz[], int tamanho) {
    for (int y = 0; y < tamanho; ++y) {
        for (int x = 0; x < tamanho; ++x) {
            cout << matriz[Array_uni(y, x, tamanho)] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


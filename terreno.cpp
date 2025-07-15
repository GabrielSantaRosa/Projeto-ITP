#include "Terreno.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
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
            soma *= rug/4;
          
            matriz[Array_uni(i, j, tamanho)] = soma;
            cout << "mudei o ponto " << i << " " << j << " para o número " << soma << endl;
        }
        
    }

}

void Square(int matriz[], const int tamanho, int des, double rug){


}


void Terreno::Gerar_terreno(int n, double rug){
    int tamanho = pow(2,n) + 1;
    int* point_tam = &tamanho;
    int matriz[tamanho*tamanho];
    int direito_sup, direito_inf, esquerdo_sup, esquerdo_inf;
    int i = 0;

}

void printMatriz(int matriz[], int tamanho) {
    for (int y = 0; y < tamanho; ++y) {
        for (int x = 0; x < tamanho; ++x) {
            cout << matriz[Array_uni(x, y, tamanho)] << " ";
        }
        cout << endl;
    }
}

int main(){
    int matriz[25];
    for(int i = 0; 25 > i; i++)
    {
        matriz[i] = 0;
    }
    int tam = 5;
    matriz[0] = 10;
    matriz[2] = 10;
    matriz[4] = 10;
    matriz[10] = 10;
    matriz[12] = 10;
    matriz[14] = 10;
    matriz[20] = 10;
    matriz[22] = 10;
    matriz[24] = 10;
    double rug = 4.0;
    int des = tam;

 
    Diamond(matriz,tam,2, rug);
    printMatriz(matriz,5);

    return 0;
}


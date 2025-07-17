#include "Terreno.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

Terreno::Terreno(int l, int a, int altitude[])
{
    largura = l;
    altura = a;

    for(int i = 0; MAX_SIZE > i; i++)
    {
        altitudes[i] = altitude[i];
    }
}

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
          
            matriz[Array_uni(i, j, tamanho)] = (soma / 4) * rug;
            
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
                matriz[Array_uni(i, j, tamanho)] = soma / count;
            }
        }
    }
}

void printMatriz(int matriz[], int tamanho) {
    for (int y = 0; y < tamanho; ++y) {
        for (int x = 0; x < tamanho; ++x) {
            cout << matriz[Array_uni(x, y, tamanho)] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Terreno::Gerar_terreno(int n, double rug){
    int tamanho = pow(2,n) + 1;
    int matriz[tamanho*tamanho];
    int des = tamanho - 1;
    srand(time(0));
    matriz[0] = rand() % 100;
    matriz[tamanho-1] = rand() % 100;
    matriz[tamanho*tamanho - tamanho] = rand() % 100; 
    matriz[tamanho*tamanho - 1] = rand() % 100;

    while(des > 1){
        Diamond(matriz,tamanho,des, rug);
        Square(matriz,tamanho, des, rug);
        des /= 2;
        //rug /= 2;
    }
    printMatriz(matriz,tamanho); 
}

int main(){

    int matriz[81];
    Terreno meuTerreno(9 ,9 ,matriz);
    
    // Gera um terreno com n=3 (tamanho 9x9) e rugosidade 0.5
    meuTerreno.Gerar_terreno(3, 0.5);
    
    // Gera outro terreno com n=2 (tamanho 5x5) e rugosidade 0.3
    //meuTerreno.Gerar_terreno(2, 0.3);

    return 0;
}


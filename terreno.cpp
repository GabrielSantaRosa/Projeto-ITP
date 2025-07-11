#include "Terreno.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void Diamond(int matriz[],const int tamanho, int* point_tam, double rug, int i){
    int lin, col;
    lin = *point_tam;
    col = *point_tam;
    cout << matriz[i] << " ";
    cout << lin-1 <<" ";
    cout << lin*tamanho+col+1 << " ";
    cout << lin*tamanho-1 << " ";
    int soma = matriz[i] + matriz[lin+i] + matriz[lin*tamanho+col+i] + matriz[lin*tamanho+i];
    int pos = i + (lin+i) + (lin*tamanho+i) + (lin * tamanho + col+i) + (lin*tamanho+i);
    cout << pos << endl;
    soma *= rug/4;

    *point_tam = ( *point_tam-1 ) /2;

    matriz[*point_tam*tamanho + *point_tam] = soma;
    cout << soma << endl;
     

}

void Square(int matriz[]){

}


void Terreno::Gerar_terreno(int n, double rug){
    int tamanho = pow(2,n) + 1;
    int* point_tam = &tamanho;
    int matriz[tamanho*tamanho];
    int direito_sup, direito_inf, esquerdo_sup, esquerdo_inf;
    int i = 0;

}

int main(){
    int matriz[25];
    int tam = 5;
    int* point_tam = &tam;
    double rug = 0.5; 
    int i = 0;
    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            matriz[lin*5+col] = 0;
        }
    }
    matriz[0] = 10;
    matriz[4] = 10;
    matriz[20] = 10;
    matriz[24] = 10;

    Diamond(matriz,25, point_tam,rug, i);

    int controle = 0;
    for(int ix = 0; 25 > ix; ix++){
        cout << matriz[ix] << " ";
        controle++;
        if(controle % 5 == 0) cout << endl;
    }

    return 0;
}
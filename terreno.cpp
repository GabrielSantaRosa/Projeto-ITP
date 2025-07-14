#include "Terreno.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void Diamond(int matriz[],const int tamanho, int* point_tam, double rug, int i){
    int lin, col;
    lin = *point_tam;
    col = *point_tam;
    i *= tamanho;
    //cout << matriz[i] << " ";
    //cout << matriz[lin+i] <<" ";
    //cout << lin*tamanho+col+i << " ";
    //cout << matriz[lin*tamanho+i] << " ";
    int soma = matriz[i] + matriz[lin] + matriz[lin*tamanho+col] + matriz[lin*tamanho];
    int pos = i + (lin) + (lin*tamanho) + (lin * tamanho + col) + (lin*tamanho);
    //cout << pos << endl;
    soma *= rug/4;

    *point_tam = ( *point_tam ) /2;

    matriz[*point_tam*tamanho + *point_tam] = soma;
    //cout << soma << endl;
     

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
    int tam = 4;
    int* point_tam = &tam;
    double rug = 0.5; 
    int i = 0;
    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            matriz[lin*5+col] = 0;
        }
    }
    matriz[0] = 100;
    matriz[4] = 100;
    matriz[20] = 100;
    matriz[24] = 100;

    Diamond(matriz,5, point_tam,rug, i);

    

    matriz[10] = 50;
    matriz[2] = 50;
    matriz[14] = 50;
    matriz[22] = 50;
    
    
    int controle = 0;
    for(int ix = 0; 25 > ix; ix++){
        cout << matriz[ix] << " ";
        controle++;
        if(controle % 5 == 0) cout << endl;
    }

    while(i < 5){
        cout << endl;
        Diamond(matriz,5, point_tam,rug, i);
        i++;
        controle = 0;
        for(int ix = 0; 25 > ix; ix++){
        cout << matriz[ix] << " ";
        controle++;
        if(controle % 5 == 0) cout << endl;
    }
    
    }





    return 0;
}
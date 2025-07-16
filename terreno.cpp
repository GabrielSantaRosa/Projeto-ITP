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
            soma /= 4;
          
            matriz[Array_uni(i, j, tamanho)] = soma;
            
        }
        
    }

}


void Square(int matriz[], const int tamanho, int des, double rug){
    int metade_des = des/2;
    int soma = 0;
    for(int i = 0; i < tamanho; i += metade_des){
       
        for (int j = (i+metade_des)%des; j < tamanho; j += des)
        {
            
            soma = matriz[Array_uni(i, (j-metade_des+tamanho)%tamanho, tamanho)] +
                matriz[Array_uni(i, (j+metade_des)%tamanho, tamanho)] +
                matriz[Array_uni((i+metade_des)%tamanho, j, tamanho)] +
                matriz[Array_uni((i-metade_des+tamanho)%tamanho, j, tamanho)];
                soma /= 4;
               
                matriz[Array_uni(i,j,tamanho)] = soma;
        }

    }
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
    cout << endl;
}





int main(){
    int matriz[25];
    for(int i = 0; 25 > i; i++)
    {
        matriz[i] = 0;
    }
    int des = 5;
     int tam = 5;
    matriz[0] = 100;
   
    matriz[4] = 100;
    
    
    
    matriz[20] = 100;
   
    matriz[24] = 100;
     double rug = 0.4;
    
    while(des > 1){
        Diamond(matriz,tam,des, rug);
        Square(matriz, tam, des, rug);
        printMatriz(matriz,5);
    des /= 2;
    } 
        
        printMatriz(matriz,5);
   
   

 
   

    return 0;
}


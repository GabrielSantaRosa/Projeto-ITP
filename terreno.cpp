#include "Terreno.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int Array_uni(int lin, int col, int tamanho){
    return lin * tamanho + col;
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

Terreno::Terreno(int l, int a)
{
    largura = l;
    altura = a;

    for(int i = 0; MAX_SIZE > i; i++)
    {
        altitudes[i] = 0;

    }
}
Terreno::~Terreno()
{
    delete altitudes;
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

void Terreno::Gerar_terreno(int n, double rug){
    int tamanho = pow(2,n) + 1;
    int matriz[tamanho*tamanho];
    int des = tamanho - 1;
    srand(time(0));
    matriz[0] = rand() % 101;
    matriz[tamanho-1] = rand() % 101;
    matriz[tamanho*tamanho - tamanho] = rand() % 101; 
    matriz[tamanho*tamanho - 1] = rand() % 101;

    while(des > 1){
        Diamond(matriz,tamanho,des, rug);
        Square(matriz,tamanho, des, rug);
        des /= 2;
        rug /= pow(2,(double)(rand()) / RAND_MAX);
    }

    altura = largura = tamanho;
    for(int i = 0; i < tamanho*tamanho; i++){
        altitudes[i] = matriz[i];
    }
    printMatriz(matriz,tamanho); 
}

int Terreno::Consulta_alt(int lin, int col){
    return altitudes[Array_uni(lin,col,largura)];
}

int Terreno::Consulta_lin(){
    return largura;
}

int Terreno::Consulta_col(){
    return altura;
}

void Terreno::Salvar_terreno(std::string arquivo){
    ofstream canal(arquivo);
    canal << largura << endl;
    canal << altura << endl;
    for(int i = 0; i < largura*altura; i++){
        canal << altitudes[i] << " ";
    }
}

void Terreno::Ler_arquivo(std::string arquivo){
    fstream canal(arquivo);
    canal >> largura;
    canal >> altura;
    for(int i = 0; i < largura*altura; i++){
        canal >> altitudes[i];
    }
    printMatriz(altitudes,largura); 
}

int main(){

    
    Terreno meuTerreno(9 ,9);
    
    // Gera um terreno com n=3 (tamanho 9x9) e rugosidade 0.5
    meuTerreno.Gerar_terreno(3, 1.0);
    std::string arquivo = "teste.txt";
    //meuTerreno.Ler_arquivo(arquivo);
    cout << meuTerreno.Consulta_alt(0,2) << endl;
    meuTerreno.Salvar_terreno(arquivo);

    // Gera outro terreno com n=2 (tamanho 5x5) e rugosidade 0.3
    //meuTerreno.Gerar_terreno(2, 0.3);
    

    return 0;

}


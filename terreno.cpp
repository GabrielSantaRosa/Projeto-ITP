#include "Terreno.h"
#include "Diamond_Square.cpp"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

Terreno::Terreno(int l, int a)
{
    largura = l;
    altura = a;

    altitudes = new int[MAX_SIZE];
    for(int i = 0; MAX_SIZE > i; i++)
    {
        altitudes[i] = 0;
    }
}
Terreno::~Terreno()
{
    delete[] altitudes;
}

void Terreno::Gerar_terreno(int n, double rug){
    int tamanho = pow(2,n) + 1;
    int matriz[tamanho*tamanho];
    int des = tamanho - 1;

    altura = largura = tamanho;

    Diamond_Square(des,matriz,tamanho,rug);

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
    cout << meuTerreno.Consulta_alt(0,1) << endl;
    meuTerreno.Salvar_terreno(arquivo);
    meuTerreno.~Terreno();
    // Gera outro terreno com n=2 (tamanho 5x5) e rugosidade 0.3
    //meuTerreno.Gerar_terreno(2, 0.3);
    cout << meuTerreno.Consulta_alt(0,2) << endl;

    return 0;
}


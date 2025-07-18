#include "Arquivos_.h\Terreno.h"
#include "Diamond_Square.cpp"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

Terreno::Terreno(int l, int a)
{
    largura = l;
    altura = a;

    altitudes = new int[largura*altura];
    for(int i = 0; largura*altura > i; i++)
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
    for(int i = 0; i < largura; i++){
        for(int j = 0; j < altura; j++)
        canal << altitudes[Array_uni(i,j,altura)] << " ";
        canal << endl;
    }
    
}

void Terreno::Ler_arquivo(std::string arquivo){
    fstream canal(arquivo);
    canal >> largura;
    canal >> altura;
    for(int i = 0; i < largura*altura; i++){
        canal >> altitudes[i];
    }
}
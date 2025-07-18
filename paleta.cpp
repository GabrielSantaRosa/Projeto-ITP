#include "Arquivos_.h\Paleta.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool operator==(const Cor& cor_1, const Cor& cor_2){
    return (cor_1.r == cor_2.r && cor_1.g == cor_2.g && cor_1.b == cor_2.b);
}

Paleta::Paleta(){

}

Paleta::Paleta(int q, Cor c[], int a[]){
    quantidade = q;
    for(int i = 0; i < q; i++){
        altura[i] = a[i];
        cores[i] = c[i];
    }
}

int Paleta::Consulta_quantidade(){
    return quantidade;
}

Cor Paleta::Consulta_cor(int a){
    Cor cor_final = cores[0];
    for(int i = 0; i < quantidade - 1; i++){
        if(a <= altura[i] && a <= altura[i+1]){
            return cores[i];
        }
    }
    return cores[quantidade-1];
}

void Paleta::Ler_arquivo(string arquivo){
    fstream canal(arquivo);
    canal >> quantidade;
    for(int i = 0; i < quantidade; i++){
        canal >> altura[i];
        canal >> cores[i].r >> cores[i].g >> cores[i].b;
    }
}
#include "cor_e_paleta.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

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
        if(a >= altura[i] && a <= altura[i+1]){
            cor_final = cores[i];
        }
        else{
            cor_final = cores[i+1];
        }
    }
    return cor_final;
}

void Paleta::Ler_arquivo(string arquivo){
    fstream canal(arquivo);
    canal >> quantidade;
    for(int i = 0; i < quantidade; i++){
        canal >> altura[i];
        Cor temporaria;
        int unsigned r, g, b;
        canal >> r >> g >> b;
        temporaria = {r, g, b};
        cores[i] = temporaria;
    }

}

bool operator==(const Cor& lhs, const Cor& rhs)
    {
    return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b);
    }




int main(){
    Paleta x;
    string teste = "teste.txt";
    x.Ler_arquivo(teste);
    Cor vermelho = {255, 0 ,0 };
    Cor preto = {0, 0, 0};
    Cor array_cores[2] = {vermelho, preto};
    int array_alturas[2] = {10, 20};
    Paleta y = {2, array_cores, array_alturas};
    y.Consulta_cor(15);
    Cor verde = {0, 255, 0};

    
    bool teste_1 = (verde == x.Consulta_cor(25));
    cout << teste_1 << endl;


    return 0;
}
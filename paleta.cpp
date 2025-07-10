#include "Paleta.h"
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
        canal >> cores[i].r >> cores[i].g >> cores[i].b;
    }

}


int main(){
    Cor vermelho = {255, 0 ,0 };
    Cor verde = {0, 255, 0};
    Cor azul = {0, 0, 255};
    Cor preto = {0, 0, 0};
    Paleta x;
    string teste = "teste.txt";
    x.Ler_arquivo(teste);
    
    Cor array_cores[2] = {vermelho, preto};
    int array_alturas[2] = {10, 20};
    Paleta y = {2, array_cores, array_alturas};
    //y.Consulta_cor(15);
    

    
    bool teste_1 = (azul == x.Consulta_cor(25));
    //if(azul == x.Consulta_cor(25))

    cout << teste_1 << endl;


    return 0;
}